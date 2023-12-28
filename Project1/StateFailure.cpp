#include"StateFailure.hpp"
#include"AssetManager.hpp"
#include"StateMenu.hpp"
#include<ctime>

int StateFailure::SelectFailureCG = 0;
StateFailure::StateFailure(StateManager& manager) :stateManager(manager)
{
	srand(unsigned(time));
	isUnlock = false;
	//获取素材管理器的单例
	AssetManager& assetManager = AssetManager::getInstance();
	//实体管理器
	EntityManager* entityManager = EntityManager::getInstance();
	//文件管理器
	SettingsManager& settingManager = SettingsManager::getInstance();
	while (!isUnlock)
	{
		UnlockFailureCG = rand() % 10;//随机给赋值1-10；
		//通过-base循环遍历01链里面所有的值
		int count = 0;//记录里面解锁的cg图数量

		for (int i = 0; i< 10; i++)
		{
			if (settingManager.unlockedCGs[i])//读取到一个解锁的cg图就++
			{
				count++;
			}
			if (count == 10)//十个都解锁了就退出while循环
			{
				isUnlock = true;
			}
		}
		if (settingManager.unlockedCGs[UnlockFailureCG] == true)
		{
			continue;
		}
		settingManager.unlockedCGs[UnlockFailureCG] = true;
		isUnlock = true;
	}
	SelectFailureCG = UnlockFailureCG + 1;
	//设置背景图片
	BackgroundImage.setTexture(assetManager.getTexture("JumkoMenu"));
	// 使图片变暗但仍然可见
	BackgroundImage.setColor(sf::Color(128, 128, 128, 255));
	//初始化结束文本
	endText.setFont(assetManager.getFont("simhei")); //设置字体
	endText.setCharacterSize(60); //设置字体大小
	endText.setFillColor(sf::Color::White);  //设置字体颜色
	endText.setString(L"很遗憾你失败了！");
	sf::FloatRect textBounds = endText.getLocalBounds();
	endText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
	endText.setPosition(960 / 2.0f, 960 / 2.0f - 100);//设置文本位置

	//设置时间文本
	this->TotalTime = entityManager->getPlayer()->getTime();
	//更新时间显示
	int minutes = static_cast<int>(TotalTime) / 60;
	int seconds = static_cast<int>(TotalTime) % 60;
	std::stringstream timeStream;// 使用std::setw和std::setfill来确保时间总是以两位数字显示
	timeStream << std::setfill('0') << std::setw(2) << minutes << ":"
		<< std::setfill('0') << std::setw(2) << seconds;
	timeText.setFont(assetManager.getFont("simhei"));  //设置字体
	timeText.setCharacterSize(30);                       //设置字体大小
	timeText.setFillColor(sf::Color::White);             //设置字体颜色
	timeText.setString("Time: " + timeStream.str());
	sf::FloatRect timetextBounds = timeText.getLocalBounds();
	timeText.setOrigin(timetextBounds.left + timetextBounds.width / 2.0f, timetextBounds.top + timetextBounds.height / 2.0f);
	timeText.setPosition(960 / 2.0f, 960 / 2.0f);//设置文本位置

	//设置最后得分
	scoreText.setFont(assetManager.getFont("simhei"));  //设置字体
	scoreText.setCharacterSize(30);                       //设置字体大小
	scoreText.setFillColor(sf::Color::White);             //设置字体颜色
	EndScore = entityManager->getPlayer()->getScore();
	scoreText.setString("Score: " + std::to_string(EndScore));
	sf::FloatRect scoretextBounds = scoreText.getLocalBounds();
	scoreText.setOrigin(scoretextBounds.left + scoretextBounds.width / 2.0f, scoretextBounds.top + scoretextBounds.height / 2.0f);
	scoreText.setPosition(960 / 2.0f, 960 / 2.0f + 100);//设置文本位置

	//设置按钮
	Next.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"下一步", 30);
	Next.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Next.setPosition(430.0f, 630.0f, 90, 40);


	//清理所有的实体
	entityManager->clearAllEntities();

	//保存文件
	SettingsManager::getInstance().saveSettings("Asset/save.txt");

	//播放战败音效
	AudioManager::getInstance().playSound("Jumko_Fail");
}


void StateFailure::handleInput(sf::RenderWindow& window)
{
	sf::Event event;
	//引用音频播放单例
	AudioManager& audioManager = AudioManager::getInstance();
	while (window.pollEvent(event))
	{
		//获取鼠标位置
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		if (event.type == sf::Event::Closed)
		{
			AudioManager::getInstance().playSound("Jumko_Exit");
			sf::sleep(sf::seconds(2));
			window.close();
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			//获取鼠标位置
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (this->Next.isMouseOver(mousePosition))
			{
				this->stateManager.changeState(stateManager.createState("OpenFailureCG"));
				audioManager.playSound("ClickButton");
			}
		}
		if (event.type == sf::Event::MouseMoved)
		{
			if (Next.isMouseOver(mousePosition))
			{
				Next.onHover();
			}
			else
			{
				Next.resetColor();
			}
		}
	}
}

void StateFailure::update(float deltaTime)
{

}

void StateFailure::draw(sf::RenderWindow& window)
{
	//最先渲染背景图片
	window.draw(BackgroundImage);
	window.draw(this->endText);
	window.draw(this->timeText);
	window.draw(this->scoreText);
	this->Next.draw(window);
}

OpenFailureCG::OpenFailureCG(StateManager& manager) :stateManager(manager)
{
	//获取素材管理器的单例
	AssetManager& assetManager = AssetManager::getInstance();
	//获取要打开的战败CG图
	this->SelectFailureCG = StateFailure::SelectFailureCG;
	//设置文本
	GameOver.setFont(assetManager.getFont("simhei"));
	GameOver.setFillColor(sf::Color::Red);
	GameOver.setCharacterSize(80);
	GameOver.setString("GameOver");
	GameOver.setPosition(350, 50);

	//设置“返回”按钮
	home.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"返回主菜单", 30);
	home.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	home.setPosition(50, 50, 200, 50);
	//初始化战败CG图片（未完成）
	FailureCG1.setTexture(assetManager.getTexture("WEIMEI1"));
	FailureCG1.setScale(960.0f / assetManager.getTexture("WEIMEI1").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
	FailureCG1.setPosition(0, 0);

	FailureCG2.setTexture(assetManager.getTexture("WEIMEI2"));
	FailureCG2.setScale(960.0f / assetManager.getTexture("WEIMEI2").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
	FailureCG2.setPosition(0, 0);

	FailureCG3.setTexture(assetManager.getTexture("WEIMEI3"));
	FailureCG3.setScale(960.0f / assetManager.getTexture("WEIMEI3").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
	FailureCG3.setPosition(0, 0);

	FailureCG4.setTexture(assetManager.getTexture("WEIMEI4"));
	FailureCG4.setScale(960.0f / assetManager.getTexture("WEIMEI4").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
	FailureCG4.setPosition(0, 0);

	FailureCG5.setTexture(assetManager.getTexture("WEIMEI5"));
	FailureCG5.setScale(960.0f / assetManager.getTexture("WEIMEI5").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
	FailureCG5.setPosition(0, 0);

	FailureCG6.setTexture(assetManager.getTexture("WEIMEI6"));
	FailureCG6.setScale(960.0f / assetManager.getTexture("WEIMEI6").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
	FailureCG6.setPosition(0, 0);

	FailureCG7.setTexture(assetManager.getTexture("WEIMEI7"));
	FailureCG7.setScale(960.0f / assetManager.getTexture("WEIMEI7").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
	FailureCG7.setPosition(0, 0);

	FailureCG8.setTexture(assetManager.getTexture("WEIMEI8"));
	FailureCG8.setScale(960.0f / assetManager.getTexture("WEIMEI8").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
	FailureCG8.setPosition(0, 0);

	FailureCG9.setTexture(assetManager.getTexture("WEIMEI9"));
	FailureCG9.setScale(960.0f / assetManager.getTexture("WEIMEI9").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
	FailureCG9.setPosition(0, 0);

	FailureCG10.setTexture(assetManager.getTexture("WEIMEI10"));
	FailureCG10.setScale(960.0f / assetManager.getTexture("WEIMEI10").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
	FailureCG10.setPosition(0, 0);

	//保存文件
	SettingsManager::getInstance().saveSettings("Asset/save.txt");
}
//处理输入的事件
void OpenFailureCG::handleInput(sf::RenderWindow& window)
{
	sf::Event event;
	//引用音频播放单例
	AudioManager& audioManager = AudioManager::getInstance();
	while (window.pollEvent(event))
	{
		//获取鼠标位置
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		if (event.type == sf::Event::Closed)
		{
			AudioManager::getInstance().playSound("Jumko_Exit");
			sf::sleep(sf::seconds(2));
			window.close();
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			//获取鼠标位置
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (this->home.isMouseOver(mousePosition)) {
				//返回主界面
				this->stateManager.changeState(std::make_unique<StateMenu>(stateManager));
				audioManager.playSound("ClickButton");
				//播放BGM
				audioManager.playMusic("MenuMusic1", true);
				//播放标题语音
				audioManager.playSound("Jumko_Title");
			}
		}
		if (event.type == sf::Event::MouseMoved)
		{
			if (home.isMouseOver(mousePosition)) {
				home.onHover();
			}
			else {
				//当鼠标不再悬停在按钮上时恢复原始颜色
				home.resetColor();
			}
		}
	}
}
//更新
void OpenFailureCG::update(float deltaTime)
{

}
//渲染
void OpenFailureCG::draw(sf::RenderWindow& window)
{
	//根据SelectFailureCG的值来确定要绘制的战败CG图
	if (this->SelectFailureCG == 1)
	{
		window.draw(FailureCG1);
	}
	else if (this->SelectFailureCG == 2)
	{
		window.draw(FailureCG2);
	}
	else if (this->SelectFailureCG == 3)
	{
		window.draw(FailureCG3);
	}
	else if (this->SelectFailureCG == 4)
	{
		window.draw(FailureCG4);
	}
	else if (this->SelectFailureCG == 5)
	{
		window.draw(FailureCG5);
	}
	else if (this->SelectFailureCG == 6)
	{
		window.draw(FailureCG6);
	}
	else if (this->SelectFailureCG == 7)
	{
		window.draw(FailureCG7);
	}
	else if (this->SelectFailureCG == 8)
	{
		window.draw(FailureCG8);
	}
	else if (this->SelectFailureCG == 9)
	{
		window.draw(FailureCG9);
	}
	else if (this->SelectFailureCG == 10)
	{
		window.draw(FailureCG10);
	}
	window.draw(this->GameOver);
	home.draw(window);
}
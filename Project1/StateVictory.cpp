#include"StateVictory.hpp"
#include"StateMenu.hpp"


bool StateVictory::isHard = false;
//构造方法
StateVictory::StateVictory(StateManager& manager) :stateManager(manager)
{
	//获取素材管理器的单例
	AssetManager& assetManager = AssetManager::getInstance();
	//实体管理器
	EntityManager* entityManager = EntityManager::getInstance();
	//文件管理器
	SettingsManager& settingManager = SettingsManager::getInstance();
	//设置背景图片
	BackgroundImage.setTexture(assetManager.getTexture("JumkoMenu"));
	// 使图片变暗但仍然可见
	BackgroundImage.setColor(sf::Color(128, 128, 128, 255));
	//初始化结束文本
	endText.setFont(assetManager.getFont("simhei")); //设置字体
	endText.setCharacterSize(60); //设置字体大小
	endText.setFillColor(sf::Color::White);  //设置字体颜色
	endText.setString(L"恭喜你，你获胜了！");
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
	//获取玩家是否选择了困难模式
	isHard = entityManager->getPlayer()->isHardCore();

	//清理所有的实体
	entityManager->clearAllEntities();

	//保存文件
	SettingsManager::getInstance().saveSettings("Asset/save.txt");

	//播放获胜音效
	AudioManager::getInstance().playSound("Jumko_Victory");
}

//处理输入的事件
void StateVictory::handleInput(sf::RenderWindow& window)
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
				this->stateManager.changeState(stateManager.createState("OpenVictoryCG"));
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

//更新
void StateVictory::update(float deltaTime)
{

}

//渲染（未完成）
void StateVictory::draw(sf::RenderWindow& window)
{
	window.draw(BackgroundImage);
	window.draw(this->endText);
	window.draw(this->timeText);
	window.draw(this->scoreText);
	this->Next.draw(window);
}

OpenVictoryCG::OpenVictoryCG(StateManager& manager) :stateManager(manager)
{
	//获取素材管理器的单例
	AssetManager& assetManager = AssetManager::getInstance();

	//设置“返回”按钮
	home.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"返回主菜单", 30);
	home.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	home.setPosition(50, 50, 200, 50);

	//初始化胜利CG图片（未完成）
	VictoryCG1.setTexture(assetManager.getTexture("WEIMEI11"));
	VictoryCG1.setScale(960.0f / assetManager.getTexture("WEIMEI11").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
	VictoryCG1.setPosition(0, 0);

	VictoryCG2.setTexture(assetManager.getTexture("WEIMEI12"));
	VictoryCG2.setScale(960.0f / assetManager.getTexture("WEIMEI12").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
	VictoryCG2.setPosition(0, 0);

	//修改文件
	SettingsManager& settingManager = SettingsManager::getInstance();
	//简单模式的胜利CG
	if (StateVictory::isHard == false)
	{
		settingManager.unlockedCGs[10] = 1;
	}
	else if (StateVictory::isHard == true)//困难模式的胜利CG
	{
		settingManager.unlockedCGs[11] = 1;
	}

	//保存文件
	SettingsManager::getInstance().saveSettings("Asset/save.txt");
}

//处理输入的事件
void OpenVictoryCG::handleInput(sf::RenderWindow& window)
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
void OpenVictoryCG::update(float deltaTime) {

}

//渲染
void OpenVictoryCG::draw(sf::RenderWindow& window)
{
	//简单模式的胜利CG
	if (StateVictory::isHard == false)
	{
		window.draw(VictoryCG1);
	}
	else if (StateVictory::isHard == true)//困难模式的胜利CG
	{
		window.draw(VictoryCG2);
	}
	home.draw(window);
}
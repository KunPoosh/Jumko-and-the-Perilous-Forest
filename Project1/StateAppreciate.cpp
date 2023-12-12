#include"StateAppreciate.hpp"
#include"StateMenu.hpp"

//初始化静态成员
int StateAppreciate::SelectImage = -1;
int StateAppreciate2::SelectImage2 = -1;
//构造函数，初始化界面
StateAppreciate::StateAppreciate(StateManager& manager) :stateManager(manager)
{
	//获取素材管理器的单例
	AssetManager& assetManager = AssetManager::getInstance();

	//设置“返回”按钮
	home.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"返回", 30);
	home.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	home.setPosition(50, 50, 200, 50);
	//设置下一页按钮
	Next.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"下一页", 30);
	Next.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Next.setPosition(490, 150, 90, 40);
	//设置上一页按钮
	Prior.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"上一页", 30);
	Prior.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Prior.setPosition(310, 150, 90, 40);
	//设置背景图片
	BackgroundImage.setTexture(assetManager.getTexture("JumkoMenu"));
	// 使图片变暗但仍然可见
	BackgroundImage.setColor(sf::Color(128, 128, 128, 255));

	//初始化标题
	title.setFont(assetManager.getFont("simhei"));
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(70);
	title.setString("Appreciate");
	title.setPosition(350, 50);

	//设置矩形圆角框大小
	roundedRect1.setSize(sf::Vector2f(300, 200));
	roundedRect2.setSize(sf::Vector2f(300, 200));
	roundedRect3.setSize(sf::Vector2f(300, 200));
	roundedRect4.setSize(sf::Vector2f(300, 200));
	roundedRect5.setSize(sf::Vector2f(300, 200));
	roundedRect6.setSize(sf::Vector2f(300, 200));
	//设置矩形圆角框颜色
	roundedRect1.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect2.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect3.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect4.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect5.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect6.setFillColor(sf::Color(200, 200, 200, 150));
	//设置矩形圆角框位置
	roundedRect1.setPosition(100, 200);
	roundedRect2.setPosition(490, 200);
	roundedRect3.setPosition(100, 450);
	roundedRect4.setPosition(490, 450);
	roundedRect5.setPosition(100, 700);
	roundedRect6.setPosition(490, 700);
	// 设置每个圆角矩形框的边框颜色
	roundedRect1.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect2.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect3.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect4.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect5.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect6.setOutlineColor(sf::Color(200, 200, 200, 150));
	// 设置每个圆角矩形框的边框厚度
	roundedRect1.setOutlineThickness(1);
	roundedRect2.setOutlineThickness(1);
	roundedRect3.setOutlineThickness(1);
	roundedRect4.setOutlineThickness(1);
	roundedRect5.setOutlineThickness(1);
	roundedRect6.setOutlineThickness(1);
	//设置精灵
	sprite1.setTexture(assetManager.getTexture("WEIMEI1"));
	sprite1.setPosition(100, 200);
	sprite1.setScale(300.0f / assetManager.getTexture("WEIMEI1").getSize().x, 200.0f / assetManager.getTexture("WEIMEI1").getSize().y);

	sprite2.setTexture(assetManager.getTexture("WEIMEI2"));
	sprite2.setPosition(490, 200);
	sprite2.setScale(300.0f / assetManager.getTexture("WEIMEI2").getSize().x, 200.0f / assetManager.getTexture("WEIMEI2").getSize().y);

	sprite3.setTexture(assetManager.getTexture("WEIMEI3"));
	sprite3.setPosition(100, 450);
	sprite3.setScale(300.0f / assetManager.getTexture("WEIMEI3").getSize().x, 200.0f / assetManager.getTexture("WEIMEI3").getSize().y);

	sprite4.setTexture(assetManager.getTexture("WEIMEI4"));
	sprite4.setPosition(490, 450);
	sprite4.setScale(300.0f / assetManager.getTexture("WEIMEI4").getSize().x, 200.0f / assetManager.getTexture("WEIMEI4").getSize().y);

	sprite5.setTexture(assetManager.getTexture("WEIMEI5"));
	sprite5.setPosition(100, 700);
	sprite5.setScale(300.0f / assetManager.getTexture("WEIMEI5").getSize().x, 200.0f / assetManager.getTexture("WEIMEI4").getSize().y);

	sprite6.setTexture(assetManager.getTexture("WEIMEI6"));
	sprite6.setPosition(490, 700);
	sprite6.setScale(300.0f / assetManager.getTexture("WEIMEI6").getSize().x, 200.0f / assetManager.getTexture("WEIMEI4").getSize().y);
	//设置CG覆盖图
	CGBackground1.setTexture(assetManager.getTexture("Close"));
	CGBackground1.setPosition(100, 200);
	CGBackground1.setScale(300.0f / assetManager.getTexture("Close").getSize().x, 200.0f / assetManager.getTexture("Close").getSize().y);

	CGBackground2.setTexture(assetManager.getTexture("Close"));
	CGBackground2.setPosition(490, 200);
	CGBackground2.setScale(300.0f / assetManager.getTexture("Close").getSize().x, 200.0f / assetManager.getTexture("Close").getSize().y);

	CGBackground3.setTexture(assetManager.getTexture("Close"));
	CGBackground3.setPosition(100, 450);
	CGBackground3.setScale(300.0f / assetManager.getTexture("Close").getSize().x, 200.0f / assetManager.getTexture("Close").getSize().y);

	CGBackground4.setTexture(assetManager.getTexture("Close"));
	CGBackground4.setPosition(490, 450);
	CGBackground4.setScale(300.0f / assetManager.getTexture("Close").getSize().x, 200.0f / assetManager.getTexture("Close").getSize().y);

	CGBackground5.setTexture(assetManager.getTexture("Close"));
	CGBackground5.setPosition(100, 700);
	CGBackground5.setScale(300.0f / assetManager.getTexture("Close").getSize().x, 200.0f / assetManager.getTexture("Close").getSize().y);

	CGBackground6.setTexture(assetManager.getTexture("Close"));
	CGBackground6.setPosition(490, 700);
	CGBackground6.setScale(300.0f / assetManager.getTexture("Close").getSize().x, 200.0f / assetManager.getTexture("Close").getSize().y);

}


void StateAppreciate::handleInput(sf::RenderWindow& window)
{
	sf::Event event;
	//引用音频播放单例
	AudioManager& audioManager = AudioManager::getInstance();
	//引用文件管理单例
	SettingsManager& settingsManager = SettingsManager::getInstance();
	while (window.pollEvent(event))
	{
		//获取鼠标位置
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
		//当点击关闭时关闭窗口
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		// ... 处理按钮点击事件，使用stateManager.changeState(...)
		if (event.type == sf::Event::MouseButtonPressed) {
			//获取鼠标位置
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (this->home.isMouseOver(mousePosition)) {
				this->stateManager.changeState(std::make_unique<StateMenu>(stateManager));
				audioManager.playSound("ClickButton");
			}
			/*点击下一页按钮*/
			else if (this->Next.isMouseOver(mousePosition))
			{
				this->stateManager.changeState(stateManager.createState("Appreciate2"));
				audioManager.playSound("ClickButton");
			}
			//鼠标点击第一张图片
			else if (sprite1.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				//01链允许打开第一张图片
				if (settingsManager.unlockedCGs[0] == 1)
				{
					SelectImage = 1;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate"));
				}
			}
			//鼠标点击第二张图片
			else if (sprite2.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[1] == 1)
				{
					SelectImage = 2;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate"));
				}
			}
			//鼠标点击第三张图片
			else if (sprite3.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[2] == 1)
				{
					SelectImage = 3;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate"));
				}
			}
			//鼠标点击第四张图片
			else if (sprite4.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[3] == 1)
				{
					SelectImage = 4;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate"));
				}
			}
			//鼠标点击第五张图片
			else if (sprite5.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[4] == 1)
				{
					SelectImage = 5;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate"));
				}
			}
			//鼠标点击第五张图片
			else if (sprite6.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[5] == 1)
				{
					SelectImage = 6;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate"));
				}
			}
		}
		if (event.type == sf::Event::MouseMoved) {
			if (home.isMouseOver(mousePosition)) {
				home.onHover();
			}
			else if (Next.isMouseOver(mousePosition))
			{
				Next.onHover();
			}
			else {
				//当鼠标不再悬停在按钮上时恢复原始颜色
				home.resetColor();
				Next.resetColor();
			}
		}
	}
}

void StateAppreciate::update(float deltaTime) {

}
void StateAppreciate::draw(sf::RenderWindow& window) {
	//最先渲染背景图片
	window.draw(BackgroundImage);
	//引用文件管理单例
	SettingsManager& settingsManager = SettingsManager::getInstance();
	// ... 绘制按钮
	this->home.draw(window);
	this->Next.draw(window);
	this->Prior.draw(window);
	//绘制文字
	window.draw(this->title);

	//绘制矩形圆角框
	window.draw(roundedRect1);
	window.draw(roundedRect2);
	window.draw(roundedRect3);
	window.draw(roundedRect4);
	window.draw(roundedRect5);
	window.draw(roundedRect6);
	//绘制图片
	window.draw(sprite1);
	window.draw(sprite2);
	window.draw(sprite3);
	window.draw(sprite4);
	window.draw(sprite5);
	window.draw(sprite6);
	//绘制CG覆盖图
	//如果01链锁上，则要绘制
	if (settingsManager.unlockedCGs[0] == 0)
	{
		window.draw(CGBackground1);
	}
	if (settingsManager.unlockedCGs[1] == 0)
	{
		window.draw(CGBackground2);
	}
	if (settingsManager.unlockedCGs[2] == 0)
	{
		window.draw(CGBackground3);
	}
	if (settingsManager.unlockedCGs[3] == 0)
	{
		window.draw(CGBackground4);
	}
	if (settingsManager.unlockedCGs[4] == 0)
	{
		window.draw(CGBackground5);
	}
	if (settingsManager.unlockedCGs[5] == 0)
	{
		window.draw(CGBackground6);
	}
}



//-----------------------------------------------------------------------------
//鉴赏界面2
StateAppreciate2::StateAppreciate2(StateManager& manager) :stateManager(manager)
{
	//获取素材管理器的单例
	AssetManager& assetManager = AssetManager::getInstance();

	//设置下一页按钮
	Next.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"下一页", 30);
	Next.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Next.setPosition(490, 150, 90, 40);
	//设置上一页按钮
	Prior.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"上一页", 30);
	Prior.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Prior.setPosition(310, 150, 90, 40);
	//设置背景图片
	BackgroundImage.setTexture(assetManager.getTexture("JumkoMenu"));
	// 使图片变暗但仍然可见
	BackgroundImage.setColor(sf::Color(128, 128, 128, 255));

	//初始化标题
	title.setFont(assetManager.getFont("simhei"));
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(70);
	title.setString("Appreciate");
	title.setPosition(350, 50);

	//设置矩形圆角框大小
	roundedRect7.setSize(sf::Vector2f(300, 200));
	roundedRect8.setSize(sf::Vector2f(300, 200));
	roundedRect9.setSize(sf::Vector2f(300, 200));
	roundedRect10.setSize(sf::Vector2f(300, 200));
	roundedRect11.setSize(sf::Vector2f(300, 200));
	roundedRect12.setSize(sf::Vector2f(300, 200));
	//设置矩形圆角框颜色
	roundedRect7.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect8.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect9.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect10.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect11.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect12.setFillColor(sf::Color(200, 200, 200, 150));
	//设置矩形圆角框位置
	roundedRect7.setPosition(100, 200);
	roundedRect8.setPosition(490, 200);
	roundedRect9.setPosition(100, 450);
	roundedRect10.setPosition(490, 450);
	roundedRect11.setPosition(100, 700);
	roundedRect12.setPosition(490, 700);
	// 设置每个圆角矩形框的边框颜色
	roundedRect7.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect8.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect9.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect10.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect11.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect12.setOutlineColor(sf::Color(200, 200, 200, 150));
	// 设置每个圆角矩形框的边框厚度
	roundedRect7.setOutlineThickness(1);
	roundedRect8.setOutlineThickness(1);
	roundedRect9.setOutlineThickness(1);
	roundedRect10.setOutlineThickness(1);
	roundedRect11.setOutlineThickness(1);
	roundedRect12.setOutlineThickness(1);

	//设置图片精灵
	sprite7.setTexture(assetManager.getTexture("WEIMEI7"));
	sprite7.setPosition(100, 200);
	sprite7.setScale(300.0f / assetManager.getTexture("WEIMEI7").getSize().x, 200.0f / assetManager.getTexture("WEIMEI1").getSize().y);

	sprite8.setTexture(assetManager.getTexture("WEIMEI8"));
	sprite8.setPosition(490, 200);
	sprite8.setScale(300.0f / assetManager.getTexture("WEIMEI8").getSize().x, 200.0f / assetManager.getTexture("WEIMEI2").getSize().y);

	sprite9.setTexture(assetManager.getTexture("WEIMEI9"));
	sprite9.setPosition(100, 450);
	sprite9.setScale(300.0f / assetManager.getTexture("WEIMEI9").getSize().x, 200.0f / assetManager.getTexture("WEIMEI3").getSize().y);

	sprite10.setTexture(assetManager.getTexture("WEIMEI10"));
	sprite10.setPosition(490, 450);
	sprite10.setScale(300.0f / assetManager.getTexture("WEIMEI10").getSize().x, 200.0f / assetManager.getTexture("WEIMEI4").getSize().y);

	sprite11.setTexture(assetManager.getTexture("WEIMEI11"));
	sprite11.setPosition(100, 700);
	sprite11.setScale(300.0f / assetManager.getTexture("WEIMEI11").getSize().x, 200.0f / assetManager.getTexture("WEIMEI4").getSize().y);

	sprite12.setTexture(assetManager.getTexture("WEIMEI12"));
	sprite12.setPosition(490, 700);
	sprite12.setScale(300.0f / assetManager.getTexture("WEIMEI12").getSize().x, 200.0f / assetManager.getTexture("WEIMEI4").getSize().y);

	//设置CG覆盖图
	CGBackground7.setTexture(assetManager.getTexture("Close"));
	CGBackground7.setPosition(100, 200);
	CGBackground7.setScale(300.0f / assetManager.getTexture("Close").getSize().x, 200.0f / assetManager.getTexture("Close").getSize().y);

	CGBackground8.setTexture(assetManager.getTexture("Close"));
	CGBackground8.setPosition(490, 200);
	CGBackground8.setScale(300.0f / assetManager.getTexture("Close").getSize().x, 200.0f / assetManager.getTexture("Close").getSize().y);

	CGBackground9.setTexture(assetManager.getTexture("Close"));
	CGBackground9.setPosition(100, 450);
	CGBackground9.setScale(300.0f / assetManager.getTexture("Close").getSize().x, 200.0f / assetManager.getTexture("Close").getSize().y);

	CGBackground10.setTexture(assetManager.getTexture("Close"));
	CGBackground10.setPosition(490, 450);
	CGBackground10.setScale(300.0f / assetManager.getTexture("Close").getSize().x, 200.0f / assetManager.getTexture("Close").getSize().y);

	CGBackground11.setTexture(assetManager.getTexture("Close"));
	CGBackground11.setPosition(100, 700);
	CGBackground11.setScale(300.0f / assetManager.getTexture("Close").getSize().x, 200.0f / assetManager.getTexture("Close").getSize().y);

	CGBackground12.setTexture(assetManager.getTexture("Close"));
	CGBackground12.setPosition(490, 700);
	CGBackground12.setScale(300.0f / assetManager.getTexture("Close").getSize().x, 200.0f / assetManager.getTexture("Close").getSize().y);

}
void StateAppreciate2::handleInput(sf::RenderWindow& window)
{
	sf::Event event;
	//引用音频播放单例
	AudioManager& audioManager = AudioManager::getInstance();
	//引用文件管理单例
	SettingsManager& settingsManager = SettingsManager::getInstance();
	while (window.pollEvent(event))
	{
		//获取鼠标位置
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		//当点击关闭时关闭窗口
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		// ... 处理按钮点击事件，使用stateManager.changeState(...)
		if (event.type == sf::Event::MouseButtonPressed) {
			//获取鼠标位置
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);

			//点击上一页按钮
			if (this->Prior.isMouseOver(mousePosition))
			{
				this->stateManager.changeState(stateManager.createState("Appreciate"));
				audioManager.playSound("ClickButton");
			}
			//鼠标点击第七张图片
			else if (sprite7.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				//01链允许打开第七张图片
				if (settingsManager.unlockedCGs[6] == 1)
				{
					SelectImage2 = 7;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate2"));
				}
			}
			//鼠标点击第八张图片
			else if (sprite8.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[7] == 1)
				{
					SelectImage2 = 8;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate2"));
				}
			}
			//鼠标点击第九张图片
			else if (sprite9.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[8] == 1)
				{
					SelectImage2 = 9;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate2"));
				}
			}
			//鼠标点击第十张图片
			else if (sprite10.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[9] == 1)
				{
					SelectImage2 = 10;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate2"));
				}
			}
			//鼠标点击第十一张图片
			else if (sprite11.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[10] == 1)
				{
					SelectImage2 = 11;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate2"));
				}
			}
			//鼠标点击第十二张图片
			else if (sprite12.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[11] == 1)
				{
					SelectImage2 = 12;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate2"));
				}
			}
		}
		if (event.type == sf::Event::MouseMoved) {
			if (Prior.isMouseOver(mousePosition))
			{
				Prior.onHover();
			}
			else {
				//当鼠标不再悬停在按钮上时恢复原始颜色
				Prior.resetColor();
			}
		}
	}
}
void StateAppreciate2::update(float deltaTime) {

}
void StateAppreciate2::draw(sf::RenderWindow& window) {
	//获取文件管理器
	SettingsManager& settingsManager = SettingsManager::getInstance();
	//最先渲染背景图片
	window.draw(BackgroundImage);
	// ... 绘制按钮
	this->Next.draw(window);
	this->Prior.draw(window);
	//绘制文字
	window.draw(this->title);
	//绘制矩形圆角框
	window.draw(roundedRect7);
	window.draw(roundedRect8);
	window.draw(roundedRect9);
	window.draw(roundedRect10);
	window.draw(roundedRect11);
	window.draw(roundedRect12);
	//绘制图片
	window.draw(sprite7);
	window.draw(sprite8);
	window.draw(sprite9);
	window.draw(sprite10);
	window.draw(sprite11);
	window.draw(sprite12);
	//如果01链锁上，则要绘制
	if (settingsManager.unlockedCGs[6] == 0)
	{
		window.draw(CGBackground7);
	}
	if (settingsManager.unlockedCGs[7] == 0)
	{
		window.draw(CGBackground8);
	}
	if (settingsManager.unlockedCGs[8] == 0)
	{
		window.draw(CGBackground9);
	}
	if (settingsManager.unlockedCGs[9] == 0)
	{
		window.draw(CGBackground10);
	}
	if (settingsManager.unlockedCGs[10] == 0)
	{
		window.draw(CGBackground11);
	}
	if (settingsManager.unlockedCGs[11] == 0)
	{
		window.draw(CGBackground12);
	}
}



//-----------------------------------------------------------------------
//必须要初始化的时候写上Appreciate(manager)，否则会出现Appreciate没有调用默认构造函数的错误
MagnifyAppreciate::MagnifyAppreciate(StateManager& manager) : StateAppreciate(manager), stateManager(manager)
{

	//获取素材管理器的单例
	AssetManager& assetManager = AssetManager::getInstance();

	//设置“返回”按钮
	home.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"返回", 30);
	home.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	home.setPosition(50, 50, 200, 50);

	if (StateAppreciate::SelectImage == 1)
	{
		//设置精灵1，让它充当背景图
		sprite1.setTexture(assetManager.getTexture("WEIMEI1"));
		sprite1.setScale(960.0f / assetManager.getTexture("WEIMEI1").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
		sprite1.setPosition(0, 0);
	}
	else if (StateAppreciate::SelectImage == 2)
	{
		//设置精灵2，让它充当背景图
		sprite2.setTexture(assetManager.getTexture("WEIMEI2"));
		sprite2.setScale(960.0f / assetManager.getTexture("WEIMEI2").getSize().x, 960.0f / assetManager.getTexture("WEIMEI2").getSize().y);
		sprite2.setPosition(0, 0);
	}
	else if (StateAppreciate::SelectImage == 3)
	{
		//设置精灵3，让它充当背景图
		sprite3.setTexture(assetManager.getTexture("WEIMEI3"));
		sprite3.setScale(960.0f / assetManager.getTexture("WEIMEI3").getSize().x, 960.0f / assetManager.getTexture("WEIMEI3").getSize().y);
		sprite3.setPosition(0, 0);
	}
	else if (StateAppreciate::SelectImage == 4)
	{
		//设置精灵4，让它充当背景图
		sprite4.setTexture(assetManager.getTexture("WEIMEI4"));
		sprite4.setScale(960.0f / assetManager.getTexture("WEIMEI4").getSize().x, 960.0f / assetManager.getTexture("WEIMEI4").getSize().y);
		sprite4.setPosition(0, 0);
	}
	else if (StateAppreciate::SelectImage == 5)
	{
		//设置精灵5，让它充当背景图
		sprite5.setTexture(assetManager.getTexture("WEIMEI5"));
		sprite5.setScale(960.0f / assetManager.getTexture("WEIMEI5").getSize().x, 960.0f / assetManager.getTexture("WEIMEI4").getSize().y);
		sprite5.setPosition(0, 0);
	}
	else if (StateAppreciate::SelectImage == 6)
	{
		//设置精灵6，让它充当背景图
		sprite6.setTexture(assetManager.getTexture("WEIMEI6"));
		sprite6.setScale(960.0f / assetManager.getTexture("WEIMEI6").getSize().x, 960.0f / assetManager.getTexture("WEIMEI4").getSize().y);
		sprite6.setPosition(0, 0);
	}
}

//处理输入的事件（未完成）
void MagnifyAppreciate::handleInput(sf::RenderWindow& window)
{
	sf::Event event;
	//引用音频播放单例
	AudioManager& audioManager = AudioManager::getInstance();
	while (window.pollEvent(event))
	{
		//获取鼠标位置
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		//当点击关闭时关闭窗口
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		// ... 处理按钮点击事件，使用stateManager.changeState(...)
		if (event.type == sf::Event::MouseButtonPressed) {
			if (this->home.isMouseOver(mousePosition)) {
				this->stateManager.changeState(std::make_unique<StateAppreciate>(stateManager));
				audioManager.playSound("ClickButton");
				StateAppreciate::SelectImage = -1;
			}
		}
		if (event.type == sf::Event::MouseMoved) {
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

void MagnifyAppreciate::update(float deltaTime)
{

}

//渲染（未完成）
void MagnifyAppreciate::draw(sf::RenderWindow& window)
{
	//根据选择值来确定绘制的图片
	if (StateAppreciate::SelectImage == 1)
	{
		window.draw(sprite1);
	}
	else if (StateAppreciate::SelectImage == 2)
	{
		window.draw(sprite2);
	}
	else if (StateAppreciate::SelectImage == 3)
	{
		window.draw(sprite3);
	}
	else if (StateAppreciate::SelectImage == 4)
	{
		window.draw(sprite4);
	}
	else if (StateAppreciate::SelectImage == 5)
	{
		window.draw(sprite5);
	}
	else if (StateAppreciate::SelectImage == 6)
	{
		window.draw(sprite6);
	}
	// ... 绘制按钮
	this->home.draw(window);
}

//-------------------------------------------
MagnifyAppreciate2::MagnifyAppreciate2(StateManager& manager) :StateAppreciate2(manager), stateManager(manager) {
	//获取素材管理器的单例
	AssetManager& assetManager = AssetManager::getInstance();

	//设置“返回”按钮
	home.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"返回", 30);
	home.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	home.setPosition(50, 50, 200, 50);

	if (StateAppreciate2::SelectImage2 == 7)
	{
		//设置精灵7，让它充当背景图
		sprite7.setTexture(assetManager.getTexture("WEIMEI7"));
		sprite7.setScale(960.0f / assetManager.getTexture("WEIMEI7").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
		sprite7.setPosition(0, 0);
	}
	else if (StateAppreciate2::SelectImage2 == 8)
	{
		//设置精灵8，让它充当背景图
		sprite8.setTexture(assetManager.getTexture("WEIMEI8"));
		sprite8.setScale(960.0f / assetManager.getTexture("WEIMEI8").getSize().x, 960.0f / assetManager.getTexture("WEIMEI2").getSize().y);
		sprite8.setPosition(0, 0);
	}
	else if (StateAppreciate2::SelectImage2 == 9)
	{
		//设置精灵9，让它充当背景图
		sprite9.setTexture(assetManager.getTexture("WEIMEI9"));
		sprite9.setScale(960.0f / assetManager.getTexture("WEIMEI9").getSize().x, 960.0f / assetManager.getTexture("WEIMEI3").getSize().y);
		sprite9.setPosition(0, 0);
	}
	else if (StateAppreciate2::SelectImage2 == 10)
	{
		//设置精灵10，让它充当背景图
		sprite10.setTexture(assetManager.getTexture("WEIMEI10"));
		sprite10.setScale(960.0f / assetManager.getTexture("WEIMEI10").getSize().x, 960.0f / assetManager.getTexture("WEIMEI4").getSize().y);
		sprite10.setPosition(0, 0);
	}
	else if (StateAppreciate2::SelectImage2 == 11)
	{
		//设置精灵11，让它充当背景图
		sprite11.setTexture(assetManager.getTexture("WEIMEI11"));
		sprite11.setScale(960.0f / assetManager.getTexture("WEIMEI11").getSize().x, 960.0f / assetManager.getTexture("WEIMEI4").getSize().y);
		sprite11.setPosition(0, 0);
	}
	else if (StateAppreciate2::SelectImage2 == 12)
	{
		//设置精灵12，让它充当背景图
		sprite12.setTexture(assetManager.getTexture("WEIMEI12"));
		sprite12.setScale(960.0f / assetManager.getTexture("WEIMEI12").getSize().x, 960.0f / assetManager.getTexture("WEIMEI4").getSize().y);
		sprite12.setPosition(0, 0);
	}

}
//处理输入的事件
void MagnifyAppreciate2::handleInput(sf::RenderWindow& window) {
	sf::Event event;
	//引用音频播放单例
	AudioManager& audioManager = AudioManager::getInstance();
	while (window.pollEvent(event))
	{
		//获取鼠标位置
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		//当点击关闭时关闭窗口
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		// ... 处理按钮点击事件，使用stateManager.changeState(...)
		if (event.type == sf::Event::MouseButtonPressed) {
			if (this->home.isMouseOver(mousePosition)) {
				this->stateManager.changeState(std::make_unique<StateAppreciate2>(stateManager));
				audioManager.playSound("ClickButton");
				StateAppreciate2::SelectImage2 = -1;
			}
		}
		if (event.type == sf::Event::MouseMoved) {
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
void MagnifyAppreciate2::update(float deltaTime) {

}

//渲染
void MagnifyAppreciate2::draw(sf::RenderWindow& window)
{
	//根据选择值来确定绘制的图片
	if (StateAppreciate2::SelectImage2 == 7)
	{
		window.draw(sprite7);
	}
	else if (StateAppreciate2::SelectImage2 == 8)
	{
		window.draw(sprite8);
	}
	else if (StateAppreciate2::SelectImage2 == 9)
	{
		window.draw(sprite9);
	}
	else if (StateAppreciate2::SelectImage2 == 10)
	{
		window.draw(sprite10);
	}
	else if (StateAppreciate2::SelectImage2 == 11)
	{
		window.draw(sprite11);
	}
	else if (StateAppreciate2::SelectImage2 == 12)
	{
		window.draw(sprite12);
	}
	// ... 绘制按钮
	this->home.draw(window);
}
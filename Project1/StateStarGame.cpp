#include "StateStarGame.hpp"

StateStartGame::StateStartGame(StateManager& manager) : stateManager(manager) {
	//构造方法
	/*
	负责人: 波波沙

	功能:
		初始化开始场景
			1.创建按钮
			2.创建图片
			3.创建文字
			4.开始计时

	参数:
		StateManager& manager   //场景管理器单例，关联到类中的场景管理器指针上。

	返回值: StateStartGame
	*/
	//----------------------实现------------------------//

	//素材管理器单例
	AssetManager& assetManager = AssetManager::getInstance();

	//设置"设置"按钮的位置等信息。
	Next.setFont(assetManager.getFont("simhei"), sf::Color::White, L">下一步", 25);
	Next.setColor(sf::Color(200, 200, 200, 0), sf::Color(100, 100, 100, 0), sf::Color(255, 255, 255, 100));
	Next.setPosition(700, 850, 200, 50);

	//图片输入
	Pic1.setTexture(assetManager.getTexture("StartPic"));
	Pic1.setPosition(320,200);

	//文本创建,文字都在这里输入
	text1.setFont(assetManager.getFont("simhei"));
	text1.setFillColor(sf::Color::White);
	text1.setCharacterSize(30);
	text1.setString(L"酱可从小就听族里的大人讲述着这片“危险之森”的“馈赠”");
	text1.setPosition(90, 400);

	text2.setFont(assetManager.getFont("simhei"));
	text2.setFillColor(sf::Color::White);
	text2.setCharacterSize(30);
	text2.setString(L"但是从酱可看到爸爸进入危险之森已经过去三天了");
	text2.setPosition(170, 450);

	text3.setFont(assetManager.getFont("simhei"));
	text3.setFillColor(sf::Color::White);
	text3.setCharacterSize(30);
	text3.setString(L"这天酱可终于决心进入危险之森");
	text3.setPosition(250, 500);

	text4.setFont(assetManager.getFont("simhei"));
	text4.setFillColor(sf::Color::White);
	text4.setCharacterSize(30);
	text4.setString(L"寻找爸爸的踪迹......");
	text4.setPosition(350, 550);





	//时间置零
	TotalTime = 0.f;

	//3秒渐进
	animationDuration = 3.f;
}

void StateStartGame::handleInput(sf::RenderWindow& window) {
	//处理输入的事件
	/*
	负责人: 波波沙

	功能:
		读取用户输入，处理按钮

	参数:
		sf::RenderWindow& window   //从窗口获得事件

	返回值: void
	*/
	//----------------------实现------------------------//

	//事件
	sf::Event event;
	while (window.pollEvent(event))
	{
		//获取鼠标位置
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		//当点击关闭时关闭窗口
		if (event.type == sf::Event::Closed) {
			AudioManager::getInstance().playSound("Jumko_Exit");
			sf::sleep(sf::seconds(2));
			window.close();
		}

		//点击下一步按钮
		if (event.type == sf::Event::MouseButtonPressed) {
			if (this->Next.isMouseOver(mousePosition)) {
				stateManager.changeState(stateManager.createState("StateSelectDifficulty"));
			}
		}
		//悬停在按钮上面
		if (event.type == sf::Event::MouseMoved) {
			if (Next.isMouseOver(mousePosition)) {
				Next.onHover();
			}
			else {
				Next.resetColor();
			}
		}
	}

}

void StateStartGame::update(float deltaTime) {
	//更新逻辑
	/*
	负责人: 波波沙

	功能:
		更新图片和文字，实现渐出的效果

	参数:
		float deltaTime		//全局间隔时间

	返回值: void
	*/
	//----------------------实现------------------------//

	TotalTime += deltaTime;

	float progress = std::min(TotalTime / animationDuration, 1.0f);
	Pic1.setColor(sf::Color(255, 255, 255, 255 * progress));
	text1.setFillColor(sf::Color(255, 255, 255, 255 * progress));
	text2.setFillColor(sf::Color(255, 255, 255, 255 * progress));
	text3.setFillColor(sf::Color(255, 255, 255, 255 * progress));
	text4.setFillColor(sf::Color(255, 255, 255, 255 * progress));
}

void StateStartGame::draw(sf::RenderWindow& window) {
	//渲染
	/*
	负责人: 波波沙

	功能:
		渲染这个窗口改渲染的东西

	参数:
		sf::RenderWindow& window		//需要渲染到的地方

	返回值: void
	*/
	//----------------------实现------------------------//

	window.draw(Pic1);
	window.draw(text1);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	if (TotalTime >= 5) {
		Next.draw(window);
	}
}

StateSelectDifficulty::StateSelectDifficulty(StateManager& manager) : stateManager(manager) {
	// 构造方法
	/*
	负责人: 波波沙

	功能:
		初始化选择难度的场景
		1.文本
		2.按钮

	参数:
		StateManager& manager	//场景管理器

	返回值: StateSelectDifficulty
	*/
	//----------------------实现------------------------//

	//素材管理器
	AssetManager& assetManager = AssetManager::getInstance();

	// 设置难度按钮
	easyButton.setFont(assetManager.getFont("simhei"), sf::Color::White, L"简单", 25);
	easyButton.setColor(sf::Color::Black, sf::Color::White, sf::Color(100, 100, 100, 255));
	easyButton.setPosition(240, 500, 200, 50);

	hardButton.setFont(assetManager.getFont("simhei"), sf::Color::White, L"困难", 25);
	hardButton.setColor(sf::Color::Black, sf::Color::White, sf::Color(100, 100, 100, 255));
	hardButton.setPosition(540, 500, 200, 50);

	bossButton.setFont(assetManager.getFont("simhei"), sf::Color::White, L"进入Boos战", 25);
	bossButton.setColor(sf::Color::Black, sf::Color::White, sf::Color(100, 100, 100, 255));
	bossButton.setPosition(390, 600, 200, 50);

	EXButton.setFont(assetManager.getFont("simhei"), sf::Color::White, L"EX", 25);
	EXButton.setColor(sf::Color::Black, sf::Color::White, sf::Color(100, 100, 100, 255));
	EXButton.setPosition(390, 700, 200, 50);

	// 难度选择文本
	difficultyText.setFont(assetManager.getFont("simhei"));
	difficultyText.setFillColor(sf::Color::White);
	difficultyText.setCharacterSize(50);
	difficultyText.setString(L"请选择游戏难度");
	difficultyText.setPosition(310, 300);

	isEasyButton = false;
	ishardButton = false;
	isEXButton = false;
}

void StateSelectDifficulty::handleInput(sf::RenderWindow& window) {
	// 主要处理鼠标点击按钮
	/*
	负责人: 波波沙

	功能:
		初始化选择难度的场景
		根据不同的按钮选择初始化不同的游戏场景

	参数:
		sf::RenderWindow& window	//输入的事件从窗口获得

	返回值: void
	*/
	//----------------------实现------------------------//

	//召唤扛着音响的大哥
	AudioManager& audioManager = AudioManager::getInstance();

	//记事本大哥
	SettingsManager& settingsManager = settingsManager.getInstance();

	sf::Event event;
	while (window.pollEvent(event)) {
		//获取鼠标位置
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		if (event.type == sf::Event::Closed) {
			AudioManager::getInstance().playSound("Jumko_Exit");
			sf::sleep(sf::seconds(2));
			window.close();
		}

		// 检测难度和boss战按钮的点击
		if (event.type == sf::Event::MouseButtonPressed) {
			if (easyButton.isMouseOver(mousePosition)) {
				// 处理简单难度的选择
				audioManager.playSound("ClickButton");
				settingsManager.isHardCore = false;
				settingsManager.isBossCore = false;
				settingsManager.isEXHard = false;
				stateManager.changeState(stateManager.createState("NewGame"));
			}
			else if (hardButton.isMouseOver(mousePosition)) {
				// 处理困难难度的选择
				audioManager.playSound("ClickButton");
				settingsManager.isHardCore = true;
				settingsManager.isBossCore = false;
				settingsManager.isEXHard = false;
				stateManager.changeState(stateManager.createState("NewGame"));
			}
			else if (bossButton.isMouseOver(mousePosition) && ( settingsManager.unlockedCGs[10]|| settingsManager.unlockedCGs[11])) {
				audioManager.playSound("ClickButton");
				settingsManager.isHardCore = true;
				settingsManager.isBossCore = true;
				settingsManager.isEXHard = false;
				stateManager.changeState(stateManager.createState("NewGame"));
			}
			else if (EXButton.isMouseOver(mousePosition)) {
				// 处理EX难度的选择
				audioManager.playSound("ClickButton");
				settingsManager.isHardCore = false;
				settingsManager.isBossCore = false;
				settingsManager.isEXHard = true;
				stateManager.changeState(stateManager.createState("NewGame"));
			}
		}

		// 按钮悬停效果
		if (event.type == sf::Event::MouseMoved) {
			if (easyButton.isMouseOver(mousePosition)) {
				easyButton.onHover();
				if (!isEasyButton) {
					isEasyButton = true;
					audioManager.playSound("SelectButton");
				}
			}
			else {
				easyButton.resetColor();
				isEasyButton = false;
			}

			if (hardButton.isMouseOver(mousePosition)) {
				hardButton.onHover();
				if (!ishardButton) {
					ishardButton = true;
					audioManager.playSound("SelectButton");
				}
			}
			else {
				hardButton.resetColor();
				ishardButton = false;
			}

			//悬停boss战按钮
			if (bossButton.isMouseOver(mousePosition)) {
				bossButton.onHover();
				if (!isbossButton) {
					isbossButton = true;
					audioManager.playSound("SelectButton");
				}
			}
			else {
				bossButton.resetColor();
				isbossButton= false;
			}
			if (EXButton.isMouseOver(mousePosition)) {
				EXButton.onHover();
				if (!isEXButton) {
					isEXButton = true;
					audioManager.playSound("SelectButton");
				}
			}
			else {
				EXButton.resetColor();
				isEXButton = false;
			}
		}

	}
}

void StateSelectDifficulty::update(float deltaTime) {
	// 更新
	/*
	负责人: 波波沙

	功能:
		这个场景不需要更新

	参数:
		sf::RenderWindow& window	//输入的事件从窗口获得

	返回值: void
	*/
	//----------------------实现------------------------//
}

void StateSelectDifficulty::draw(sf::RenderWindow& window) {
	// 渲染 
	/*
	负责人: 波波沙

	功能:
		初始化选择难度的场景
		根据不同的按钮选择初始化不同的游戏场景

	参数:
		sf::RenderWindow& window	//输入的事件从窗口获得

	返回值: void
	*/
	//----------------------实现------------------------//
	window.draw(difficultyText);
	easyButton.draw(window);
	hardButton.draw(window);
	bossButton.draw(window);
	EXButton.draw(window);
}

#include <SFML/Graphics.hpp>
#include "StateGameplay.hpp"
#include "StateMenu.hpp"
extern bool isSelectHome;//在别的cpp文件中引用全局静态变量
bool isSelectBack = false;
bool isSelectNext = false;
StateGameplay::StateGameplay(StateManager& manager) : stateManager(manager) {
	//素材管理器单例
	AssetManager& assetmanager = AssetManager::getInstance();

	//返回主菜单按钮的信息
	home.setFont(assetmanager.getFont("SIMYOU"), sf::Color::White, L"返回", 30);
	home.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	home.setPosition(50, 50, 200, 50);

	//下一页按钮的信息
	Next.setFont(assetmanager.getFont("SIMYOU"), sf::Color::White, L"下一页", 30);
	Next.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Next.setPosition(490, 150, 90, 40);

	//上一页按钮的信息
	Back.setFont(assetmanager.getFont("SIMYOU"), sf::Color::White, L"上一页", 30);
	Back.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Back.setPosition(310, 150, 90, 40);

	//标题的相关信息
	title.setFont(assetmanager.getFont("simhei"));
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(70);
	title.setString(L"游戏玩法");
	title.setPosition(350, 50);

	//设置背景图片
	BackgroundImage.setTexture(assetmanager.getTexture("JumkoMenu"));

	//使图片变暗但仍然可见
	BackgroundImage.setColor(sf::Color(128, 128, 128, 255));

	//四张图片的布局和设计
	Introduction1.setTexture(assetmanager.getTexture("TextHowToPlay1"));
	Introduction1.setPosition(sf::Vector2f(0, 0));

}

// 处理用户输入
void StateGameplay::handleInput(sf::RenderWindow& window) {
	AudioManager& audioManager = AudioManager::getInstance();
	sf::Event event;
	while (window.pollEvent(event)) {
		//获取鼠标位置
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		//处理关闭界面
		if (event.type == sf::Event::Closed) {
			AudioManager::getInstance().playSound("Jumko_Exit");
			sf::sleep(sf::seconds(2));
			window.close();
		}
		//处理鼠标点击按钮事件
		if (event.type == sf::Event::MouseButtonPressed) {
			//返回主菜单按钮的响应
			if (home.isMouseOver(mousePosition)) {
				audioManager.playSound("ClickButton");
				stateManager.changeState(std::make_unique<StateMenu>(stateManager));
				//entityManager->clearAllEntities();
			}

			//下一页按钮的响应
			else if (Next.isMouseOver(mousePosition)) {
				audioManager.playSound("ClickButton");
				stateManager.changeState(stateManager.createState("StateGameplay2"));
			}
		}
		//处理鼠标移动到按钮变色
		if (event.type == sf::Event::MouseMoved) {
			// 返回的响应
			if (home.isMouseOver(mousePosition)) {
				home.onHover();
				if (!isSelectHome) {
					isSelectHome = true;
					audioManager.playSound("SelectButton");
				}
			}
			else {
				home.resetColor();
				isSelectHome = false;
			}

			//上一页的响应
			if (Back.isMouseOver(mousePosition)) {
				Back.onHover();
				if (!isSelectBack) {
					isSelectBack = true;
					audioManager.playSound("SelectButton");
				}
			}
			else {
				Back.resetColor();
				isSelectBack = false;
			}

			//下一页的响应
			if (Next.isMouseOver(mousePosition)) {
				Next.onHover();
				if (!isSelectNext) {
					isSelectNext = true;
					audioManager.playSound("SelectButton");
				}
			}
			else {
				Next.resetColor();
				isSelectNext = false;
			}
		}
	}
}
//对数据实时更新
void StateGameplay::update(float deltaTime) {
	//EntityManager::getInstance()->updateEntities(deltaTime);
}

//对渲染所有需要渲染的东西
void StateGameplay::draw(sf::RenderWindow& window) {
	//绘制背景
	window.draw(BackgroundImage);

	//绘制标题
	window.draw(title);

	//渲染四个介绍图片
	window.draw(Introduction1);

	//绘制按钮
	home.draw(window);
	Back.draw(window);
	Next.draw(window);
}





//--------------------------游戏玩法界面第二页-----------------------------


StateGameplay2::StateGameplay2(StateManager& manager) : stateManager(manager) {
	//素材管理器单例
	AssetManager& assetmanager = AssetManager::getInstance();

	//返回主菜单按钮的信息
	home.setFont(assetmanager.getFont("SIMYOU"), sf::Color::White, L"返回", 30);
	home.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	home.setPosition(50, 50, 200, 50);

	//下一页按钮的信息
	Next.setFont(assetmanager.getFont("SIMYOU"), sf::Color::White, L"下一页", 30);
	Next.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Next.setPosition(490, 150, 90, 40);

	//上一页按钮的信息
	Back.setFont(assetmanager.getFont("SIMYOU"), sf::Color::White, L"上一页", 30);
	Back.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Back.setPosition(310, 150, 90, 40);

	//标题的相关信息
	title.setFont(assetmanager.getFont("simhei"));
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(70);
	title.setString(L"游戏玩法");
	title.setPosition(350, 50);

	//设置背景图片
	BackgroundImage.setTexture(assetmanager.getTexture("JumkoMenu"));

	//使图片变暗但仍然可见
	BackgroundImage.setColor(sf::Color(128, 128, 128, 255));

	//四张图片的布局和设计
	// 测试用
	/*
	Introduction1.setTexture(assetmanager.getTexture("JumkoMenu"));
	Introduction1.setScale(500.0f / Introduction1.getLocalBounds().width, 500.0f / Introduction1.getLocalBounds().height);
	Introduction1.setPosition(400.0f, 400.0f);
	*/
	Introduction1.setTexture(assetmanager.getTexture("TextHowToPlay2"));
	Introduction1.setPosition(sf::Vector2f(0, 0));
}

// 处理用户输入
void StateGameplay2::handleInput(sf::RenderWindow& window) {
	AudioManager& audioManager = AudioManager::getInstance();
	sf::Event event;
	while (window.pollEvent(event)) {
		//获取鼠标位置
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		//处理关闭界面
		if (event.type == sf::Event::Closed) {
			AudioManager::getInstance().playSound("Jumko_Exit");
			sf::sleep(sf::seconds(2));
			window.close();
		}
		//处理鼠标点击按钮事件
		if (event.type == sf::Event::MouseButtonPressed) {
			//返回主菜单按钮的响应
			if (home.isMouseOver(mousePosition)) {
				audioManager.playSound("ClickButton");
				stateManager.changeState(std::make_unique<StateMenu>(stateManager));
				//entityManager->clearAllEntities();
			}

			//上一页按钮的响应
			else if (Back.isMouseOver(mousePosition)) {
				audioManager.playSound("ClickButton");
				stateManager.changeState(stateManager.createState("StateGameplay"));
			}

			//下一页按钮的响应 (如果需要第三页 那么就得加)

		}
		//处理鼠标移动到按钮变色
		if (event.type == sf::Event::MouseMoved) {
			// 返回的响应
			if (home.isMouseOver(mousePosition)) {
				home.onHover();
				if (!isSelectHome) {
					isSelectHome = true;
					audioManager.playSound("SelectButton");
				}
			}
			else {
				home.resetColor();
				isSelectHome = false;
			}

			//上一页的响应
			if (Back.isMouseOver(mousePosition)) {
				Back.onHover();
				if (!isSelectBack) {
					isSelectBack = true;
					audioManager.playSound("SelectButton");
				}
			}
			else {
				Back.resetColor();
				isSelectBack = false;
			}

			//下一页的响应
			if (Next.isMouseOver(mousePosition)) {
				Next.onHover();
				if (!isSelectNext) {
					isSelectNext = true;
					audioManager.playSound("SelectButton");
				}
			}
			else {
				Next.resetColor();
				isSelectNext = false;
			}
		}
	}
}
//对数据实时更新
void StateGameplay2::update(float deltaTime) {
	//EntityManager::getInstance()->updateEntities(deltaTime);
}

//对渲染所有需要渲染的东西
void StateGameplay2::draw(sf::RenderWindow& window) {
	//绘制背景
	window.draw(BackgroundImage);

	//绘制标题
	window.draw(title);

	//渲染四个介绍图片

	window.draw(Introduction1);

	//绘制按钮
	home.draw(window);
	Back.draw(window);
	Next.draw(window);
}

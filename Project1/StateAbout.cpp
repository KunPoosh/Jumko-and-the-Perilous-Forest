#include <SFML/Graphics.hpp>
#include "StateAbout.hpp"
#include "StateMenu.hpp"
#include "AudioManager.hpp"
bool isSelectHome = false;
bool isSlectLink = false;
StateAbout::StateAbout(StateManager& manager) : stateManager(manager) {
	//素材管理器单例
	AssetManager& assetmanager = AssetManager::getInstance();

	//按钮的相关信息
	home.setFont(assetmanager.getFont("SIMYOU"), sf::Color::White, L"返回", 30);
	home.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	home.setPosition(50, 50, 200, 50);

	//标题的相关信息
	title.setFont(assetmanager.getFont("simhei"));
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(70);
	title.setString(L"关于");
	title.setPosition(400, 50);

	//设置背景图片
	BackgroundImage.setTexture(assetmanager.getTexture("JumkoMenu"));

	//使图片变暗但仍然可见
	BackgroundImage.setColor(sf::Color(128, 128, 128, 255));

	//设置关于人员图片
	About.setTexture(assetmanager.getTexture("TextAbout"));//从assetmanager中索取图片
	About.setPosition(sf::Vector2f(0, 0));

	//设置我的项目按钮
	visitLink.setFont(assetmanager.getFont("simhei"));
	visitLink.setFillColor(sf::Color::White);
	visitLink.setCharacterSize(30);
	visitLink.setString(L"我的项目");
	visitLink.setPosition(160, 900);

} 

//------------功能---------------
// //用于存入显示的关于内容

void StateAbout::handleInput(sf::RenderWindow& window) {
	AudioManager& audioManager = AudioManager::getInstance();
	sf::Event event;
	while (window.pollEvent(event)) {
		//获取鼠标位置
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		//处理关闭界面
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		//处理鼠标点击按钮事件
		if (event.type == sf::Event::MouseButtonPressed) {
			if (home.isMouseOver(mousePosition)) {
				stateManager.changeState(std::make_unique<StateMenu>(stateManager));
				audioManager.playSound("ClickButton");

				//entityManager->clearAllEntities();
			}
		}
		//处理鼠标移动到按钮变色
		if (event.type == sf::Event::MouseMoved) {
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
		}
		//处理鼠标点击我的项目事件
		if (event.type == sf::Event::MouseButtonPressed) {
			if (home.isMouseOver(mousePosition)) {
				stateManager.changeState(std::make_unique<StateMenu>(stateManager));
				audioManager.playSound("ClickButton");
			}
			else if (visitLink.getGlobalBounds().contains(mousePosition)) {
				system("start https://github.com/KunPoosh/Jumko-and-the-Perilous-Forest");
			}
		}
	}
}

void StateAbout::update(float deltaTime) {
	//EntityManager::getInstance()->updateEntities(deltaTime);
}

void StateAbout::draw(sf::RenderWindow& window) {
	AssetManager& assetmanager = AssetManager::getInstance();
	//绘制背景
	window.draw(BackgroundImage);
	//绘制标题
	window.draw(title);
	//绘制关于人员
	window.draw(About);

	//绘制按钮
	home.draw(window);

	window.draw(visitLink);
}
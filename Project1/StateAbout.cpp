#include <SFML/Graphics.hpp>
#include "StateAbout.hpp"
#include "StateMenu.hpp"
#include "AudioManager.hpp"
bool isSelectHome = false;
bool isSlectLink = false;
StateAbout::StateAbout(StateManager& manager) : stateManager(manager) {
	//�زĹ���������
	AssetManager& assetmanager = AssetManager::getInstance();

	//��ť�������Ϣ
	home.setFont(assetmanager.getFont("SIMYOU"), sf::Color::White, L"����", 30);
	home.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	home.setPosition(50, 50, 200, 50);

	//����������Ϣ
	title.setFont(assetmanager.getFont("simhei"));
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(70);
	title.setString(L"����");
	title.setPosition(400, 50);

	//���ñ���ͼƬ
	BackgroundImage.setTexture(assetmanager.getTexture("JumkoMenu"));

	//ʹͼƬ�䰵����Ȼ�ɼ�
	BackgroundImage.setColor(sf::Color(128, 128, 128, 255));

	//���ù�����ԱͼƬ
	About.setTexture(assetmanager.getTexture("TextAbout"));//��assetmanager����ȡͼƬ
	About.setPosition(sf::Vector2f(0, 0));

	//�����ҵ���Ŀ��ť
	visitLink.setFont(assetmanager.getFont("simhei"));
	visitLink.setFillColor(sf::Color::White);
	visitLink.setCharacterSize(30);
	visitLink.setString(L"�ҵ���Ŀ");
	visitLink.setPosition(160, 900);

	

} 

//------------����---------------
// //���ڴ�����ʾ�Ĺ�������

void StateAbout::handleInput(sf::RenderWindow& window) {
	AudioManager& audioManager = AudioManager::getInstance();
	sf::Event event;
	while (window.pollEvent(event)) {
		//��ȡ���λ��
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		//����رս���
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		//�����������ť�¼�
		if (event.type == sf::Event::MouseButtonPressed) {
			if (home.isMouseOver(mousePosition)) {
				stateManager.changeState(std::make_unique<StateMenu>(stateManager));
				audioManager.playSound("ClickButton");

				//entityManager->clearAllEntities();
			}
		}
		//��������ƶ�����ť��ɫ
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
		//����������ҵ���Ŀ�¼�
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
	//���Ʊ���
	window.draw(BackgroundImage);
	//���Ʊ���
	window.draw(title);
	//���ƹ�����Ա
	window.draw(About);

	//���ư�ť
	home.draw(window);

	window.draw(visitLink);
}
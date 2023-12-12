#include <SFML/Graphics.hpp>
#include "StateGameplay.hpp"
#include "StateMenu.hpp"
extern bool isSelectHome;//�ڱ��cpp�ļ�������ȫ�־�̬����
bool isSelectBack = false;
bool isSelectNext = false;
StateGameplay::StateGameplay(StateManager& manager) : stateManager(manager) {
	//�زĹ���������
	AssetManager& assetmanager = AssetManager::getInstance();

	//�������˵���ť����Ϣ
	home.setFont(assetmanager.getFont("SIMYOU"), sf::Color::White, L"����", 30);
	home.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	home.setPosition(50, 50, 200, 50);

	//��һҳ��ť����Ϣ
	Next.setFont(assetmanager.getFont("SIMYOU"), sf::Color::White, L"��һҳ", 30);
	Next.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Next.setPosition(490, 150, 90, 40);

	//��һҳ��ť����Ϣ
	Back.setFont(assetmanager.getFont("SIMYOU"), sf::Color::White, L"��һҳ", 30);
	Back.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Back.setPosition(310, 150, 90, 40);

	//����������Ϣ
	title.setFont(assetmanager.getFont("simhei"));
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(70);
	title.setString(L"��Ϸ�淨");
	title.setPosition(350, 50);

	//���ñ���ͼƬ
	BackgroundImage.setTexture(assetmanager.getTexture("JumkoMenu"));

	//ʹͼƬ�䰵����Ȼ�ɼ�
	BackgroundImage.setColor(sf::Color(128, 128, 128, 255));

	//����ͼƬ�Ĳ��ֺ����
	Introduction1.setTexture(assetmanager.getTexture("TextHowToPlay1"));
	Introduction1.setPosition(sf::Vector2f(0, 0));

}

// �����û�����
void StateGameplay::handleInput(sf::RenderWindow& window) {
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
			//�������˵���ť����Ӧ
			if (home.isMouseOver(mousePosition)) {
				audioManager.playSound("ClickButton");
				stateManager.changeState(std::make_unique<StateMenu>(stateManager));
				//entityManager->clearAllEntities();
			}

			//��һҳ��ť����Ӧ
			else if (Next.isMouseOver(mousePosition)) {
				audioManager.playSound("ClickButton");
				stateManager.changeState(stateManager.createState("StateGameplay2"));
			}
		}
		//��������ƶ�����ť��ɫ
		if (event.type == sf::Event::MouseMoved) {
			// ���ص���Ӧ
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

			//��һҳ����Ӧ
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

			//��һҳ����Ӧ
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
//������ʵʱ����
void StateGameplay::update(float deltaTime) {
	//EntityManager::getInstance()->updateEntities(deltaTime);
}

//����Ⱦ������Ҫ��Ⱦ�Ķ���
void StateGameplay::draw(sf::RenderWindow& window) {
	//���Ʊ���
	window.draw(BackgroundImage);

	//���Ʊ���
	window.draw(title);

	//��Ⱦ�ĸ�����ͼƬ
	window.draw(Introduction1);

	//���ư�ť
	home.draw(window);
	Back.draw(window);
	Next.draw(window);
}





//--------------------------��Ϸ�淨����ڶ�ҳ-----------------------------


StateGameplay2::StateGameplay2(StateManager& manager) : stateManager(manager) {
	//�زĹ���������
	AssetManager& assetmanager = AssetManager::getInstance();

	//�������˵���ť����Ϣ
	home.setFont(assetmanager.getFont("SIMYOU"), sf::Color::White, L"����", 30);
	home.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	home.setPosition(50, 50, 200, 50);

	//��һҳ��ť����Ϣ
	Next.setFont(assetmanager.getFont("SIMYOU"), sf::Color::White, L"��һҳ", 30);
	Next.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Next.setPosition(490, 150, 90, 40);

	//��һҳ��ť����Ϣ
	Back.setFont(assetmanager.getFont("SIMYOU"), sf::Color::White, L"��һҳ", 30);
	Back.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Back.setPosition(310, 150, 90, 40);

	//����������Ϣ
	title.setFont(assetmanager.getFont("simhei"));
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(70);
	title.setString(L"��Ϸ�淨");
	title.setPosition(350, 50);

	//���ñ���ͼƬ
	BackgroundImage.setTexture(assetmanager.getTexture("JumkoMenu"));

	//ʹͼƬ�䰵����Ȼ�ɼ�
	BackgroundImage.setColor(sf::Color(128, 128, 128, 255));

	//����ͼƬ�Ĳ��ֺ����
	// ������
	/*
	Introduction1.setTexture(assetmanager.getTexture("JumkoMenu"));
	Introduction1.setScale(500.0f / Introduction1.getLocalBounds().width, 500.0f / Introduction1.getLocalBounds().height);
	Introduction1.setPosition(400.0f, 400.0f);
	*/
	Introduction1.setTexture(assetmanager.getTexture("TextHowToPlay2"));
	Introduction1.setPosition(sf::Vector2f(0, 0));
}

// �����û�����
void StateGameplay2::handleInput(sf::RenderWindow& window) {
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
			//�������˵���ť����Ӧ
			if (home.isMouseOver(mousePosition)) {
				audioManager.playSound("ClickButton");
				stateManager.changeState(std::make_unique<StateMenu>(stateManager));
				//entityManager->clearAllEntities();
			}

			//��һҳ��ť����Ӧ
			else if (Back.isMouseOver(mousePosition)) {
				audioManager.playSound("ClickButton");
				stateManager.changeState(stateManager.createState("StateGameplay"));
			}

			//��һҳ��ť����Ӧ (�����Ҫ����ҳ ��ô�͵ü�)

		}
		//��������ƶ�����ť��ɫ
		if (event.type == sf::Event::MouseMoved) {
			// ���ص���Ӧ
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

			//��һҳ����Ӧ
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

			//��һҳ����Ӧ
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
//������ʵʱ����
void StateGameplay2::update(float deltaTime) {
	//EntityManager::getInstance()->updateEntities(deltaTime);
}

//����Ⱦ������Ҫ��Ⱦ�Ķ���
void StateGameplay2::draw(sf::RenderWindow& window) {
	//���Ʊ���
	window.draw(BackgroundImage);

	//���Ʊ���
	window.draw(title);

	//��Ⱦ�ĸ�����ͼƬ

	window.draw(Introduction1);

	//���ư�ť
	home.draw(window);
	Back.draw(window);
	Next.draw(window);
}

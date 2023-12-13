#include "StateStarGame.hpp"

StateStartGame::StateStartGame(StateManager& manager) : stateManager(manager) {
	//���췽��
	/*
	������: ����ɳ

	����:
		��ʼ����ʼ����
			1.������ť
			2.����ͼƬ
			3.��������
			4.��ʼ��ʱ

	����:
		StateManager& manager   //�������������������������еĳ���������ָ���ϡ�

	����ֵ: StateStartGame
	*/
	//----------------------ʵ��------------------------//

	//�زĹ���������
	AssetManager& assetManager = AssetManager::getInstance();

	//����"����"��ť��λ�õ���Ϣ��
	Next.setFont(assetManager.getFont("simhei"), sf::Color::White, L">��һ��", 25);
	Next.setColor(sf::Color(200, 200, 200, 0), sf::Color(100, 100, 100, 0), sf::Color(255, 255, 255, 100));
	Next.setPosition(700, 850, 200, 50);

	//ͼƬ����
	Pic1.setTexture(assetManager.getTexture("StartPic"));
	Pic1.setPosition(320,200);

	//�ı�����,���ֶ�����������
	text1.setFont(assetManager.getFont("simhei"));
	text1.setFillColor(sf::Color::White);
	text1.setCharacterSize(30);
	text1.setString(L"���ɴ�С��������Ĵ��˽�������Ƭ��Σ��֮ɭ���ġ�������");
	text1.setPosition(90, 400);

	text2.setFont(assetManager.getFont("simhei"));
	text2.setFillColor(sf::Color::White);
	text2.setCharacterSize(30);
	text2.setString(L"���Ǵӽ��ɿ����ְֽ���Σ��֮ɭ�Ѿ���ȥ������");
	text2.setPosition(170, 450);

	text3.setFont(assetManager.getFont("simhei"));
	text3.setFillColor(sf::Color::White);
	text3.setCharacterSize(30);
	text3.setString(L"���콴�����ھ��Ľ���Σ��֮ɭ");
	text3.setPosition(250, 500);

	text4.setFont(assetManager.getFont("simhei"));
	text4.setFillColor(sf::Color::White);
	text4.setCharacterSize(30);
	text4.setString(L"Ѱ�Ұְֵ��ټ�......");
	text4.setPosition(350, 550);





	//ʱ������
	TotalTime = 0.f;

	//3�뽥��
	animationDuration = 3.f;
}

void StateStartGame::handleInput(sf::RenderWindow& window) {
	//����������¼�
	/*
	������: ����ɳ

	����:
		��ȡ�û����룬����ť

	����:
		sf::RenderWindow& window   //�Ӵ��ڻ���¼�

	����ֵ: void
	*/
	//----------------------ʵ��------------------------//

	//�¼�
	sf::Event event;
	while (window.pollEvent(event))
	{
		//������ر�ʱ�رմ���
		if (event.type == sf::Event::Closed) {
			window.close();
		}

		//�����һ����ť
		if (event.type == sf::Event::MouseButtonPressed) {
			if (this->Next.isMouseOver(window)) {
				stateManager.changeState(stateManager.createState("StateSelectDifficulty"));
			}
		}
		//��ͣ�ڰ�ť����
		if (event.type == sf::Event::MouseMoved) {
			if (Next.isMouseOver(window)) {
				Next.onHover();
			}
			else {
				Next.resetColor();
			}
		}
	}

}

void StateStartGame::update(float deltaTime) {
	//�����߼�
	/*
	������: ����ɳ

	����:
		����ͼƬ�����֣�ʵ�ֽ�����Ч��

	����:
		float deltaTime		//ȫ�ּ��ʱ��

	����ֵ: void
	*/
	//----------------------ʵ��------------------------//

	TotalTime += deltaTime;

	float progress = std::min(TotalTime / animationDuration, 1.0f);
	Pic1.setColor(sf::Color(255, 255, 255, 255 * progress));
	text1.setFillColor(sf::Color(255, 255, 255, 255 * progress));
	text2.setFillColor(sf::Color(255, 255, 255, 255 * progress));
	text3.setFillColor(sf::Color(255, 255, 255, 255 * progress));
	text4.setFillColor(sf::Color(255, 255, 255, 255 * progress));
}

void StateStartGame::draw(sf::RenderWindow& window) {
	//��Ⱦ
	/*
	������: ����ɳ

	����:
		��Ⱦ������ڸ���Ⱦ�Ķ���

	����:
		sf::RenderWindow& window		//��Ҫ��Ⱦ���ĵط�

	����ֵ: void
	*/
	//----------------------ʵ��------------------------//

	window.draw(Pic1);
	window.draw(text1);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	if (TotalTime >= 1) {
		Next.draw(window);
	}
}

StateSelectDifficulty::StateSelectDifficulty(StateManager& manager) : stateManager(manager) {
	// ���췽��
	/*
	������: ����ɳ

	����:
		��ʼ��ѡ���Ѷȵĳ���
		1.�ı�
		2.��ť

	����:
		StateManager& manager	//����������

	����ֵ: StateSelectDifficulty
	*/
	//----------------------ʵ��------------------------//

	//�زĹ�����
	AssetManager& assetManager = AssetManager::getInstance();

	// �����ѶȰ�ť
	easyButton.setFont(assetManager.getFont("simhei"), sf::Color::White, L"��", 25);
	easyButton.setColor(sf::Color::Black, sf::Color::White, sf::Color(100, 100, 100, 255));
	easyButton.setPosition(240, 500, 200, 50);

	hardButton.setFont(assetManager.getFont("simhei"), sf::Color::White, L"����", 25);
	hardButton.setColor(sf::Color::Black, sf::Color::White, sf::Color(100, 100, 100, 255));
	hardButton.setPosition(540, 500, 200, 50);

	EXButton.setFont(assetManager.getFont("simhei"), sf::Color::White, L"EXģʽ", 25);
	EXButton.setColor(sf::Color::Black, sf::Color::White, sf::Color(100, 100, 100, 255));
	EXButton.setPosition(390, 600, 200, 50);

	// �Ѷ�ѡ���ı�
	difficultyText.setFont(assetManager.getFont("simhei"));
	difficultyText.setFillColor(sf::Color::White);
	difficultyText.setCharacterSize(50);
	difficultyText.setString(L"��ѡ����Ϸ�Ѷ�");
	difficultyText.setPosition(310, 300);

	isEasyButton = false;
	ishardButton = false;
	isEXButton = false;
}

void StateSelectDifficulty::handleInput(sf::RenderWindow& window) {
	// ��Ҫ�����������ť
	/*
	������: ����ɳ

	����:
		��ʼ��ѡ���Ѷȵĳ���
		���ݲ�ͬ�İ�ťѡ���ʼ����ͬ����Ϸ����

	����:
		sf::RenderWindow& window	//������¼��Ӵ��ڻ��

	����ֵ: void
	*/
	//----------------------ʵ��------------------------//

	//�ٻ���������Ĵ��
	AudioManager& audioManager = AudioManager::getInstance();

	//���±����
	SettingsManager& settingsManager = settingsManager.getInstance();

	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}

		// ����ѶȰ�ť�ĵ��
		if (event.type == sf::Event::MouseButtonPressed) {
			if (easyButton.isMouseOver(window)) {
				// ������Ѷȵ�ѡ��
				audioManager.playSound("ClickButton");
				settingsManager.isHardCore = false;
				settingsManager.isEXHard = false;
				stateManager.changeState(stateManager.createState("NewGame"));
			}
			else if (hardButton.isMouseOver(window)) {
				// ���������Ѷȵ�ѡ��
				audioManager.playSound("ClickButton");
				settingsManager.isHardCore = true;
				settingsManager.isEXHard = false;
				stateManager.changeState(stateManager.createState("NewGame"));
			}
			else if (EXButton.isMouseOver(window)) {
				// ����EX�Ѷȵ�ѡ��
				audioManager.playSound("ClickButton");
				settingsManager.isEXHard = true;
				stateManager.changeState(stateManager.createState("NewGame"));
			}
		}

		// ��ť��ͣЧ��
		if (event.type == sf::Event::MouseMoved) {
			if (easyButton.isMouseOver(window)) {
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

			if (hardButton.isMouseOver(window)) {
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

			if (EXButton.isMouseOver(window)) {
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
	// ����
	/*
	������: ����ɳ

	����:
		�����������Ҫ����

	����:
		sf::RenderWindow& window	//������¼��Ӵ��ڻ��

	����ֵ: void
	*/
	//----------------------ʵ��------------------------//
}

void StateSelectDifficulty::draw(sf::RenderWindow& window) {
	// ��Ⱦ 
	/*
	������: ����ɳ

	����:
		��ʼ��ѡ���Ѷȵĳ���
		���ݲ�ͬ�İ�ťѡ���ʼ����ͬ����Ϸ����

	����:
		sf::RenderWindow& window	//������¼��Ӵ��ڻ��

	����ֵ: void
	*/
	//----------------------ʵ��------------------------//
	window.draw(difficultyText);
	easyButton.draw(window);
	hardButton.draw(window);
	EXButton.draw(window);
}

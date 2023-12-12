#include"StateAppreciate.hpp"
#include"StateMenu.hpp"

//��ʼ����̬��Ա
int StateAppreciate::SelectImage = -1;
int StateAppreciate2::SelectImage2 = -1;
//���캯������ʼ������
StateAppreciate::StateAppreciate(StateManager& manager) :stateManager(manager)
{
	//��ȡ�زĹ������ĵ���
	AssetManager& assetManager = AssetManager::getInstance();

	//���á����ء���ť
	home.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"����", 30);
	home.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	home.setPosition(50, 50, 200, 50);
	//������һҳ��ť
	Next.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"��һҳ", 30);
	Next.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Next.setPosition(490, 150, 90, 40);
	//������һҳ��ť
	Prior.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"��һҳ", 30);
	Prior.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Prior.setPosition(310, 150, 90, 40);
	//���ñ���ͼƬ
	BackgroundImage.setTexture(assetManager.getTexture("JumkoMenu"));
	// ʹͼƬ�䰵����Ȼ�ɼ�
	BackgroundImage.setColor(sf::Color(128, 128, 128, 255));

	//��ʼ������
	title.setFont(assetManager.getFont("simhei"));
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(70);
	title.setString("Appreciate");
	title.setPosition(350, 50);

	//���þ���Բ�ǿ��С
	roundedRect1.setSize(sf::Vector2f(300, 200));
	roundedRect2.setSize(sf::Vector2f(300, 200));
	roundedRect3.setSize(sf::Vector2f(300, 200));
	roundedRect4.setSize(sf::Vector2f(300, 200));
	roundedRect5.setSize(sf::Vector2f(300, 200));
	roundedRect6.setSize(sf::Vector2f(300, 200));
	//���þ���Բ�ǿ���ɫ
	roundedRect1.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect2.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect3.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect4.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect5.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect6.setFillColor(sf::Color(200, 200, 200, 150));
	//���þ���Բ�ǿ�λ��
	roundedRect1.setPosition(100, 200);
	roundedRect2.setPosition(490, 200);
	roundedRect3.setPosition(100, 450);
	roundedRect4.setPosition(490, 450);
	roundedRect5.setPosition(100, 700);
	roundedRect6.setPosition(490, 700);
	// ����ÿ��Բ�Ǿ��ο�ı߿���ɫ
	roundedRect1.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect2.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect3.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect4.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect5.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect6.setOutlineColor(sf::Color(200, 200, 200, 150));
	// ����ÿ��Բ�Ǿ��ο�ı߿���
	roundedRect1.setOutlineThickness(1);
	roundedRect2.setOutlineThickness(1);
	roundedRect3.setOutlineThickness(1);
	roundedRect4.setOutlineThickness(1);
	roundedRect5.setOutlineThickness(1);
	roundedRect6.setOutlineThickness(1);
	//���þ���
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
	//����CG����ͼ
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
	//������Ƶ���ŵ���
	AudioManager& audioManager = AudioManager::getInstance();
	//�����ļ�������
	SettingsManager& settingsManager = SettingsManager::getInstance();
	while (window.pollEvent(event))
	{
		//��ȡ���λ��
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
		//������ر�ʱ�رմ���
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		// ... ����ť����¼���ʹ��stateManager.changeState(...)
		if (event.type == sf::Event::MouseButtonPressed) {
			//��ȡ���λ��
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (this->home.isMouseOver(mousePosition)) {
				this->stateManager.changeState(std::make_unique<StateMenu>(stateManager));
				audioManager.playSound("ClickButton");
			}
			/*�����һҳ��ť*/
			else if (this->Next.isMouseOver(mousePosition))
			{
				this->stateManager.changeState(stateManager.createState("Appreciate2"));
				audioManager.playSound("ClickButton");
			}
			//�������һ��ͼƬ
			else if (sprite1.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				//01������򿪵�һ��ͼƬ
				if (settingsManager.unlockedCGs[0] == 1)
				{
					SelectImage = 1;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate"));
				}
			}
			//������ڶ���ͼƬ
			else if (sprite2.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[1] == 1)
				{
					SelectImage = 2;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate"));
				}
			}
			//�����������ͼƬ
			else if (sprite3.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[2] == 1)
				{
					SelectImage = 3;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate"));
				}
			}
			//�����������ͼƬ
			else if (sprite4.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[3] == 1)
				{
					SelectImage = 4;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate"));
				}
			}
			//�����������ͼƬ
			else if (sprite5.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[4] == 1)
				{
					SelectImage = 5;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate"));
				}
			}
			//�����������ͼƬ
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
				//����겻����ͣ�ڰ�ť��ʱ�ָ�ԭʼ��ɫ
				home.resetColor();
				Next.resetColor();
			}
		}
	}
}

void StateAppreciate::update(float deltaTime) {

}
void StateAppreciate::draw(sf::RenderWindow& window) {
	//������Ⱦ����ͼƬ
	window.draw(BackgroundImage);
	//�����ļ�������
	SettingsManager& settingsManager = SettingsManager::getInstance();
	// ... ���ư�ť
	this->home.draw(window);
	this->Next.draw(window);
	this->Prior.draw(window);
	//��������
	window.draw(this->title);

	//���ƾ���Բ�ǿ�
	window.draw(roundedRect1);
	window.draw(roundedRect2);
	window.draw(roundedRect3);
	window.draw(roundedRect4);
	window.draw(roundedRect5);
	window.draw(roundedRect6);
	//����ͼƬ
	window.draw(sprite1);
	window.draw(sprite2);
	window.draw(sprite3);
	window.draw(sprite4);
	window.draw(sprite5);
	window.draw(sprite6);
	//����CG����ͼ
	//���01�����ϣ���Ҫ����
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
//���ͽ���2
StateAppreciate2::StateAppreciate2(StateManager& manager) :stateManager(manager)
{
	//��ȡ�زĹ������ĵ���
	AssetManager& assetManager = AssetManager::getInstance();

	//������һҳ��ť
	Next.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"��һҳ", 30);
	Next.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Next.setPosition(490, 150, 90, 40);
	//������һҳ��ť
	Prior.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"��һҳ", 30);
	Prior.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Prior.setPosition(310, 150, 90, 40);
	//���ñ���ͼƬ
	BackgroundImage.setTexture(assetManager.getTexture("JumkoMenu"));
	// ʹͼƬ�䰵����Ȼ�ɼ�
	BackgroundImage.setColor(sf::Color(128, 128, 128, 255));

	//��ʼ������
	title.setFont(assetManager.getFont("simhei"));
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(70);
	title.setString("Appreciate");
	title.setPosition(350, 50);

	//���þ���Բ�ǿ��С
	roundedRect7.setSize(sf::Vector2f(300, 200));
	roundedRect8.setSize(sf::Vector2f(300, 200));
	roundedRect9.setSize(sf::Vector2f(300, 200));
	roundedRect10.setSize(sf::Vector2f(300, 200));
	roundedRect11.setSize(sf::Vector2f(300, 200));
	roundedRect12.setSize(sf::Vector2f(300, 200));
	//���þ���Բ�ǿ���ɫ
	roundedRect7.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect8.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect9.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect10.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect11.setFillColor(sf::Color(200, 200, 200, 150));
	roundedRect12.setFillColor(sf::Color(200, 200, 200, 150));
	//���þ���Բ�ǿ�λ��
	roundedRect7.setPosition(100, 200);
	roundedRect8.setPosition(490, 200);
	roundedRect9.setPosition(100, 450);
	roundedRect10.setPosition(490, 450);
	roundedRect11.setPosition(100, 700);
	roundedRect12.setPosition(490, 700);
	// ����ÿ��Բ�Ǿ��ο�ı߿���ɫ
	roundedRect7.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect8.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect9.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect10.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect11.setOutlineColor(sf::Color(200, 200, 200, 150));
	roundedRect12.setOutlineColor(sf::Color(200, 200, 200, 150));
	// ����ÿ��Բ�Ǿ��ο�ı߿���
	roundedRect7.setOutlineThickness(1);
	roundedRect8.setOutlineThickness(1);
	roundedRect9.setOutlineThickness(1);
	roundedRect10.setOutlineThickness(1);
	roundedRect11.setOutlineThickness(1);
	roundedRect12.setOutlineThickness(1);

	//����ͼƬ����
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

	//����CG����ͼ
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
	//������Ƶ���ŵ���
	AudioManager& audioManager = AudioManager::getInstance();
	//�����ļ�������
	SettingsManager& settingsManager = SettingsManager::getInstance();
	while (window.pollEvent(event))
	{
		//��ȡ���λ��
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		//������ر�ʱ�رմ���
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		// ... ����ť����¼���ʹ��stateManager.changeState(...)
		if (event.type == sf::Event::MouseButtonPressed) {
			//��ȡ���λ��
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);

			//�����һҳ��ť
			if (this->Prior.isMouseOver(mousePosition))
			{
				this->stateManager.changeState(stateManager.createState("Appreciate"));
				audioManager.playSound("ClickButton");
			}
			//�����������ͼƬ
			else if (sprite7.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				//01������򿪵�����ͼƬ
				if (settingsManager.unlockedCGs[6] == 1)
				{
					SelectImage2 = 7;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate2"));
				}
			}
			//������ڰ���ͼƬ
			else if (sprite8.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[7] == 1)
				{
					SelectImage2 = 8;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate2"));
				}
			}
			//������ھ���ͼƬ
			else if (sprite9.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[8] == 1)
				{
					SelectImage2 = 9;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate2"));
				}
			}
			//�������ʮ��ͼƬ
			else if (sprite10.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[9] == 1)
				{
					SelectImage2 = 10;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate2"));
				}
			}
			//�������ʮһ��ͼƬ
			else if (sprite11.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				if (settingsManager.unlockedCGs[10] == 1)
				{
					SelectImage2 = 11;
					this->stateManager.changeState(stateManager.createState("MagnifyAppreciate2"));
				}
			}
			//�������ʮ����ͼƬ
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
				//����겻����ͣ�ڰ�ť��ʱ�ָ�ԭʼ��ɫ
				Prior.resetColor();
			}
		}
	}
}
void StateAppreciate2::update(float deltaTime) {

}
void StateAppreciate2::draw(sf::RenderWindow& window) {
	//��ȡ�ļ�������
	SettingsManager& settingsManager = SettingsManager::getInstance();
	//������Ⱦ����ͼƬ
	window.draw(BackgroundImage);
	// ... ���ư�ť
	this->Next.draw(window);
	this->Prior.draw(window);
	//��������
	window.draw(this->title);
	//���ƾ���Բ�ǿ�
	window.draw(roundedRect7);
	window.draw(roundedRect8);
	window.draw(roundedRect9);
	window.draw(roundedRect10);
	window.draw(roundedRect11);
	window.draw(roundedRect12);
	//����ͼƬ
	window.draw(sprite7);
	window.draw(sprite8);
	window.draw(sprite9);
	window.draw(sprite10);
	window.draw(sprite11);
	window.draw(sprite12);
	//���01�����ϣ���Ҫ����
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
//����Ҫ��ʼ����ʱ��д��Appreciate(manager)����������Appreciateû�е���Ĭ�Ϲ��캯���Ĵ���
MagnifyAppreciate::MagnifyAppreciate(StateManager& manager) : StateAppreciate(manager), stateManager(manager)
{

	//��ȡ�زĹ������ĵ���
	AssetManager& assetManager = AssetManager::getInstance();

	//���á����ء���ť
	home.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"����", 30);
	home.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	home.setPosition(50, 50, 200, 50);

	if (StateAppreciate::SelectImage == 1)
	{
		//���þ���1�������䵱����ͼ
		sprite1.setTexture(assetManager.getTexture("WEIMEI1"));
		sprite1.setScale(960.0f / assetManager.getTexture("WEIMEI1").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
		sprite1.setPosition(0, 0);
	}
	else if (StateAppreciate::SelectImage == 2)
	{
		//���þ���2�������䵱����ͼ
		sprite2.setTexture(assetManager.getTexture("WEIMEI2"));
		sprite2.setScale(960.0f / assetManager.getTexture("WEIMEI2").getSize().x, 960.0f / assetManager.getTexture("WEIMEI2").getSize().y);
		sprite2.setPosition(0, 0);
	}
	else if (StateAppreciate::SelectImage == 3)
	{
		//���þ���3�������䵱����ͼ
		sprite3.setTexture(assetManager.getTexture("WEIMEI3"));
		sprite3.setScale(960.0f / assetManager.getTexture("WEIMEI3").getSize().x, 960.0f / assetManager.getTexture("WEIMEI3").getSize().y);
		sprite3.setPosition(0, 0);
	}
	else if (StateAppreciate::SelectImage == 4)
	{
		//���þ���4�������䵱����ͼ
		sprite4.setTexture(assetManager.getTexture("WEIMEI4"));
		sprite4.setScale(960.0f / assetManager.getTexture("WEIMEI4").getSize().x, 960.0f / assetManager.getTexture("WEIMEI4").getSize().y);
		sprite4.setPosition(0, 0);
	}
	else if (StateAppreciate::SelectImage == 5)
	{
		//���þ���5�������䵱����ͼ
		sprite5.setTexture(assetManager.getTexture("WEIMEI5"));
		sprite5.setScale(960.0f / assetManager.getTexture("WEIMEI5").getSize().x, 960.0f / assetManager.getTexture("WEIMEI4").getSize().y);
		sprite5.setPosition(0, 0);
	}
	else if (StateAppreciate::SelectImage == 6)
	{
		//���þ���6�������䵱����ͼ
		sprite6.setTexture(assetManager.getTexture("WEIMEI6"));
		sprite6.setScale(960.0f / assetManager.getTexture("WEIMEI6").getSize().x, 960.0f / assetManager.getTexture("WEIMEI4").getSize().y);
		sprite6.setPosition(0, 0);
	}
}

//����������¼���δ��ɣ�
void MagnifyAppreciate::handleInput(sf::RenderWindow& window)
{
	sf::Event event;
	//������Ƶ���ŵ���
	AudioManager& audioManager = AudioManager::getInstance();
	while (window.pollEvent(event))
	{
		//��ȡ���λ��
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		//������ر�ʱ�رմ���
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		// ... ����ť����¼���ʹ��stateManager.changeState(...)
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
				//����겻����ͣ�ڰ�ť��ʱ�ָ�ԭʼ��ɫ
				home.resetColor();
			}
		}
	}
}

void MagnifyAppreciate::update(float deltaTime)
{

}

//��Ⱦ��δ��ɣ�
void MagnifyAppreciate::draw(sf::RenderWindow& window)
{
	//����ѡ��ֵ��ȷ�����Ƶ�ͼƬ
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
	// ... ���ư�ť
	this->home.draw(window);
}

//-------------------------------------------
MagnifyAppreciate2::MagnifyAppreciate2(StateManager& manager) :StateAppreciate2(manager), stateManager(manager) {
	//��ȡ�زĹ������ĵ���
	AssetManager& assetManager = AssetManager::getInstance();

	//���á����ء���ť
	home.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"����", 30);
	home.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	home.setPosition(50, 50, 200, 50);

	if (StateAppreciate2::SelectImage2 == 7)
	{
		//���þ���7�������䵱����ͼ
		sprite7.setTexture(assetManager.getTexture("WEIMEI7"));
		sprite7.setScale(960.0f / assetManager.getTexture("WEIMEI7").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
		sprite7.setPosition(0, 0);
	}
	else if (StateAppreciate2::SelectImage2 == 8)
	{
		//���þ���8�������䵱����ͼ
		sprite8.setTexture(assetManager.getTexture("WEIMEI8"));
		sprite8.setScale(960.0f / assetManager.getTexture("WEIMEI8").getSize().x, 960.0f / assetManager.getTexture("WEIMEI2").getSize().y);
		sprite8.setPosition(0, 0);
	}
	else if (StateAppreciate2::SelectImage2 == 9)
	{
		//���þ���9�������䵱����ͼ
		sprite9.setTexture(assetManager.getTexture("WEIMEI9"));
		sprite9.setScale(960.0f / assetManager.getTexture("WEIMEI9").getSize().x, 960.0f / assetManager.getTexture("WEIMEI3").getSize().y);
		sprite9.setPosition(0, 0);
	}
	else if (StateAppreciate2::SelectImage2 == 10)
	{
		//���þ���10�������䵱����ͼ
		sprite10.setTexture(assetManager.getTexture("WEIMEI10"));
		sprite10.setScale(960.0f / assetManager.getTexture("WEIMEI10").getSize().x, 960.0f / assetManager.getTexture("WEIMEI4").getSize().y);
		sprite10.setPosition(0, 0);
	}
	else if (StateAppreciate2::SelectImage2 == 11)
	{
		//���þ���11�������䵱����ͼ
		sprite11.setTexture(assetManager.getTexture("WEIMEI11"));
		sprite11.setScale(960.0f / assetManager.getTexture("WEIMEI11").getSize().x, 960.0f / assetManager.getTexture("WEIMEI4").getSize().y);
		sprite11.setPosition(0, 0);
	}
	else if (StateAppreciate2::SelectImage2 == 12)
	{
		//���þ���12�������䵱����ͼ
		sprite12.setTexture(assetManager.getTexture("WEIMEI12"));
		sprite12.setScale(960.0f / assetManager.getTexture("WEIMEI12").getSize().x, 960.0f / assetManager.getTexture("WEIMEI4").getSize().y);
		sprite12.setPosition(0, 0);
	}

}
//����������¼�
void MagnifyAppreciate2::handleInput(sf::RenderWindow& window) {
	sf::Event event;
	//������Ƶ���ŵ���
	AudioManager& audioManager = AudioManager::getInstance();
	while (window.pollEvent(event))
	{
		//��ȡ���λ��
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		//������ر�ʱ�رմ���
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		// ... ����ť����¼���ʹ��stateManager.changeState(...)
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
				//����겻����ͣ�ڰ�ť��ʱ�ָ�ԭʼ��ɫ
				home.resetColor();
			}
		}
	}
}

//����
void MagnifyAppreciate2::update(float deltaTime) {

}

//��Ⱦ
void MagnifyAppreciate2::draw(sf::RenderWindow& window)
{
	//����ѡ��ֵ��ȷ�����Ƶ�ͼƬ
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
	// ... ���ư�ť
	this->home.draw(window);
}
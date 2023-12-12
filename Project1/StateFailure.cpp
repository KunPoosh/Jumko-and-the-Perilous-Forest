#include"StateFailure.hpp"
#include"AssetManager.hpp"
#include"StateMenu.hpp"
#include<ctime>

int StateFailure::SelectFailureCG = 0;
StateFailure::StateFailure(StateManager& manager) :stateManager(manager)
{
	srand(unsigned(time));
	isUnlock = false;
	//��ȡ�زĹ������ĵ���
	AssetManager& assetManager = AssetManager::getInstance();
	//ʵ�������
	EntityManager* entityManager = EntityManager::getInstance();
	//�ļ�������
	SettingsManager& settingManager = SettingsManager::getInstance();
	while (!isUnlock)
	{
		UnlockFailureCG = rand() % 10;//�������ֵ1-10��
		//ͨ��-baseѭ������01���������е�ֵ
		int count = 0;//��¼���������cgͼ����

		for (int i = 0; i< 10; i++)
		{
			if (settingManager.unlockedCGs[i])//��ȡ��һ��������cgͼ��++
			{
				count++;
			}
			if (count == 10)//ʮ���������˾��˳�whileѭ��
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
	//���ñ���ͼƬ
	BackgroundImage.setTexture(assetManager.getTexture("JumkoMenu"));
	// ʹͼƬ�䰵����Ȼ�ɼ�
	BackgroundImage.setColor(sf::Color(128, 128, 128, 255));
	//��ʼ�������ı�
	endText.setFont(assetManager.getFont("simhei")); //��������
	endText.setCharacterSize(60); //���������С
	endText.setFillColor(sf::Color::White);  //����������ɫ
	endText.setString(L"���ź���ʧ���ˣ�");
	sf::FloatRect textBounds = endText.getLocalBounds();
	endText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
	endText.setPosition(960 / 2.0f, 960 / 2.0f - 100);//�����ı�λ��

	//����ʱ���ı�
	this->TotalTime = entityManager->getPlayer()->getTime();
	//����ʱ����ʾ
	int minutes = static_cast<int>(TotalTime) / 60;
	int seconds = static_cast<int>(TotalTime) % 60;
	std::stringstream timeStream;// ʹ��std::setw��std::setfill��ȷ��ʱ����������λ������ʾ
	timeStream << std::setfill('0') << std::setw(2) << minutes << ":"
		<< std::setfill('0') << std::setw(2) << seconds;
	timeText.setFont(assetManager.getFont("simhei"));  //��������
	timeText.setCharacterSize(30);                       //���������С
	timeText.setFillColor(sf::Color::White);             //����������ɫ
	timeText.setString("Time: " + timeStream.str());
	sf::FloatRect timetextBounds = timeText.getLocalBounds();
	timeText.setOrigin(timetextBounds.left + timetextBounds.width / 2.0f, timetextBounds.top + timetextBounds.height / 2.0f);
	timeText.setPosition(960 / 2.0f, 960 / 2.0f);//�����ı�λ��

	//�������÷�
	scoreText.setFont(assetManager.getFont("simhei"));  //��������
	scoreText.setCharacterSize(30);                       //���������С
	scoreText.setFillColor(sf::Color::White);             //����������ɫ
	EndScore = entityManager->getPlayer()->getScore();
	scoreText.setString("Score: " + std::to_string(EndScore));
	sf::FloatRect scoretextBounds = scoreText.getLocalBounds();
	scoreText.setOrigin(scoretextBounds.left + scoretextBounds.width / 2.0f, scoretextBounds.top + scoretextBounds.height / 2.0f);
	scoreText.setPosition(960 / 2.0f, 960 / 2.0f + 100);//�����ı�λ��

	//���ð�ť
	Next.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"��һ��", 30);
	Next.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	Next.setPosition(430.0f, 630.0f, 90, 40);


	//�������е�ʵ��
	entityManager->clearAllEntities();
}


void StateFailure::handleInput(sf::RenderWindow& window)
{
	sf::Event event;
	//������Ƶ���ŵ���
	AudioManager& audioManager = AudioManager::getInstance();
	while (window.pollEvent(event))
	{
		//��ȡ���λ��
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			//��ȡ���λ��
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
	//������Ⱦ����ͼƬ
	window.draw(BackgroundImage);
	window.draw(this->endText);
	window.draw(this->timeText);
	window.draw(this->scoreText);
	this->Next.draw(window);
}

OpenFailureCG::OpenFailureCG(StateManager& manager) :stateManager(manager)
{
	//��ȡ�زĹ������ĵ���
	AssetManager& assetManager = AssetManager::getInstance();
	//��ȡҪ�򿪵�ս��CGͼ
	this->SelectFailureCG = StateFailure::SelectFailureCG;
	//�����ı�
	GameOver.setFont(assetManager.getFont("simhei"));
	GameOver.setFillColor(sf::Color::Red);
	GameOver.setCharacterSize(80);
	GameOver.setString("GameOver");
	GameOver.setPosition(350, 50);

	//���á����ء���ť
	home.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"�������˵�", 30);
	home.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	home.setPosition(50, 50, 200, 50);
	//��ʼ��ս��CGͼƬ��δ��ɣ�
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

}
//����������¼�
void OpenFailureCG::handleInput(sf::RenderWindow& window)
{
	sf::Event event;
	//������Ƶ���ŵ���
	AudioManager& audioManager = AudioManager::getInstance();
	while (window.pollEvent(event))
	{
		//��ȡ���λ��
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			//��ȡ���λ��
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (this->home.isMouseOver(mousePosition)) {
				//����������
				this->stateManager.changeState(std::make_unique<StateMenu>(stateManager));
				audioManager.playSound("ClickButton");
				//����BGM
				audioManager.playMusic("MenuMusic1", true);
			}
		}
		if (event.type == sf::Event::MouseMoved)
		{
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
void OpenFailureCG::update(float deltaTime)
{

}
//��Ⱦ
void OpenFailureCG::draw(sf::RenderWindow& window)
{
	//����SelectFailureCG��ֵ��ȷ��Ҫ���Ƶ�ս��CGͼ
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
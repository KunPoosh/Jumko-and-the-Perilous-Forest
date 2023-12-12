#include"StateVictory.hpp"
#include"StateMenu.hpp"


bool StateVictory::isHard = false;
//���췽��
StateVictory::StateVictory(StateManager& manager) :stateManager(manager)
{
	//��ȡ�زĹ������ĵ���
	AssetManager& assetManager = AssetManager::getInstance();
	//ʵ�������
	EntityManager* entityManager = EntityManager::getInstance();
	//�ļ�������
	SettingsManager& settingManager = SettingsManager::getInstance();
	//���ñ���ͼƬ
	BackgroundImage.setTexture(assetManager.getTexture("JumkoMenu"));
	// ʹͼƬ�䰵����Ȼ�ɼ�
	BackgroundImage.setColor(sf::Color(128, 128, 128, 255));
	//��ʼ�������ı�
	endText.setFont(assetManager.getFont("simhei")); //��������
	endText.setCharacterSize(60); //���������С
	endText.setFillColor(sf::Color::White);  //����������ɫ
	endText.setString(L"��ϲ�㣬���ʤ�ˣ�");
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
	//��ȡ����Ƿ�ѡ��������ģʽ
	isHard = entityManager->getPlayer()->isHardCore();

	//�������е�ʵ��
	entityManager->clearAllEntities();
}

//����������¼�
void StateVictory::handleInput(sf::RenderWindow& window)
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

//����
void StateVictory::update(float deltaTime)
{

}

//��Ⱦ��δ��ɣ�
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
	//��ȡ�زĹ������ĵ���
	AssetManager& assetManager = AssetManager::getInstance();

	//���á����ء���ť
	home.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"�������˵�", 30);
	home.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	home.setPosition(50, 50, 200, 50);

	//��ʼ��ʤ��CGͼƬ��δ��ɣ�
	VictoryCG1.setTexture(assetManager.getTexture("WEIMEI11"));
	VictoryCG1.setScale(960.0f / assetManager.getTexture("WEIMEI11").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
	VictoryCG1.setPosition(0, 0);

	VictoryCG2.setTexture(assetManager.getTexture("WEIMEI12"));
	VictoryCG2.setScale(960.0f / assetManager.getTexture("WEIMEI12").getSize().x, 960.0f / assetManager.getTexture("WEIMEI1").getSize().y);
	VictoryCG2.setPosition(0, 0);

	//�޸��ļ�
	SettingsManager& settingManager = SettingsManager::getInstance();
	//��ģʽ��ʤ��CG
	if (StateVictory::isHard == false)
	{
		settingManager.unlockedCGs[10] = 1;
	}
	else if (StateVictory::isHard == true)//����ģʽ��ʤ��CG
	{
		settingManager.unlockedCGs[11] = 1;
	}
}

//����������¼�
void OpenVictoryCG::handleInput(sf::RenderWindow& window)
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
void OpenVictoryCG::update(float deltaTime) {

}

//��Ⱦ
void OpenVictoryCG::draw(sf::RenderWindow& window)
{
	//��ģʽ��ʤ��CG
	if (StateVictory::isHard == false)
	{
		window.draw(VictoryCG1);
	}
	else if (StateVictory::isHard == true)//����ģʽ��ʤ��CG
	{
		window.draw(VictoryCG2);
	}
	home.draw(window);
}
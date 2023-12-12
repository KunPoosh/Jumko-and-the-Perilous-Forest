#include "StateMenu.hpp"
#include <iostream>
#include "Animation.hpp"

StateMenu::StateMenu(StateManager& manager)
    : stateManager(manager)
{
    //���췽��������һ�����������������ã�������ó����������ķ�����(δ���)
    /*
    ������: ����ɳ

    ����:
        ��ʼ����������
            1.������ť������Ϸ������ģʽ�����ã���Ϸָ�ϣ��˳���Ϸ��
            2.��������ͼƬ
            3.������Ϸ������
            4.ʹ��ǰ�������������������������

    ����:
        StateManager& manager   //�������������������������еĳ���������ָ���ϡ�

    ����ֵ: StateMenu
    */
    //----------------------ʵ��------------------------//

    //ʹ���زĹ�����
    AssetManager& assetManager = AssetManager::getInstance();

    //���ñ���ͼƬ
    BackgroundImage.setTexture(assetManager.getTexture("JumkoMenu"));
    BackgroundImage.setPosition(0, 0);

    //����"��ʼ��Ϸ"��ť��λ�õ���Ϣ
    startButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"����Ϸ", 40);
    startButton.setColor(sf::Color(200, 200, 200, 100), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 150));
    startButton.setPosition(50, 350, 400, 80);

    //����"����ģʽ"��ť��λ�õ���Ϣ
    galleryButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"����ģʽ", 40);
    galleryButton.setColor(sf::Color(200, 200, 200, 50), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 130));
    galleryButton.setPosition(50, 430, 400, 80);

    //����"����"��ť��λ�õ���Ϣ
    settingsButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"����", 40);
    settingsButton.setColor(sf::Color(200, 200, 200, 100), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 150));
    settingsButton.setPosition(50, 510, 400, 80);

    //����"����"��ť��λ�õ���Ϣ
    aboutButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"����", 40);
    aboutButton.setColor(sf::Color(200, 200, 200, 50), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 130));
    aboutButton.setPosition(50, 590, 400, 80);

    //����"��Ϸ�淨"��ť��λ�õ���Ϣ
    howToPlayButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"��Ϸ�淨", 40);
    howToPlayButton.setColor(sf::Color(200, 200, 200, 100), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 150));
    howToPlayButton.setPosition(50, 670, 400, 80);

    //����"�˳�"��ť��λ�õ���Ϣ
    exitButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"�˳���Ϸ", 40);
    exitButton.setColor(sf::Color(200, 200, 200, 50), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 130));
    exitButton.setPosition(50, 750, 400, 80);

    isSelectStare = false;
    isSelectGallery = false;
    isSelectSettings = false;
    isSelectAbout = false;
    isSelectHowToPlay = false;
    isSelectExit = false;

    // ���� TitleAnimation ʵ��
    std::shared_ptr<TitleAnimation> titleAnimation = std::make_shared<TitleAnimation>();

    EntityManager::getInstance()->addEntity(titleAnimation);
}

void StateMenu::handleInput(sf::RenderWindow& window){
    //����ǰ�������¼�����Ҫ�ǵ����ť���¼������д������ҷ�����������ǰ�����С���д���෽����(δ���)
    /*
    ������: ����ɳ

    ����: ��������¼���
            ����¼����㵽������ť��ʱ�Ĳ�ͬ��Ӧ��ʩ��

    ����:
        sf::RenderWindow& window    //���������ڣ���Ҫ���ڽ�һ���´���
        sf::Event& event            //�������з�����һ���¼������ڴ���

    ����ֵ: void
    */
    //----------------------ʵ��------------------------//

    //����һ���¼��࣬�������ܺʹ����¼�
    sf::Event event;

    //������Ƶ���ŵ���
    AudioManager& audioManager = AudioManager::getInstance();
    //����ʵ�������
    EntityManager* entityManager = EntityManager::getInstance();

    while (window.pollEvent(event))
    {
        //��ȡ���λ��
        sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

        //������ر�ʱ�رմ���
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        //�������ʱ�ж����˲��������Ǹ���ť���Ϸ�
        if (event.type == sf::Event::MouseButtonPressed) {
            //�ڰ�ť��ʼ��Ϸ���Ϸ�
            if (startButton.isMouseOver(mousePosition)) {
                audioManager.playSound("ClickButton");
                stateManager.changeState(stateManager.createState("StateStarGame"));
                entityManager->clearAllEntities();
                //ֹͣ��������
                audioManager.stopMusic();
            }

            //�ڰ�ť����ģʽ���Ϸ�
            else if (galleryButton.isMouseOver(mousePosition)) {
                stateManager.changeState(stateManager.createState("Appreciate"));
                audioManager.playSound("ClickButton");
                //��ת����ʱ��յ�ǰ��ʵ��
                entityManager->clearAllEntities();
            }

            //�ڰ�ť"����"���Ϸ�
            else if (settingsButton.isMouseOver(mousePosition)) {
                //�������л������ý���
                stateManager.changeState(stateManager.createState("StateSetting"));
                audioManager.playSound("ClickButton");
                //��ת����ʱ��յ�ǰ��ʵ��
                entityManager->clearAllEntities();
            }

            //�ڰ�ť���ڵ��Ϸ�
            else if (aboutButton.isMouseOver(mousePosition)) {
                stateManager.changeState(stateManager.createState("StateAbout"));
                audioManager.playSound("ClickButton");
                //��ת����ʱ��յ�ǰ��ʵ��
                entityManager->clearAllEntities();
            }

            //�ڰ�ť��Ϸ�淨���Ϸ�
            else if (howToPlayButton.isMouseOver(mousePosition)) {
                stateManager.changeState(stateManager.createState("StateGameplay"));
                audioManager.playSound("ClickButton");
                //��ת����ʱ��յ�ǰ��ʵ��
                entityManager->clearAllEntities();
            }

            //�ڰ�ť�˳����Ϸ�
            else if (exitButton.isMouseOver(mousePosition)) {
                audioManager.playSound("ClickButton");
                window.close();
                return;
            }

        }

        //������ƶ�ʱ��ȡ���λ�ã��ж��Ƿ���ĳһ����ť���棬�ǵĻ�����ť�ı���ɫ
        if (event.type == sf::Event::MouseMoved) {
            //����true����ǰ����ڵ�ǰ"���ð�ť��"
           
            //�ڿ�ʼ��Ϸ��ť���Ϸ�
            if (startButton.isMouseOver(mousePosition)) {
                startButton.onHover();
                if (!isSelectStare) {
                    isSelectStare = true;
                    audioManager.playSound("SelectButton");
                }
            }
            else
            {
                startButton.resetColor();
                isSelectStare = false;
            }

            //�ڼ���ģʽ��ť���Ϸ�
            if (galleryButton.isMouseOver(mousePosition)) {
                galleryButton.onHover();
                if (!isSelectGallery) {
                    isSelectGallery = true;
                    audioManager.playSound("SelectButton");
                }
            }
            else
            {
                galleryButton.resetColor();
                isSelectGallery = false;
            }

            //�����ð�ť���Ϸ�
            if (settingsButton.isMouseOver(mousePosition)) {
                settingsButton.onHover();
                if (!isSelectSettings) {
                    isSelectSettings = true;
                    audioManager.playSound("SelectButton");
                }
            }
            else {
                settingsButton.resetColor();
                isSelectSettings = false;
            }

            //�ڹ��ڰ�ť���Ϸ�
            if (aboutButton.isMouseOver(mousePosition)) {
                aboutButton.onHover();
                if (!isSelectAbout) {
                    isSelectAbout = true;
                    audioManager.playSound("SelectButton");
                }
            }
            else
            {
                aboutButton.resetColor();
                isSelectAbout = false;
            }

            //����Ϸ�淨��ť���Ϸ�
            if (howToPlayButton.isMouseOver(mousePosition)) {
                howToPlayButton.onHover();
                if (!isSelectHowToPlay) {
                    isSelectHowToPlay = true;
                    audioManager.playSound("SelectButton");
                }
            }
            else
            {
                howToPlayButton.resetColor();
                isSelectHowToPlay = false;
            }

            //���˳���ť���Ϸ�
            if (exitButton.isMouseOver(mousePosition)) {
                exitButton.onHover();
                if (!isSelectExit) {
                    isSelectExit = true;
                    audioManager.playSound("SelectButton");
                }
            }
            else
            {
                exitButton.resetColor();
                isSelectExit = false;
            }

        }
    }

 
}

void StateMenu::update(float deltaTime)  {
    //���µ�ǰ���ڣ���Ҫ�Ǹ��±�����
    /*
    ������: ����ɳ

    ����: ��

    ����:void

    ����ֵ: void
    */
    //----------------------����Ҫʵ��------------------------//

    EntityManager::getInstance()->updateEntities(deltaTime);
}

void StateMenu::draw(sf::RenderWindow& window) {
    //��Ⱦ����Ⱦ���еİ�ť�ͱ���ͼƬ�ȵȡ�(δ���)
    /*
    ������: ����ɳ

    ����: ��

    ����:
        sf::RenderWindow& window    //��Ҫ��Ⱦ����λ��

    ����ֵ: void
    */
    //----------------------ʵ��------------------------//

    //��Ⱦ����ͼ
    window.draw(BackgroundImage);

    //���ö�Ӧ��ť����Ⱦ�������������´���
    startButton.draw(window);
    galleryButton.draw(window);
    settingsButton.draw(window);
    aboutButton.draw(window);
    howToPlayButton.draw(window);
    exitButton.draw(window);

    //�����Ⱦ���⶯��
    EntityManager::getInstance()->drawEntities(window);
}

#include "StateMainGame.hpp"
#include <iostream>
#include "Animation.hpp"
#include "StateMenu.hpp"

StateMainGame::StateMainGame(StateManager& manager)
    : stateManager(manager)
{
    //���췽��ʵ��
    //----------------------ʵ��------------------------//
    //�ٻ��زĹ��������
    AssetManager& assetManager = AssetManager::getInstance();

    // ��ʼ��ʱ���ı�
    timeText.setFont(assetManager.getFont("simhei"));  // ��������
    timeText.setCharacterSize(30);                       // ���������С
    timeText.setFillColor(sf::Color::Black);             // ����������ɫ
    timeText.setPosition(680, 20);                      // �����ı�λ��

    // ��ʼ�������ı�
    scoreText.setFont(assetManager.getFont("simhei")); // ͬ��
    scoreText.setCharacterSize(30);                      // ͬ��
    scoreText.setFillColor(sf::Color::Black);            // ͬ��
    scoreText.setPosition(680, 60);                     // �����ı�λ����΢����ʱ���ı�

    // ��ʼ�������ı�
    HP.setFont(assetManager.getFont("simhei")); // ͬ��
    HP.setCharacterSize(30);                      // ͬ��
    HP.setFillColor(sf::Color::Black);            // ͬ��
    HP.setPosition(670, 400);                     // �����ı�λ����Ѫ�����
    HP.setString("HP:");

    // ��ʼ��FPS�ı�
    FPS.setFont(assetManager.getFont("simhei")); // ��������
    FPS.setCharacterSize(15);                      // ���������С
    FPS.setFillColor(sf::Color::Black);            // ����������ɫ
    FPS.setPosition(880, 5);                      // �����ı�λ�ã��������Ͻ�

    //���ñ���ͼƬ
    gameBackground.setTexture(assetManager.getTexture("BackGround2"));
    gameBackground.setPosition(0, -1040);
    //���ý�������
    characterPortrait.setTexture(assetManager.getTexture("JumkoPic1"));
    characterPortrait.setPosition(705, 480);
    //���ü���ͼ��
    skillIcon.setTexture(assetManager.getTexture("Skill"));
    skillIcon.setPosition(665, 250);
    //���ó��ܿ�
    energyBars1.setSize(sf::Vector2f(20, 20));
    energyBars1.setPosition(829, 250);
    energyBars1.setFillColor(sf::Color::Green);

    energyBars2.setSize(sf::Vector2f(20, 20));
    energyBars2.setPosition(829, 280);
    energyBars2.setFillColor(sf::Color::Green);

    // ��ʼ���ұ�UI�ı�������
    uiBackground.setSize(sf::Vector2f(320, 960));  // ���þ��εĿ��Ϊ360���߶�Ϊ960
    uiBackground.setPosition(640, 0);              // �����η����ڴ��ڵ��Ҳ�
    uiBackground.setFillColor(sf::Color(250, 240, 200));    //������ɫΪ��ɫ

    // ��ʼ��������µĻ�ɫ����
    portraitBackground.setSize(sf::Vector2f(270, 500)); // ���þ��εĿ��Ϊ270���߶�Ϊ500
    portraitBackground.setPosition(665, 460);           // ���þ��ε�λ��
    portraitBackground.setFillColor(sf::Color(128, 128, 128));//���þ�����ɫΪ��ɫ

    // ��ʼ��Ѫ���װ�
    healthBarBackground.setSize(sf::Vector2f(206, 26));  // ��Ѫ���Դ�һ��
    healthBarBackground.setPosition(730, 407);          // λ����Ѫ����ͬ������ƫ��
    healthBarBackground.setFillColor(sf::Color(50, 50, 50)); // ��ɫ������Ѫ����ɫ�γɶԱ�
    // ��ʼ��Ѫ��
    healthBar.setSize(sf::Vector2f(200, 20));  // ����Ѫ���Ĵ�С
    healthBar.setPosition(733, 410);           // ����Ѫ����λ��
    healthBar.setFillColor(sf::Color::Red);    // ����Ѫ����ɫΪ��ɫ

    // ��ʼ��������ȴ���װ�
    skillBarBackground.setSize(sf::Vector2f(14, 130));  // ���ü�����ȴ���װ�Ĵ�С
    skillBarBackground.setPosition(805, 250);           // ���ü�����ȴ���װ��λ��
    skillBarBackground.setFillColor(sf::Color(50, 50, 50)); // ���ü�����ȴ���װ���ɫ
    // ��ʼ��������ȴ��
    skillBar.setSize(sf::Vector2f(10, 126));  // ���ü�����ȴ���ĳ�ʼ��С
    skillBar.setPosition(807, 252);           // ���ü�����ȴ����λ��
    skillBar.setFillColor(sf::Color::Cyan);   // ���ü�����ȴ����ɫ

    // ��ʼ����ͣ������
    ground.setSize(sf::Vector2f(960, 960));
    ground.setPosition(0, 0);
    ground.setFillColor(sf::Color(0, 0, 0, 128));
    ground2.setSize(sf::Vector2f(300, 300));
    ground2.setPosition(300, 300);
    ground2.setFillColor(sf::Color(0, 0, 0, 66));
    // ��ʼ����ť
    Continue.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"����", 40);
    Continue.setColor(sf::Color(200, 200, 200, 100), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 150));
    Continue.setPosition(325, 350, 250, 80);
    Return.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"���ر������", 40);
    Return.setColor(sf::Color(200, 200, 200, 100), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 150));
    Return.setPosition(325, 500, 250, 80);


    //��ֵ��ʼ��
    TIMEFORPLAY = 0;
    score = 0;
    TOTALTIME = 0.f;
    elapsedTime = 0.f;
    fpsUpdateTime = 0.f;
    isHardMode = SettingsManager::getInstance().isHardCore;
    isEXMode = SettingsManager::getInstance().isEXHard;
    isBossMode = SettingsManager::getInstance().isBossCore;

    //数值初始化
    score = 0;
    power = 0;
    if (isBossMode) {
        TOTALTIME = 205.0f;
        TIMEFORPLAY = 104;
    }
    else {
        TOTALTIME = 0.f; 
        TIMEFORPLAY = 0;
    }
    ENEMYOUT2S = 0;
    ENEMYOUT2STIME = 0.f;
    //RecordTotalTime = 0.f;

    maxPlayerHealth = 1000;
    playerHealth = 1000;

    skillCD = 5;
    CDTime = 0.f;
    skillCharging = 1;
    skillUseCd = 1.0f;
    useTime = 0.f;
    
    //�������
    std::shared_ptr<Player> player = std::make_unique<Player>();
    //������ҳ�ʼλ��
    player->setPosition(sf::Vector2f(300, 800));
    //�Ƿ�������ģʽ
    if (isHardMode) {
        player->hardCore();
    }
    //�Ƿ���EX�Ѷ�ģʽ
    else if (isEXMode) {
        player->exCord();
    }
    //�Ƿ����޵�ģʽ
    if (SettingsManager::getInstance().isInvincible) {
        player->Invincible();
    }

    //�������������
    //是否开启Boss战模式
    if (isBossMode) {
        player->bossCore();
    }
    //管理器关联玩家
    EntityManager::getInstance()->setPlayer(player);

    //...
}

bool isContinue = false;
bool isReturn = false;
void StateMainGame::handleInput(sf::RenderWindow& window) {
    //������Ϸ�߼�����������롢��ײ���ȡ�
    //----------------------ʵ��------------------------//
    // 
    //����һ���¼��࣬�������ܺʹ����¼�
    sf::Event event;

    //������Ƶ���ŵ���
    AudioManager& audioManager = AudioManager::getInstance();
    //����ʵ�������
    EntityManager* entityManager = EntityManager::getInstance();

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                if (isEsc) {
                    isEsc = false;
                    audioManager.resumeMusic();
                }
                else {
                    isEsc = true;
                    audioManager.pauseMusic();
                }
            }
        }
        if (!isEsc)
        {
            //���¼�����������ɫ
            entityManager->getPlayer()->handleInput(event);

            //�����Ƿ��ͷ�
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::X) {
                    if (skillCharging > 0 && (useTime >= skillUseCd)) {
                        entityManager->getPlayer()->SkillFire();
                        skillCharging--;
                        useTime = 0.f;
                    }
                }

            }

        }
        else
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                //�ڰ�ť�������Ϸ�
                if (Continue.isMouseOver(window)) {
                    audioManager.playSound("ClickButton");
                    isEsc = false;
                    audioManager.resumeMusic();
                }

                //�ڰ�ť���ر���ҳ����Ϸ�
                else if (Return.isMouseOver(window)) {
                    entityManager->clearAllEntities();
                    stateManager.changeState(std::make_unique<StateMenu>(stateManager));
                    audioManager.playSound("ClickButton");

                    audioManager.playMusic("MenuMusic1", true);
                    //��ת����ʱ��յ�ǰ��ʵ��

                }
            }
            if (event.type == sf::Event::MouseMoved)
            {
                if (Continue.isMouseOver(window)) {
                    Continue.onHover();
                    if (!isContinue) {
                        isContinue = true;
                        audioManager.playSound("SelectButton");
                    }
                }
                else
                {
                    Continue.resetColor();
                    isContinue = false;
                }

                if (Return.isMouseOver(window)) {
                    Return.onHover();
                    if (!isReturn) {
                        isReturn = true;
                        audioManager.playSound("SelectButton");
                    }
                }
                else
                {
                    Return.resetColor();
                    isReturn = false;
                }
            }
        }
        //������ر�ʱ�رմ���
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
    //...
}

void StateMainGame::update(float deltaTime) {
    //������Ϸ״̬����ʵ��λ�á���Ϸ�����ȡ�
    //----------------------ʵ��------------------------//

    //�زĴ��
    AssetManager& assetManager = AssetManager::getInstance();
    //ʵ�������
    EntityManager* entityManager = EntityManager::getInstance();
    if (!isEsc)
    {
        //ʱ����£�����
        ENEMYOUT2STIME += deltaTime;
        TOTALTIME += deltaTime;
        elapsedTime += deltaTime;
        useTime += deltaTime;
        //RecordTotalTime = TOTALTIME;
        //����ʱ����ʾ
        int minutes = static_cast<int>(TOTALTIME) / 60;
        int seconds = static_cast<int>(TOTALTIME) % 60;
        entityManager->getPlayer()->setTime(TOTALTIME);

        // ʹ��std::setw��std::setfill��ȷ��ʱ����������λ������ʾ
        std::stringstream timeStream;
        timeStream << std::setfill('0') << std::setw(2) << minutes << ":"
            << std::setfill('0') << std::setw(2) << seconds;
        timeText.setString("Time: " + timeStream.str());

        ADDENEMYS();

        //����ʵ��
        entityManager->updateEntities(deltaTime);

        //���¼�����ȴ
        if (skillCharging < 2) {
            CDTime += deltaTime;
            if (CDTime >= skillCD) {
                CDTime = 0.f;
                skillCharging++;
            }
        }
        else
        {
            CDTime = 0.f;
        }
        float cooldownRatio = CDTime / skillCD;
        cooldownRatio = 1.0f - std::max(0.0f, std::min(cooldownRatio, 1.0f)); // ȷ��������0��1֮��
        // ���ü�����ȴ���ĸ߶�
        skillBar.setSize(sf::Vector2f(10, 126 * (1 - cooldownRatio)));

        //����Ҵ����·���
        score = entityManager->getPlayer()->getScore();
        //������ʾ
        scoreText.setString("Score: " + std::to_string(score));

        //����Ҵ����������Ϣ
        playerHealth = entityManager->getPlayer()->getHealth();
        maxPlayerHealth = entityManager->getPlayer()->getMaxHealth();
        //�ж���ɫ�Ƿ�����
        if (playerHealth <= 0.f) {
            //�л������㳡��
            stateManager.changeState(stateManager.createState("StateFailure"));
            //ֹͣ����BGM
            AudioManager::getInstance().stopMusic();
            //���ʵ��Ĳ����ɽ��㳡������
            return;
        }
        //������ʾ
        // ����Ѫ���ĳ��ȱ���
        float healthRatio = static_cast<float>(playerHealth) / maxPlayerHealth;
        // ����Ѫ���ĳ���
        healthBar.setSize(sf::Vector2f(200 * healthRatio, 20));


        //������ʾFPS
        fpsUpdateTime += deltaTime; // �ۼ�ʱ��
        // ÿ�����һ��FPS��ʾ
        if (fpsUpdateTime >= 1.0f) {
            float currentFPS = 1.0f / deltaTime; // ����FPS
            FPS.setString("FPS: " + std::to_string(static_cast<int>(currentFPS)));
            fpsUpdateTime = 0.0f; // �����ۼ�ʱ��
        }

        //�ƶ�����ͼƬ
        gameBackground.move(sf::Vector2f(0, deltaTime * 2000));
        if (gameBackground.getPosition().y >= 0) {
            gameBackground.setPosition(sf::Vector2f(0, -1040));
        }


        //���ɫͬ����ֵ
        //ͬ�����ܳ���
        entityManager->getPlayer()->setSkill(skillCharging);


        //...
        //������
        //std::cout << "TIMEFORPLAY: " << TIMEFORPLAY << std::endl;
    }
}

void StateMainGame::draw(sf::RenderWindow& window) {
    //��Ⱦ��Ϸʵ��ͽ���Ԫ��
    //----------------------ʵ��------------------------//
    window.draw(gameBackground);



    //��Ⱦʵ��
    EntityManager::getInstance()->drawEntities(window);

    //��ȾUI
    window.draw(uiBackground);
    window.draw(portraitBackground);
    window.draw(characterPortrait);
    window.draw(skillIcon);
    window.draw(timeText);
    window.draw(scoreText);
    window.draw(HP);
    window.draw(healthBarBackground);
    window.draw(healthBar);
    window.draw(skillBarBackground);
    window.draw(skillBar);
    window.draw(FPS);

    //�����Ƿ�Ҫ��Ⱦ���ܿ�
    if (skillCharging >= 1) {
        window.draw(energyBars1);
    }
    if (skillCharging >= 2) {
        window.draw(energyBars2);
    }

    if (isEsc)
    {
        window.draw(ground);
        window.draw(ground2);
        Continue.draw(window);
        Return.draw(window);
    }
    
    //...
}
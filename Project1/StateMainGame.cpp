#include "StateMainGame.hpp"
#include <iostream>
#include "Animation.hpp"
#include "StateMenu.hpp"

StateMainGame::StateMainGame(StateManager& manager)
    : stateManager(manager)
{
    //构造方法实现
    //----------------------实现------------------------//
    //召唤素材管理器大哥
    AssetManager& assetManager = AssetManager::getInstance();

    // 初始化时间文本
    timeText.setFont(assetManager.getFont("simhei"));  // 设置字体
    timeText.setCharacterSize(30);                       // 设置字体大小
    timeText.setFillColor(sf::Color::Black);             // 设置字体颜色
    timeText.setPosition(680, 20);                      // 设置文本位置

    // 初始化分数文本
    scoreText.setFont(assetManager.getFont("simhei")); // 同上
    scoreText.setCharacterSize(30);                      // 同上
    scoreText.setFillColor(sf::Color::Black);            // 同上
    scoreText.setPosition(680, 60);                     // 设置文本位置稍微低于时间文本

    // 初始化分数文本
    HP.setFont(assetManager.getFont("simhei")); // 同上
    HP.setCharacterSize(30);                      // 同上
    HP.setFillColor(sf::Color::Black);            // 同上
    HP.setPosition(670, 400);                     // 设置文本位置在血条左边
    HP.setString("HP:");

    // 初始化FPS文本
    FPS.setFont(assetManager.getFont("simhei")); // 设置字体
    FPS.setCharacterSize(15);                      // 设置字体大小
    FPS.setFillColor(sf::Color::Black);            // 设置字体颜色
    FPS.setPosition(880, 5);                      // 设置文本位置，例如右上角

    //设置背景图片
    gameBackground.setTexture(assetManager.getTexture("BackGround2"));
    gameBackground.setPosition(0, -1040);
    //设置酱可立绘
    characterPortrait.setTexture(assetManager.getTexture("JumkoPic1"));
    characterPortrait.setPosition(705, 480);
    //设置技能图标
    skillIcon.setTexture(assetManager.getTexture("Skill"));
    skillIcon.setPosition(665, 250);
    //设置充能块
    energyBars1.setSize(sf::Vector2f(20, 20));
    energyBars1.setPosition(829, 250);
    energyBars1.setFillColor(sf::Color::Green);

    energyBars2.setSize(sf::Vector2f(20, 20));
    energyBars2.setPosition(829, 280);
    energyBars2.setFillColor(sf::Color::Green);

    // 初始化右边UI的背景矩形
    uiBackground.setSize(sf::Vector2f(320, 960));  // 设置矩形的宽度为360，高度为960
    uiBackground.setPosition(640, 0);              // 将矩形放置在窗口的右侧
    uiBackground.setFillColor(sf::Color(250, 240, 200));    //设置颜色为米色

    // 初始化立绘底下的灰色矩形
    portraitBackground.setSize(sf::Vector2f(270, 500)); // 设置矩形的宽度为270，高度为500
    portraitBackground.setPosition(665, 460);           // 设置矩形的位置
    portraitBackground.setFillColor(sf::Color(128, 128, 128));//设置矩形颜色为灰色

    // 初始化血条底板
    healthBarBackground.setSize(sf::Vector2f(206, 26));  // 比血条稍大一点
    healthBarBackground.setPosition(730, 407);          // 位置与血条相同或略有偏移
    healthBarBackground.setFillColor(sf::Color(50, 50, 50)); // 暗色调，与血条颜色形成对比
    // 初始化血条
    healthBar.setSize(sf::Vector2f(200, 20));  // 设置血条的大小
    healthBar.setPosition(733, 410);           // 设置血条的位置
    healthBar.setFillColor(sf::Color::Red);    // 设置血条颜色为红色

    // 初始化技能冷却条底板
    skillBarBackground.setSize(sf::Vector2f(14, 130));  // 设置技能冷却条底板的大小
    skillBarBackground.setPosition(805, 250);           // 设置技能冷却条底板的位置
    skillBarBackground.setFillColor(sf::Color(50, 50, 50)); // 设置技能冷却条底板颜色
    // 初始化技能冷却条
    skillBar.setSize(sf::Vector2f(10, 126));  // 设置技能冷却条的初始大小
    skillBar.setPosition(807, 252);           // 设置技能冷却条的位置
    skillBar.setFillColor(sf::Color::Cyan);   // 设置技能冷却条颜色

    // 初始化暂停背景板
    ground.setSize(sf::Vector2f(960, 960));
    ground.setPosition(0, 0);
    ground.setFillColor(sf::Color(0, 0, 0, 128));
    ground2.setSize(sf::Vector2f(300, 300));
    ground2.setPosition(300, 300);
    ground2.setFillColor(sf::Color(0, 0, 0, 66));
    // 初始化按钮
    Continue.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"继续", 40);
    Continue.setColor(sf::Color(200, 200, 200, 100), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 150));
    Continue.setPosition(325, 350, 250, 80);
    Return.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"返回标题界面", 40);
    Return.setColor(sf::Color(200, 200, 200, 100), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 150));
    Return.setPosition(325, 500, 250, 80);

    //数值初始化
    TIMEFORPLAY = 0;
    score = 0;
    TOTALTIME = 0.f;
    elapsedTime = 0.f;
    fpsUpdateTime = 0.f;
    isHardMode = SettingsManager::getInstance().isHardCore;
    isEXMode = SettingsManager::getInstance().isEXHard;
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
    
    //创建玩家
    std::shared_ptr<Player> player = std::make_unique<Player>();
    //设置玩家初始位置
    player->setPosition(sf::Vector2f(300, 800));
    //是否开启困难模式
    if (isHardMode) {
        player->hardCore();
    }
    //是否开启EX难度模式
    else if (isEXMode) {
        player->exCord();
    }
    //是否开启无敌模式
    if (SettingsManager::getInstance().isInvincible) {
        player->Invincible();
    }
    //管理器关联玩家
    EntityManager::getInstance()->setPlayer(player);

    //...
}

bool isContinue = false;
bool isReturn = false;
void StateMainGame::handleInput(sf::RenderWindow& window) {
    //处理游戏逻辑，如玩家输入、碰撞检测等。
    //----------------------实现------------------------//
    // 
    //创建一个事件类，用来接受和处理事件
    sf::Event event;

    //引用音频播放单例
    AudioManager& audioManager = AudioManager::getInstance();
    //引用实体管理器
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
            //将事件尽数传给角色
            entityManager->getPlayer()->handleInput(event);

            //技能是否释放
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
                //在按钮继续的上方
                if (Continue.isMouseOver(window)) {
                    audioManager.playSound("ClickButton");
                    isEsc = false;
                    audioManager.resumeMusic();
                }

                //在按钮返回标题页面的上方
                else if (Return.isMouseOver(window)) {
                    entityManager->clearAllEntities();
                    stateManager.changeState(std::make_unique<StateMenu>(stateManager));
                    audioManager.playSound("ClickButton");

                    audioManager.playMusic("MenuMusic1", true);
                    //跳转场景时清空当前的实体

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
        //当点击关闭时关闭窗口
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
    //...
}

void StateMainGame::update(float deltaTime) {
    //更新游戏状态，如实体位置、游戏分数等。
    //----------------------实现------------------------//

    //素材大哥
    AssetManager& assetManager = AssetManager::getInstance();
    //实体管理器
    EntityManager* entityManager = EntityManager::getInstance();
    if (!isEsc)
    {
        //时间更新！！！
        ENEMYOUT2STIME += deltaTime;
        TOTALTIME += deltaTime;
        elapsedTime += deltaTime;
        useTime += deltaTime;
        //RecordTotalTime = TOTALTIME;
        //更新时间显示
        int minutes = static_cast<int>(TOTALTIME) / 60;
        int seconds = static_cast<int>(TOTALTIME) % 60;
        entityManager->getPlayer()->setTime(TOTALTIME);

        // 使用std::setw和std::setfill来确保时间总是以两位数字显示
        std::stringstream timeStream;
        timeStream << std::setfill('0') << std::setw(2) << minutes << ":"
            << std::setfill('0') << std::setw(2) << seconds;
        timeText.setString("Time: " + timeStream.str());

        ADDENEMYS();

        //更新实体
        entityManager->updateEntities(deltaTime);

        //更新技能冷却
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
        cooldownRatio = 1.0f - std::max(0.0f, std::min(cooldownRatio, 1.0f)); // 确保比例在0到1之间
        // 设置技能冷却条的高度
        skillBar.setSize(sf::Vector2f(10, 126 * (1 - cooldownRatio)));

        //从玩家处更新分数
        score = entityManager->getPlayer()->getScore();
        //更新显示
        scoreText.setString("Score: " + std::to_string(score));

        //从玩家处获得生命信息
        playerHealth = entityManager->getPlayer()->getHealth();
        maxPlayerHealth = entityManager->getPlayer()->getMaxHealth();
        //判定角色是否死亡
        if (playerHealth <= 0.f) {
            //切换到结算场景
            stateManager.changeState(stateManager.createState("StateFailure"));
            //停止播放BGM
            AudioManager::getInstance().stopMusic();
            //清空实体的操作由结算场景负责
            return;
        }
        //更新显示
        // 计算血条的长度比例
        float healthRatio = static_cast<float>(playerHealth) / maxPlayerHealth;
        // 设置血条的长度
        healthBar.setSize(sf::Vector2f(200 * healthRatio, 20));


        //更新显示FPS
        fpsUpdateTime += deltaTime; // 累加时间
        // 每秒更新一次FPS显示
        if (fpsUpdateTime >= 1.0f) {
            float currentFPS = 1.0f / deltaTime; // 计算FPS
            FPS.setString("FPS: " + std::to_string(static_cast<int>(currentFPS)));
            fpsUpdateTime = 0.0f; // 重置累计时间
        }

        //移动背景图片
        gameBackground.move(sf::Vector2f(0, deltaTime * 2000));
        if (gameBackground.getPosition().y >= 0) {
            gameBackground.setPosition(sf::Vector2f(0, -1040));
        }


        //与角色同步数值
        //同步技能充能
        entityManager->getPlayer()->setSkill(skillCharging);


        //...
        //测试区
        //std::cout << "TIMEFORPLAY: " << TIMEFORPLAY << std::endl;
    }
}

void StateMainGame::draw(sf::RenderWindow& window) {
    //渲染游戏实体和界面元素
    //----------------------实现------------------------//
    window.draw(gameBackground);



    //渲染实体
    EntityManager::getInstance()->drawEntities(window);

    //渲染UI
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

    //觉得是否要渲染技能块
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
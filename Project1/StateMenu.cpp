#include "StateMenu.hpp"
#include <iostream>
#include "Animation.hpp"

StateMenu::StateMenu(StateManager& manager)
    : stateManager(manager)
{
    //构造方法，传入一个场景管理器的引用，方便调用场景管理器的方法。(未完成)
    /*
    负责人: 波波沙

    功能:
        初始化主场景：
            1.创建按钮（新游戏，鉴赏模式，设置，游戏指南，退出游戏）
            2.创建背景图片
            3.创建游戏标题字
            4.使当前场景对象关联场景管理器对象

    参数:
        StateManager& manager   //场景管理器单例，关联到类中的场景管理器指针上。

    返回值: StateMenu
    */
    //----------------------实现------------------------//

    //使用素材管理器
    AssetManager& assetManager = AssetManager::getInstance();

    //设置背景图片
    BackgroundImage.setTexture(assetManager.getTexture("JumkoMenu"));
    BackgroundImage.setPosition(0, 0);

    //设置"开始游戏"按钮的位置等信息
    startButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"新游戏", 40);
    startButton.setColor(sf::Color(200, 200, 200, 100), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 150));
    startButton.setPosition(50, 350, 400, 80);

    //设置"鉴赏模式"按钮的位置等信息
    galleryButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"鉴赏模式", 40);
    galleryButton.setColor(sf::Color(200, 200, 200, 50), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 130));
    galleryButton.setPosition(50, 430, 400, 80);

    //设置"设置"按钮的位置等信息
    settingsButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"设置", 40);
    settingsButton.setColor(sf::Color(200, 200, 200, 100), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 150));
    settingsButton.setPosition(50, 510, 400, 80);

    //设置"关于"按钮的位置等信息
    aboutButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"关于", 40);
    aboutButton.setColor(sf::Color(200, 200, 200, 50), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 130));
    aboutButton.setPosition(50, 590, 400, 80);

    //设置"游戏玩法"按钮的位置等信息
    howToPlayButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"游戏玩法", 40);
    howToPlayButton.setColor(sf::Color(200, 200, 200, 100), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 150));
    howToPlayButton.setPosition(50, 670, 400, 80);

    //设置"退出"按钮的位置等信息
    exitButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"退出游戏", 40);
    exitButton.setColor(sf::Color(200, 200, 200, 50), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 130));
    exitButton.setPosition(50, 750, 400, 80);

    //设置"音乐开关"按钮的位置等信息
    musicButton.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"音乐开关", 40);
    musicButton.setColor(sf::Color(200, 200, 200, 100), sf::Color(255, 0, 0, 0), sf::Color(180, 180, 180, 150));
    musicButton.setPosition(760, 870 , 200, 80);

    isSelectStare = false;
    isSelectGallery = false;
    isSelectSettings = false;
    isSelectAbout = false;
    isSelectHowToPlay = false;
    isSelectExit = false;
    isSelectMusic = false;
    isMusic = true;

    // 创建 TitleAnimation 实例
    std::shared_ptr<TitleAnimation> titleAnimation = std::make_shared<TitleAnimation>();

    EntityManager::getInstance()->addEntity(titleAnimation);
}

void StateMenu::handleInput(sf::RenderWindow& window){
    //将当前发生的事件（主要是点击按钮的事件）进行处理，并且反馈操作到当前窗口中。复写基类方法。(未完成)
    /*
    负责人: 波波沙

    功能: 处理各种事件。
            点击事件，点到各各按钮上时的不同对应措施。

    参数:
        sf::RenderWindow& window    //程序主窗口，主要用于进一步下传。
        sf::Event& event            //主窗口中发生的一个事件，用于处理。

    返回值: void
    */
    //----------------------实现------------------------//

    //创建一个事件类，用来接受和处理事件
    sf::Event event;

    //引用音频播放单例
    AudioManager& audioManager = AudioManager::getInstance();
    //引用实体管理器
    EntityManager* entityManager = EntityManager::getInstance();

    while (window.pollEvent(event))
    {
        //获取鼠标位置
        sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

        //当点击关闭时关闭窗口
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        //当鼠标点击时判断这个瞬间鼠标在那个按钮的上方
        if (event.type == sf::Event::MouseButtonPressed) {
            //在按钮开始游戏的上方
            if (startButton.isMouseOver(mousePosition)) {
                audioManager.playSound("ClickButton");
                stateManager.changeState(stateManager.createState("StateStarGame"));
                entityManager->clearAllEntities();
                //停止播放音乐
                audioManager.stopMusic();
            }

            //在按钮鉴赏模式的上方
            else if (galleryButton.isMouseOver(mousePosition)) {
                stateManager.changeState(stateManager.createState("Appreciate"));
                audioManager.playSound("ClickButton");
                //跳转场景时清空当前的实体
                entityManager->clearAllEntities();
            }

            //在按钮"设置"的上方
            else if (settingsButton.isMouseOver(mousePosition)) {
                //将场景切换到设置界面
                stateManager.changeState(stateManager.createState("StateSetting"));
                audioManager.playSound("ClickButton");
                //跳转场景时清空当前的实体
                entityManager->clearAllEntities();
            }

            //在按钮关于的上方
            else if (aboutButton.isMouseOver(mousePosition)) {
                stateManager.changeState(stateManager.createState("StateAbout"));
                audioManager.playSound("ClickButton");
                //跳转场景时清空当前的实体
                entityManager->clearAllEntities();
            }

            //在按钮游戏玩法的上方
            else if (howToPlayButton.isMouseOver(mousePosition)) {
                stateManager.changeState(stateManager.createState("StateGameplay"));
                audioManager.playSound("ClickButton");
                //跳转场景时清空当前的实体
                entityManager->clearAllEntities();
            }

            //在按钮退出的上方
            else if (exitButton.isMouseOver(mousePosition)) {
                audioManager.playSound("ClickButton");
                window.close();
                return;
            }

            //在音乐开关的上方
            else if (musicButton.isMouseOver(mousePosition)) {
                audioManager.playSound("ClickButton");

                if (isMusic == true) {
                    //暂停播放音乐
                    audioManager.pauseMusic();
                    isMusic = false;
                }
                else {
                    //播放音乐
                    audioManager.resumeMusic();
                    isMusic = true;
                }
                return;
            }

        }

        //当鼠标移动时获取鼠标位置，判断是否在某一个按钮上面，是的话讲按钮改变颜色
        if (event.type == sf::Event::MouseMoved) {
            //返回true代表当前鼠标在当前"设置按钮上"
           
            //在开始游戏按钮的上方
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

            //在鉴赏模式按钮的上方
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

            //在设置按钮的上方
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

            //在关于按钮的上方
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

            //在游戏玩法按钮的上方
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

            //在退出按钮的上方
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

            //在音乐开关按钮的上方
            if (musicButton.isMouseOver(mousePosition)) {
                musicButton.onHover();
                if (!isSelectMusic) {
                    isSelectMusic = true;
                    audioManager.playSound("SelectButton");
                }
            }
            else
            {
                musicButton.resetColor();
                isSelectMusic = false;
            }

        }
    }

 
}

void StateMenu::update(float deltaTime)  {
    //更新当前窗口，主要是更新标题字
    /*
    负责人: 波波沙

    功能: 无

    参数:void

    返回值: void
    */
    //----------------------不需要实现------------------------//

    EntityManager::getInstance()->updateEntities(deltaTime);
}

void StateMenu::draw(sf::RenderWindow& window) {
    //渲染，渲染所有的按钮和背景图片等等。(未完成)
    /*
    负责人: 波波沙

    功能: 无

    参数:
        sf::RenderWindow& window    //需要渲染到的位置

    返回值: void
    */
    //----------------------实现------------------------//

    //渲染背景图
    window.draw(BackgroundImage);

    //调用对应按钮的渲染方法，将窗口下传。
    startButton.draw(window);
    galleryButton.draw(window);
    settingsButton.draw(window);
    aboutButton.draw(window);
    howToPlayButton.draw(window);
    exitButton.draw(window);
    musicButton.draw(window);

    //最后渲染标题动画
    EntityManager::getInstance()->drawEntities(window);
}

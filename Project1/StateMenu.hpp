#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "State.hpp"
#include "Button.hpp"
#include "StateManager.hpp"
#include "AssetManager.hpp"
#include "AudioManager.hpp"
#include "EntityManager.hpp"


// -------------------- 类设计 --------------------
/*
    【主菜单类】(未完成)
    负责人： 波波沙

    功能：
        实现游戏主菜单的功能
        1.显示背景图片
        2.显示多个按钮（新游戏，鉴赏模式，设置，玩法介绍，退出并保存）
        3.处理窗口事件（点击按钮事件）
        4.显示标题字

*/

class StateMenu : public State {
public:
    //构造方法，传入一个场景管理器的引用，方便调用场景管理器的方法。(未完成)
    StateMenu(StateManager& manager);

    //将当前发生的事件（主要是点击按钮的事件）进行处理，并且反馈操作到当前窗口中。复写基类方法。(未完成)
    void handleInput(sf::RenderWindow& window) override;

    //更新当前窗口，主窗口没有什么需要更新的。
    void update(float deltaTime) override;

    //渲染，渲染所有的按钮和背景图片等等。(未完成)
    void draw(sf::RenderWindow& window) override;

private:
    //场景管理器
    StateManager& stateManager;

    //主菜单的背景图片
    sf::Sprite BackgroundImage;

    //开始游戏的按钮
    Button startButton;
    //鉴赏模式
    Button galleryButton;
    //游戏设置的按钮
    Button settingsButton;
    //关于
    Button aboutButton;
    //游戏玩法
    Button howToPlayButton;
    //退出游戏
    Button exitButton;

    //是否选择按钮，用于播放音效
    bool isSelectStare;
    bool isSelectGallery;
    bool isSelectSettings;
    bool isSelectAbout;
    bool isSelectHowToPlay;
    bool isSelectExit;

    //...
    //...
    //...

};


#endif // MENUSTATE_HPP

#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"
#include "Button.hpp"
#include "StateManager.hpp"
#include "AssetManager.hpp"
#include "AudioManager.hpp"
#include "EntityManager.hpp"
#include "SettingsManager.hpp"
#include "EnemyFactory.hpp"
#include "Player.hpp"
#include <sstream>
#include <iomanip>
#include <string>

// -------------------- 类设计 --------------------
/*
    【游戏主场景类】(未完成)
    负责人： 波波沙

    功能：
        实现游戏主游戏场景的功能
        1.显示游戏背景
            游戏战斗界面的背景图片
            右边UI的背景矩形
            人物立绘
            立绘底下的一个灰色矩形
            一个技能的图标图片
            两个表示充能的绿色矩形
            一个在技能正下方的技能冷却条
            一个玩家的血条
            文本 时间
            文本 分数
            文本 玩家当前的力量值

        2.管理和更新游戏实体（如玩家角色，敌人，障碍物等）
        3.处理游戏逻辑（如玩家输入，碰撞检测等）
        4.渲染游戏实体和界面元素

        数据
            玩家是否开启了困难模式
            当前累计时间
            当前分数
*/

class StateMainGame : public State {
    friend class StateFailure;
public:
    //构造方法，传入一个场景管理器的引用，方便调用场景管理器的方法。(未完成)
    StateMainGame(StateManager& manager);

    //处理游戏逻辑，如玩家输入、碰撞检测等。(未完成)
    void handleInput(sf::RenderWindow& window) override;

    //更新游戏状态，如实体位置、游戏分数等。(未完成)
    void update(float deltaTime) override;

    //渲染游戏实体和界面元素。(未完成)
    void draw(sf::RenderWindow& window) override;

    //----------添加敌人---------//
    //                          //
    void ADDENEMYS();           //
    //                          //
    //----------添加敌人---------//

private:
    // 场景管理器
    StateManager& stateManager;

    // 游戏背景
    sf::Sprite gameBackground;

    // UI元素
    sf::RectangleShape uiBackground;        // 右边UI的背景矩形
    sf::Sprite characterPortrait;           // 人物立绘
    sf::RectangleShape portraitBackground;  // 立绘底下的灰色矩形
    sf::Sprite skillIcon;                   // 技能图标
    sf::RectangleShape energyBars1;         // 两个表示充能的绿色矩形
    sf::RectangleShape energyBars2;
    sf::RectangleShape skillCooldownBar;    // 技能冷却条
    sf::RectangleShape healthBar;           // 玩家血条
    sf::RectangleShape healthBarBackground; // 玩家血条底板
    sf::RectangleShape skillBar;            // 技能冷却条
    sf::RectangleShape skillBarBackground;  // 技能冷却条底板
    sf::RectangleShape ground;              // 暂停背景板
    sf::RectangleShape ground2;
    Button Continue;
    Button Return;

    // 文本元素
    sf::Text timeText;   // 显示时间
    sf::Text scoreText;  // 显示分数
    sf::Text powerText;  // 显示玩家当前的力量值
    sf::Text HP;         // 显示玩家血量
    sf::Text FPS;        // 显示当前游戏帧数


    // 游戏逻辑相关数据
    float elapsedTime;   // 当前累计时间(测试使用)
    bool isHardMode;     // 玩家是否开启了困难模式
    bool isBossMode;
    float fpsUpdateTime; // 累计时间，用于更新FPS显示
    float TOTALTIME;     // 总时间
    int score;           // 当前分数
    int power;
    int TIMEFORPLAY;     // 场景切换数值
    int ENEMYOUT2S;      // 小场景切换计数器
    float ENEMYOUT2STIME;// 小场景计时器
    //static float RecordTotalTime;//为结束场景记录最后时间
    bool isEXMode;       //玩家是否开启了EX模式

    int playerHealth;    //玩家的当前生命值
    int maxPlayerHealth; //玩家的生命上限

    float skillCD;       //技能CD
    float CDTime;        //当前累计的技能CD时间
    int skillCharging;   //技能充能点数
    float skillUseCd;    //技能间的释放CD
    float useTime;       //技能间的计时
    //...

    bool isEsc = false;          //是否进入暂停
    bool isContinue = false;
    bool isReturn = false;

};

#endif // GAMESTATE_HPP

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"
#include "EntityManager.hpp"
#include "Bullet.hpp"
#include "AudioManager.hpp"
#include <iostream>


// -------------------- 类设计 --------------------
/*
    【玩家类】（未完成）
    负责人： 波波沙

    功能：玩家
        1.移动
        2.接受事件
            .处理移动
            .处理攻击
        3.更新
            .生命恢复
            .道具效果（搁置）
        4.拥有道具(搁置)

*/

class Player : public Entity {
private:
    sf::Sprite sprite;             // 玩家角色的精灵
    sf::Sprite hitboxSprite;       // 判定点的精灵

    int health;                    // 生命值
    int maxHealth;                 // 生命值上限
    int strength;                  // 力量值
    float moveSpeed;               // 移动速度

    float accumulatedTime;         // 累计时间(攻击)
    float attackInterval;          // 攻击间隔
    float timeTohealth;            // 累计时间(生命再生)
    int healthRegenerationRate;    // 生命再生速度
    int skillCharging;             // 技能充能点数

    int atkBullet;                 // 子弹的伤害
    int helthBullet;               // 子弹的血量
    int speedBullet;               // 子弹的速度

    float TotalTime;
    int score;          // 分数
    bool isHard;        // 是否开启困难模式
    bool isGameOver;    // 是否通关
    bool isInvincible;  // 是否开启无敌模式
    bool isSkill;       // 是否可以释放技能

    //事件操作
    bool movingUp;      // 用于跟踪 上 键是否被按下
    bool movingDown;    // 用于跟踪 下 键是否被按下
    bool movingLeft;    // 用于跟踪 左 键是否被按下
    bool movingRight;   // 用于跟踪 右 键是否被按下
    bool slowMovement;  // 用于跟踪 Shift 键是否被按下
    bool openFire;      // 用于跟踪 Z 键是否被按下

public:

    //构造方法，手动创建
    Player();

    //更新
    void update(float deltaTime) override;

    //处理事件
    void handleInput(sf::Event& event);

    //渲染
    void draw(sf::RenderWindow& window) override;


    //返回判定点中心的位置
    sf::Vector2f getHitboxPosition() const;

    //开启困难模式！
    void hardCore();

    //开启无敌模式
    void Invincible();

    //设置玩家位置
    void setPosition(sf::Vector2f position);

    // 返回对玩家精灵的引用
    const sf::Sprite& getSprite() const;

    // 返回对玩家判定点的引用
    const sf::Sprite& getHitBox() const;

    // 获取玩家的分数
    int getScore() const;

    // 增加玩家的分数
    void addScore(int score);

    //获取玩家的力量值
    int getPower() {
        return strength;
    }

    // 增加玩家力量
    void addPower(int power);

    // 玩家受到伤害的方法
    void takeDamage(int damage);

    //获取玩家当前的生命值
    int getHealth();

    //获取玩家当前的生命上限
    int getMaxHealth();

    //设置玩家的技能点数
    void setSkill(int skill);

    //使用技能
    void SkillFire();

    //设置总时间
    void setTime(float time) {
        TotalTime = time;
    }

    //获取总时间
    float getTime() {
        return TotalTime;
    }

    // 玩家获胜
    void victory() {
        isGameOver = true;
    }

    //获取玩家是否获胜
    bool isVictory() {
        return isGameOver;
    }

    //获取玩家是否开启困难模式
    bool isHardCore() {
        return isHard;
    }

    // 设置和获取属性的方法
    // ...
};

#endif

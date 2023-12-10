#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include "EntityManager.hpp"
#include "Bullet.hpp"
#include "AssetManager.hpp"

// -------------------- 类设计 --------------------
/*
    【敌人基类】
    负责人： 波波沙

    功能：所有敌人的模板，精英怪也可以
        
*/

class Enemy : public Entity {
protected:
    sf::Sprite sprite;                  // 敌人的精灵
    int health;                         // 生命值
    sf::Vector2f direction;             // 移动方向
    float speed;                        // 移动速度

    float attackCooldown = 1.f;         // 攻击冷却时间
    float attackTimer = 0.f;            // 用于追踪攻击更新的计时器

public:
    // 构造函数，输入一个纹理，生命值，移动方向，速度
    Enemy(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd)
        : health(hp), direction(dir), speed(spd) {
        sprite.setTexture(texture);
    }

    // 返回对敌人精灵的引用
    const sf::Sprite& getSprite() const {
        return sprite;
    }

    // 敌人受到伤害的方法
    void takeDamage(int damage);

    // 纯虚函数，由子类实现
    //更新
    virtual void update(float deltaTime) = 0;
    //渲染
    virtual void draw(sf::RenderWindow& window) = 0;

    // 获取敌人的位置
    sf::Vector2f getPosition();

    //设置敌人的位置
    void setPosition(sf::Vector2f position);

    // 计算指向玩家的单位向量
    sf::Vector2f getDirectionTowardsPlayer();

    // 其他可能的方法...
};


// -------------------- 类设计 --------------------
/*
    【敌人类1】（未完成）
    负责人： 波波沙

    功能：一个小怪，攻击方式是垂直向下发射一颗弹幕

*/

class Enemy1 : public Enemy {
public:
    //构造方法,输入纹理，生命值，移动方向，速度
    Enemy1(const sf::Texture& texture,int hp, const sf::Vector2f& dir, float spd);

    //更新，实现敌人的移动和攻击（未完成）
    void update(float deltaTime) override;

    //渲染敌人
    void draw(sf::RenderWindow& window) override;
};

/*
    【敌人类2】（未完成）
    负责人： 马亚楠

    功能：自机狙，指向玩家攻击子弹

*/
class Enemy2 : public Enemy {
public:
    //构造方法,输入纹理，生命值，移动方向，速度
    Enemy2(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd);

    //更新，实现敌人的移动和攻击（未完成）
    void update(float deltaTime) override;

    //渲染敌人
    void draw(sf::RenderWindow& window) override;
};

/*
    【敌人类3】（未完成）
    负责人： 小杨

    功能：

*/
class Enemy3 : public Enemy {
public:
    //构造方法,输入纹理，生命值，移动方向，速度
    Enemy3(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd);

    //更新，实现敌人的移动和攻击（未完成）
    void update(float deltaTime) override;

    //渲染敌人
    void draw(sf::RenderWindow& window) override;
};

/*
    【敌人类4】（未完成）
    负责人： 小杨

    功能：

*/
class Enemy4 : public Enemy {
public:
    //构造方法,输入纹理，生命值，移动方向，速度
    Enemy4(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd);

    //更新，实现敌人的移动和攻击（未完成）
    void update(float deltaTime) override;

    //渲染敌人
    void draw(sf::RenderWindow& window) override;
};


/*
    【敌人类5】（未完成）
    负责人： 马亚楠

    功能：

*/
class Enemy5 : public Enemy {
public:
    //构造方法,输入纹理，生命值，移动方向，速度
    Enemy5(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd);

    //更新，实现敌人的移动和攻击（未完成）
    void update(float deltaTime) override;

    //渲染敌人
    void draw(sf::RenderWindow& window) override;
};

/*
    【敌人类6】（未完成）
    负责人： 马亚楠

    功能：

*/
class Enemy6 : public Enemy {
public:
    //构造方法,输入纹理，生命值，移动方向，速度
    Enemy6(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd);

    //更新，实现敌人的移动和攻击（未完成）
    void update(float deltaTime) override;

    //渲染敌人
    void draw(sf::RenderWindow& window) override;
};

/*
 【精英怪1】
  负责人：Tiant
  功能：多段移动，攻击方式多样

*/
class EliteEnemy1 :public Enemy {
public:
    //构造方法,输入纹理，生命值，移动方向，速度
    EliteEnemy1(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd);

    //更新，实现敌人的移动和攻击（未完成）
    void update(float deltaTime) override;

    //渲染敌人
    void draw(sf::RenderWindow& window) override;
private:
    //计算朝某一方向运动的时间，一旦达到特定值，则改变方向
    float timer;
    int SelectDirect;//选择移动的方向
    //更新攻击方式的时间
    float upgradeAttack;
    //选择攻击方式
    int SelectAttack;
};

/*
 【精英怪2】
  负责人：朱
  功能：多段移动，攻击方式多样

*/
class Spider :public Enemy {
public:
    //构造方法,输入纹理，生命值，移动方向，速度
    Spider(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd);

    //更新，实现敌人的移动和攻击（未完成）
    void update(float deltaTime) override;

    //渲染敌人
    void draw(sf::RenderWindow& window) override;
private:
    //判断是否进入红血第一阶段
    bool isInRedMode1;
    //判断是否进入红血第二阶段
    bool isInRedMode2;
    //记录敌人最大血量
    float MaxHealth;
    //计算朝某一方向运动的时间，一旦达到特定值，则改变方向
    float timer;
    //选择移动的方向
    int SelectDirect;
    //更新攻击方式的时间
    float upgradeAttack;
    //选择攻击方式
    int SelectAttack;
};

/*
 【史莱姆BOSS】
  负责人：波波沙
  功能：多段移动，攻击方式多样

*/
class BigSlime :public Enemy {
public:
    //构造方法,输入纹理，生命值，移动方向，速度
    BigSlime(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd);

    //更新，实现敌人的移动和攻击（未完成）
    void update(float deltaTime) override;

    //渲染敌人
    void draw(sf::RenderWindow& window) override;

    //移动到开始点
    void moveToPosition(sf::Vector2f targetPosition, float deltaTime);
private:
    //攻击模式
    int attackMode;
    //开火模式
    int FireMode;
    //记录敌人最大血量
    float MaxHealth;
    //计算存在总时间
    float timer;
    //每个攻击模式中的单独计时器
    float ModeTimer;
    //攻击角度偏差
    float angleOffset;

};

#endif

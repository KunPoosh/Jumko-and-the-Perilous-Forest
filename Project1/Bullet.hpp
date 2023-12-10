#ifndef BULLET_HPP
#define BULLET_HPP

#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include <typeinfo>
#include "Animation.hpp"

// -------------------- 类设计 --------------------
/*
    【子弹基类】
    负责人： 波波沙

    功能：
        所有子弹和拾取道具的基类，包括了必要的属性和方法

*/

class Bullet : public Entity {
protected:
    sf::Sprite sprite;         // 子弹的精灵
    sf::Vector2f direction;    // 子弹的方向
    float speed;               // 子弹的速度
    int health;                // 子弹的生命值
    int atk;                   // 子弹的伤害
    bool isHitPlayer;          // 判断是否击中玩家模型(擦弹判定用)

public:

    //构造方法，直接输入纹理，方向，速度，血量，攻击力
    Bullet(const sf::Texture& texture, const sf::Vector2f& dir, float spd, int hp, int atk)
        : direction(dir), speed(spd), health(hp) ,atk(atk){
        sprite.setTexture(texture);
        //将中心点设置到图片中心点
        sf::Vector2u textureSize = texture.getSize(); // 获取贴图的尺寸
        sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f); // 设置精灵的原点为贴图中心
        //设置角度
        setAngle();
        isHitPlayer = false;
    }

    // 将 update 和 draw 方法声明为纯虚函数
    //更新
    virtual void update(float deltaTime) = 0;
    //渲染
    virtual void draw(sf::RenderWindow& window) = 0;

    // 单独设置子弹的位置
    void setPosition(const sf::Vector2f& position);

    // 设置子弹图片的角度
    void setAngle();

    //返回子弹的精灵
    sf::Sprite& getSprite();

    //减少子弹的生命值
    void atkHealth(int atk);

    // 可以添加设置和获取子弹属性的虚方法
    // ...
};


// -------------------- 类设计 --------------------
/*
    【敌人子弹类1】
    负责人： 波波沙

    功能：
        只由敌人使用的一种子弹

*/

class EnemyBullet1 : public Bullet {
public:
    // 使用基类的构造函数
    using Bullet::Bullet;

    //更新子弹位置，输入间隔时间（未完成）
    void update(float deltaTime) override;
    //渲染子弹
    void draw(sf::RenderWindow& window) override;

    // 可以添加特定于敌人子弹的方法
    //...
};


// -------------------- 类设计 --------------------
/*
    【玩家子弹类1】
    负责人： 波波沙

    功能：
        只由玩家使用的一种子弹

*/

class PlayerBullet1 : public Bullet {
public:
    // 使用基类的构造函数
    using Bullet::Bullet;

    //更新
    void update(float deltaTime) override;
    //渲染
    void draw(sf::RenderWindow& window) override;

    // 如有需要，可以添加特定于玩家子弹的其他方法
};

// -------------------- 类设计 --------------------
/*
    【魔法子弹】
    负责人： 小柱

    功能：消除所有子弹的攻击
        

*/
class PlayerMagicBullet : public Bullet {
    using Bullet::Bullet;
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
};

//------------------力量道具类------------------
/*
    负责人: 朱

    功能:
        敌人被摧毁后 有概率爆出来， 拾取后增加玩家力量点
        该道具与玩家距离一定范围时候，被玩家吸附

    */
    //前向声明
class Player;
class PowerUpItem :virtual public Bullet, virtual private Animation {
public:
    //使用基类的构造函数
    using Bullet::Bullet;
    //更新子弹位置, 这个位置根据敌人摧毁的位置决定, 以delaTime的时间间隔下落
    void update(float deltaTime) override;
    //渲染力量道具
    void draw(sf::RenderWindow& window) override;
    //设置将道具的距离 设置成玩家的距离
    void setPosition(const sf::Vector2f& position) {
        sprite.setPosition(position);
    }
    //判断该道具与玩家的距离是否达到吸附距离
    bool isWithinDistance(const sf::Vector2f& playerPosition) {
        float distance = std::sqrtf(std::pow(playerPosition.x - getPosition().x, 2) + std::pow(playerPosition.y - getPosition().y, 2));
        isBeingAbsorbed = (distance <= maxDistance);
        return isBeingAbsorbed;
    }
    // 吸附到玩家身上的逻辑
    void adsorbToPlayer(const sf::Vector2f& playerPosition, float progress) {
        if (isWithinDistance(playerPosition)) {

            // 使用线性插值计算新位置
            sf::Vector2f newPosition = lerp(getPosition(), playerPosition, progress);
            setPosition(newPosition);
        }
    }
private:
    //吸附道具的阀值
    float maxDistance = 100.0f;
    //得到道具的实时距离
    sf::Vector2f getPosition() {
        return sprite.getPosition();
    }
    //动画时间
    float totaltime = 0.0f;
    // 是否正在被吸附
    bool isBeingAbsorbed = false;;
};

//-----------------点数道具类---------------------
/*
    负责人: 朱

    功能:
        敌人被摧毁后， 有概率爆出来 拾取后增加玩家分数
         该道具与玩家距离一定范围时候，被玩家吸附

    */
class ScorePointItem :virtual public Bullet, virtual private Animation {
public:
    //使用基类的构造函数
    using Bullet::Bullet;
    //更新子弹位置, 这个位置根据敌人摧毁的位置决定, 以delaTime的时间间隔下落
    void update(float deltaTime) override;
    //渲染分数道具
    void draw(sf::RenderWindow& window) override;
    //设置将道具的距离 设置成玩家的距离
    void setPosition(const sf::Vector2f& position) {
        sprite.setPosition(position);
    }
    //判断该道具与玩家的距离是否达到吸附距离
    bool isWithinDistance(const sf::Vector2f& playerPosition) {
        float distance = std::sqrtf(std::pow(playerPosition.x - getPosition().x, 2) + std::pow(playerPosition.y - getPosition().y, 2));
        isBeingAbsorbed = (distance <= maxDistance);
        return isBeingAbsorbed;
    }
    // 吸附到玩家身上的逻辑
    void adsorbToPlayer(const sf::Vector2f& playerPosition, float progress) {
        if (isWithinDistance(playerPosition)) {

            // 使用线性插值计算新位置
            sf::Vector2f newPosition = lerp(getPosition(), playerPosition, progress);
            setPosition(newPosition);
        }
    }
private:
    //吸附道具的阀值
    float maxDistance = 100.0f;
    //得到道具的实时距离
    sf::Vector2f getPosition() {
        return sprite.getPosition();
    }
    //动画时间
    float totaltime = 0.0f;
    // 是否正在被吸附
    bool isBeingAbsorbed = false;;
};


#endif

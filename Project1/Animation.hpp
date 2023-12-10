#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"

// -------------------- 类设计 --------------------
/*
    【动画基类】
    负责人： 波波沙

    功能：继承于实体，是所有动画的基类，只提供方法，因为不同动画要显示的东西是不一样的
*/

class Animation : public Entity {
protected:
    float totalTime;  // 用于动画的累积时间

public:

    //更新
    virtual void update(float deltaTime) = 0;
    //渲染
    virtual void draw(sf::RenderWindow& window) = 0;

    // 线性插值函数
    sf::Vector2f lerp(const sf::Vector2f& start, const sf::Vector2f& end, float progress);
};


// -------------------- 类设计 --------------------
/*
    【动画类1】
    负责人： 波波沙

    功能：显示标题的动画
*/
class TitleAnimation : public Animation {
private:
    //艺术字“酱可”
    sf::Sprite Pic1;
    //艺术字“与”
    sf::Sprite Pic2;
    //艺术字“危险之森”
    sf::Sprite Pic3;

    //结束时位置
    sf::Vector2f endPic1;
    sf::Vector2f endPic2;
    sf::Vector2f endPic3;

    // 动画总时间
    float animationDuration;
public:
    //构造方法
    TitleAnimation();

    //更新
    void update(float deltaTime) override;
    //渲染
    void draw(sf::RenderWindow& window) override;
};

// -------------------- 类设计 --------------------
/*
    【动画类2】
    负责人： 波波沙

    功能：屏幕闪红
*/
class FlashRedAnimation : public Animation {
private:
    sf::RectangleShape redSquare;   // 红色方块
    float animationDuration;        // 动画持续时间

public:
    FlashRedAnimation();

    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
};

#endif // ANIMATION_HPP

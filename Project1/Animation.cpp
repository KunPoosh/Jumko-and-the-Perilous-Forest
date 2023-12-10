#include "Animation.hpp"

sf::Vector2f Animation::lerp(const sf::Vector2f& start, const sf::Vector2f& end, float progress) {
    // 线性插值函数
    /*
    负责人: 波波沙

    功能:
        实现一个丝滑的移动

    参数:    
        const sf::Vector2f& start       //开始时的位置
        const sf::Vector2f& end         //结束时的位置
        float progress                  //0-1的值，表示处于中间过程的哪里

    返回值: sf::Vector2f
    */
    //----------------------实现------------------------//

    return start + (end - start) * progress;
}

TitleAnimation::TitleAnimation() {
    //召唤大哥
    /*
    负责人: 波波沙

    功能:
        构造方法,初始化标题动画的所有组件

    参数:
        void

    返回值: void
    */
    //----------------------实现------------------------//

    AssetManager& assetManager = AssetManager::getInstance();

    Pic1.setTexture(assetManager.getTexture("Title1"));
    Pic2.setTexture(assetManager.getTexture("Title2"));
    Pic3.setTexture(assetManager.getTexture("Title3"));

    Pic1.setPosition(-10, -10);
    Pic2.setPosition(280,120);
    Pic3.setPosition(450, 60);

    Pic1.setColor(sf::Color(255, 255, 255, 255));
    Pic2.setColor(sf::Color(255, 255, 255, 255));
    Pic3.setColor(sf::Color(255, 255, 255, 255));

    endPic1 = sf::Vector2f(30, 30);
    endPic2 = sf::Vector2f(280, 120);
    endPic3 = sf::Vector2f(350, 60);

    //动画持续时间
    animationDuration = 3.0f;

    //清空开始时的计数器
    totalTime = 0.f;
}

void TitleAnimation::update(float deltaTime) {
    //更新
    /*
    负责人: 波波沙

    功能:
        动画的更新方法，使动画动起来并且有一个渐出

    参数:
        float deltaTime //全局间隔时间

    返回值: void
    */
    //----------------------实现------------------------//

    totalTime += deltaTime;

     //计算动画进度的比例
    float progress = std::min(totalTime / animationDuration, 1.0f);

     //计算每个图片的新位置和透明度
    Pic1.setPosition(lerp(Pic1.getPosition(), endPic1, progress));
    Pic2.setPosition(lerp(Pic2.getPosition(), endPic2, progress));
    Pic3.setPosition(lerp(Pic3.getPosition(), endPic3, progress));

    int alpha = static_cast<int>(255 * progress);
    sf::Color color(255, 255, 255, alpha);
    Pic1.setColor(color);
    Pic2.setColor(color);
    Pic3.setColor(color);
}

void TitleAnimation::draw(sf::RenderWindow& window) {
    // 绘制当前动画帧
    /*
    负责人: 波波沙

    功能:
        按照特定的顺序去渲染动画

    参数:
        sf::RenderWindow& window    //需要渲染到的地方

    返回值: void
    */
    //----------------------实现------------------------//

    window.draw(Pic1);
    window.draw(Pic3);
    window.draw(Pic2);
}

FlashRedAnimation::FlashRedAnimation() {
    // 初始化红色方块
    redSquare.setSize(sf::Vector2f(960, 960)); // 设置大小为全屏
    redSquare.setFillColor(sf::Color(255, 0, 0, 128)); // 初始透明度为中等（128）

    // 动画持续时间
    animationDuration = 1.0f; // 比如动画持续1秒

    // 清空开始时的计数器
    totalTime = 0.f;
}

void FlashRedAnimation::update(float deltaTime) {
    totalTime += deltaTime;

    // 计算动画进度的比例
    float progress = std::min(totalTime / animationDuration, 1.0f);

    // 计算红色方块的新透明度
    int alpha = static_cast<int>(128 * (1 - progress)); // 透明度从128减少到0
    redSquare.setFillColor(sf::Color(255, 0, 0, alpha));
    //销毁
    if (totalTime >= animationDuration) {
        markForDestruction();
    }
}

void FlashRedAnimation::draw(sf::RenderWindow& window) {
    window.draw(redSquare);
}
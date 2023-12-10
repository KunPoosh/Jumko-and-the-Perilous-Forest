#ifndef ENEMYFACTORY_HPP
#define ENEMYFACTORY_HPP

#include "Enemy.hpp"
#include "EntityManager.hpp"
#include <string>
#include <memory>

// -------------------- 类设计 --------------------
/*
    【敌人工厂】（未完成）
    负责人： 波波沙

    功能：输入属性直接创建敌人并且加入到实体管理器中

*/

class EnemyFactory {
public:
    // 创建敌人的方法
    static void createEnemy(const std::string& type, const sf::Texture& texture,
        const sf::Vector2f& position, const sf::Vector2f& direction,
        int hp, float speed) {
        /*
            输入：
                1.敌人的名称，如"Enemy1"
                2.敌人的贴图，使用素材大哥去调用
                3.位置，一个Vector2f
                4.移动的方向，一个单位向量
                5.血量值
                6.速度值
        */
        /*
        负责人: 波波沙

        功能:
            静态方法，可以在任何地方生成一个敌人

        参数:
            如上

        返回值: void
        */
    //----------------------实现------------------------//

        std::shared_ptr<Enemy> enemy;

        if (type == "Enemy1") {
            enemy = std::make_shared<Enemy1>(texture, hp, direction, speed);
        }
        if (type == "Enemy2") {
            enemy = std::make_shared<Enemy2>(texture, hp, direction, speed);
        }
        if (type == "Enemy3") {
            enemy = std::make_shared<Enemy3>(texture, hp, direction, speed);
        }
        if (type == "Enemy4") {
            enemy = std::make_shared<Enemy4>(texture, hp, direction, speed);
        }
        if (type == "Enemy5") {
            enemy = std::make_shared<Enemy5>(texture, hp, direction, speed);
        }
        if (type == "Enemy6") {
            enemy = std::make_shared<Enemy6>(texture, hp, direction, speed);
        }
        if (type == "EliteEnemy1") {
            enemy = std::make_shared<EliteEnemy1>(texture, hp, direction, speed);
        }
        if (type == "Spider") {
            enemy = std::make_shared<Spider>(texture, hp, direction, speed);
        }
        if (type == "SilmeBoss") {
            enemy = std::make_shared<BigSlime>(texture, hp, direction, speed);
        }
        // 可以根据需要添加更多的敌人类型
        // else if (type == "Enemy2") { ... }

        if (enemy) {
            enemy->setPosition(position);
            EntityManager::getInstance()->addEnemy(enemy);
        }
    }
};

#endif

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

// -------------------- 类设计 --------------------
/*
	【实体类】
	负责人： 波波沙

	功能：
		一切实体的基类，提供必要方法
		1.更新
		2.渲染
*/

class Entity {
protected:
	//对象是否需要被销毁
	bool toBeDestroyed = false;
public:

	//更新
    virtual void update(float deltaTime) = 0;

	//渲染
    virtual void draw(sf::RenderWindow& window) = 0;

	bool isToBeDestroyed() const {
	//返回当前对象是否需要被销毁
		return toBeDestroyed;
	}

	void markForDestruction() {
	//使当前对象变得需要被销毁
		toBeDestroyed = true;
	}
};

#endif

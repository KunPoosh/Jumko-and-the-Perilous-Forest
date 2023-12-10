#ifndef STATE_HPP
#define STATE_HPP

#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>


// -------------------- 类设计 --------------------
/*
	【场景基类】
	负责人： 波波沙

	功能：
		是各种场景类的父类，包含了各种必要的虚函数。

*/

//向前声明
class StateManager;
class AssetManager;

class State {
public:

	//读取窗口的输入，处理窗口事件。
	virtual void handleInput(sf::RenderWindow& window) = 0;

	//在每一帧开始时更新场景的信息。
	virtual void update(float deltaTime) = 0;

	//渲染当前场景的所有需要渲染的对象。
	virtual void draw(sf::RenderWindow& window) = 0;

protected:

};


#endif

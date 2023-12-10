#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "State.hpp"
#include "AssetManager.hpp"

// -------------------- 类设计 --------------------
/*
	【场景管理类】(未完成)
	负责人： 波波沙

	功能：管理所有的场景
		1.切换场景
		2.更新场景
		3.将窗口和事件下传更新场景，事件处理
		4.渲染场景
*/

//向前声明,要不然编译器不认识你这个类，但是不能引用头文件，要不然会循环引用。头文件在对应类的cpp文件里面去引用
class StateMenu;
class StateSetting;
class StateStartGame;
class StateSelectDifficulty;
class StateAbout;
class StateGameplay;
class StateGamePlay2;
class StateAppreciate;
class StateAppreciate2;
class MagnifyAppreciate;
class StateAppreciate2;
class StateMainGame;
class StateFailure;
class OpenFailureCG;
class StateVictory;
class OpenVictoryCG;


class StateManager {
public:

	//切换场景，使用一个智能指针
	void changeState(std::unique_ptr<State> newState);

	//创建一个场景，根据输入的String来决定要创造什么场景（未完成）
	std::unique_ptr<State> createState(const std::string& stateType);

	//更新
	void updateCurrentState(float deltaTime);

	//下传窗口
	void handleInputCurrentState(sf::RenderWindow& window);

	//渲染
	void drawCurrentState(sf::RenderWindow& window);

private:
	//当前的场景！！！
	std::unique_ptr<State> currentState;
};

#endif // STATEMANAGER_HPP

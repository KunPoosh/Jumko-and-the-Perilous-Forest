#include "StateManager.hpp"
#include "StateSetting.hpp"
#include "StateMenu.hpp"
#include "StateStarGame.hpp"
#include "StateAbout.hpp"
#include "StateGameplay.hpp"
#include "StateAppreciate.hpp"
#include "StateMainGame.hpp"
#include "StateFailure.hpp"
#include "StateVictory.hpp"

void StateManager::changeState(std::unique_ptr<State> newState) {
	//切换场景，使用一个智能指针
	/*
	负责人: 波波沙

	功能: 切换场景

	参数:
		std::unique_ptr<State> newState     //一个指向场景对象的智能指针

	返回值: void
	*/
	//----------------------实现------------------------//

	//将当前的场景切换成新的场景，一个智能指针指向的场景
	currentState = std::move(newState);
}

std::unique_ptr<State> StateManager::createState(const std::string& stateType) {
	//创建一个场景，根据输入的String来决定要创造什么场景
	/*
	负责人: 波波沙

	功能: 创造需要的场景

	参数:
		const std::string& stateType     //一个String，他因该是一个场景的名字

	返回值: std::unique_ptr<State>
	*/
	//----------------------实现------------------------//

	//当输入"StateSetting"的时候创建一个设置界面的场景并且返回。
	if (stateType == "StateSetting") {
		//创建智能指针
		return std::make_unique<StateSetting>(*this);
	}

	//创建开始游戏的界面
	if (stateType == "StateStarGame") {
		return std::make_unique<StateStartGame>(*this);
	}

	//开始游戏！！！！
	if (stateType == "NewGame") {
		return std::make_unique<StateMainGame>(*this);
	}

	//鉴赏模式的界面
	if (stateType == "Appreciate") {
		return std::make_unique<StateAppreciate>(*this);
	}

	//鉴赏模式第二页
	if (stateType == "Appreciate2") {
		return std::make_unique<StateAppreciate2>(*this);
	}

	//展现图片界面
	if (stateType == "MagnifyAppreciate") {
		return std::make_unique<MagnifyAppreciate>(*this);
	}
	
	//展现图片界面2
	if (stateType == "MagnifyAppreciate2") {
		return std::make_unique<MagnifyAppreciate2>(*this);
	}

	//"关于"界面
	if (stateType == "StateAbout") {
		return std::make_unique<StateAbout>(*this);
	}

	//游戏玩法界面
	if (stateType == "StateGameplay") {
		return std::make_unique<StateGameplay>(*this);
	}

	//游戏玩法界面第二页
	if (stateType == "StateGameplay2") {
		return std::make_unique<StateGameplay2>(*this);
	}

	//选择难度场景
	if (stateType == "StateSelectDifficulty") {
		return std::make_unique<StateSelectDifficulty>(*this);
	}

	//战败结算界面
	if (stateType == "StateFailure") {
		return std::make_unique<StateFailure>(*this);
	}

	//战败CG界面
	if (stateType == "OpenFailureCG") {
		return std::make_unique<OpenFailureCG>(*this);
	}

	//获胜结算界面
	if (stateType == "StateVictory") {
		return std::make_unique<StateVictory>(*this);
	}

	//获胜CG界面
	if (stateType == "OpenVictoryCG") {
		return std::make_unique<OpenVictoryCG>(*this);
	}


	// ... 其他状态的创建逻辑

}

void StateManager::updateCurrentState(float deltaTime) {
	//更新场景
	/*
	负责人: 波波沙

	功能: 每一帧更新一次场景

	参数:void

	返回值: void
	*/
	//----------------------实现------------------------//

	if (currentState) {
		currentState->update(deltaTime);
	}
}

void StateManager::handleInputCurrentState(sf::RenderWindow& window) {
	//下传窗口
	/*
	负责人: 波波沙

	功能: 将当前场景窗口下传，用来处理事件等。

	参数:
		sf::RenderWindow& window    //用了下传的窗口

	返回值: void
	*/
	//----------------------实现------------------------//

	if (currentState) {
		currentState->handleInput(window);
	}
}

void  StateManager::drawCurrentState(sf::RenderWindow& window) {
	//渲染场景
	/*
	负责人: 波波沙

	功能: 渲染当前场景的所有需要渲染的东西

	参数:
		sf::RenderWindow& window    //要渲染到的地方

	返回值: void
	*/
	//----------------------实现------------------------//

	if (currentState) {
		currentState->draw(window);
	}
}
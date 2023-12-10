#ifndef STATESTARE_HPP
#define STATESTARE_HPP

#include "Button.hpp"
#include "StateManager.hpp"
#include "State.hpp"
#include "AssetManager.hpp"
#include "AudioManager.hpp"
#include "SettingsManager.hpp"


// -------------------- 类设计 --------------------
/*
	【开始界面类】
	负责人：波波沙

	功能：播放开场动画，调转到选择难度场景
*/

class StateStartGame : public State {
public:
	//构造方法
	StateStartGame(StateManager& manager);

	//处理输入的事件
	void handleInput(sf::RenderWindow& window) override;

	//更新（未完成）
	void update(float deltaTime) override;

	//渲染（未完成）
	void draw(sf::RenderWindow& window) override;

private:
	//常见管理器的引用
	StateManager& stateManager;

	//下一步按钮
	Button Next;
	
	//一张图片
	sf::Sprite Pic1;
	//一段文字
	sf::Text text1;
	sf::Text text2;
	sf::Text text3;
	sf::Text text4;

	//计时器
	float TotalTime;

	//多久显示完成
	float animationDuration;

	
};

// -------------------- 类设计 --------------------
/*
	【选择难度类】
	负责人：波波沙

	功能：两个难度选一个，并且传入场景
*/
class StateSelectDifficulty : public State {
public:
	// 构造方法
	StateSelectDifficulty(StateManager& manager);

	// 处理输入的事件
	void handleInput(sf::RenderWindow& window) override;

	// 更新（未完成）
	void update(float deltaTime) override;

	// 渲染（未完成）
	void draw(sf::RenderWindow& window) override;

private:
	// 状态管理器的引用
	StateManager& stateManager;

	// 选择难度的按钮
	Button easyButton;
	Button hardButton;

	//是否播放过音效
	bool isEasyButton;
	bool ishardButton;

	// 显示难度选择的文字
	sf::Text difficultyText;

	// 可能需要的其他成员变量...
};

#endif

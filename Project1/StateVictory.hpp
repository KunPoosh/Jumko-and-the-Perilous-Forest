#ifndef STATEVICTORY_HPP
#define STATEVICTORY_HPP

#include"State.hpp"
#include"Button.hpp"
#include"StateManager.hpp"
#include"AssetManager.hpp"
#include "AudioManager.hpp"
#include"SettingsManager.hpp"
#include "EntityManager.hpp"
#include"Player.hpp"
#include<iostream>
#include <sstream>
#include <iomanip>
#include <string>

/*
   【胜利界面】
   负责人：Tiant
   功能：当玩家打赢BOSS通关后，显示玩家所用总时间和所得分数
		 根据玩家选择的简单或困难模式打开相应的CG图

*/
class OpenVictoryCG;
class StateVictory :public State
{
	friend class OpenVictoryCG;
public:
	//构造方法
	StateVictory(StateManager& manager);
	//处理输入的事件（未完成）
	void handleInput(sf::RenderWindow& window) override;

	//更新（未完成）
	void update(float deltaTime) override;

	//渲染（未完成）
	void draw(sf::RenderWindow& window) override;
private:
	//常见管理器的引用
	StateManager& stateManager;
	//主菜单的背景图片
	sf::Sprite BackgroundImage;
	//文本元素
	sf::Text endText;//结束文本
	sf::Text timeText;//显示最后所花费时间
	sf::Text scoreText;//显示最后的得分
	//下一页按钮:用来打开CG图
	Button Next;
	int EndScore;//最后得分
	float TotalTime;//最后所花费时间
	static bool isHard;//判断玩家是否在困难模式下通关
};

class OpenVictoryCG :public State
{
public:
	//构造方法
	OpenVictoryCG(StateManager& manager);

	//处理输入的事件
	void handleInput(sf::RenderWindow& window) override;

	//更新
	void update(float deltaTime) override;

	//渲染
	void draw(sf::RenderWindow& window) override;
private:
	//常见管理器的引用
	StateManager& stateManager;
	//返回按钮
	Button home;
	//要打开的胜利CG图
	sf::Sprite VictoryCG1;//简单模式的胜利CG图
	sf::Sprite VictoryCG2;//困难模式的胜利CG图
};
#endif // !STATEVICTORY_HPP

#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Button.hpp"
#include "StateManager.hpp"
#include "AssetManager.hpp"
// -------------------- 类设计 --------------------
/*
	【游戏玩法场景类】（未完成）
	负责人：朱
	功能：实现游戏玩法界面的功能
	1.显示返回按钮
	2.显示一些图片，和游戏玩法介绍(文字啥的 都由我们手动画出)
	3.处理点击和触碰按钮的相关事件响应
	4.显示标题字
*/
class StateGameplay : public State {
public:
	//构造方法
	StateGameplay(StateManager& manager);

	//处理输入的事件
	void handleInput(sf::RenderWindow& window) override;

	//更新
	void update(float deltaTime) override;

	//渲染
	void draw(sf::RenderWindow& window) override;
private:
	//管理器的引用
	StateManager& stateManager;
	//返回按钮
	Button home;
	//下一页按钮
	Button Next;
	//上一页按钮
	Button Back;
	//标题
	sf::Text title;
	//主菜单的背景图片
	sf::Sprite BackgroundImage;
	//用于显示玩法介绍图片
	sf::Sprite Introduction1;
	sf::Sprite Introduction2;
	sf::Sprite Introduction3;
	sf::Sprite Introduction4;
};

// --------------游戏界面第二页的设计--------------
class StateGameplay2 : public State {
public:
	//构造方法
	StateGameplay2(StateManager& manager);

	//处理输入的事件
	void handleInput(sf::RenderWindow& window) override;

	//更新
	void update(float deltaTime) override;

	//渲染
	void draw(sf::RenderWindow& window) override;
private:
	//管理器的引用
	StateManager& stateManager;
	//返回按钮
	Button home;
	//下一页按钮
	Button Next;
	//上一页按钮
	Button Back;
	//标题
	sf::Text title;
	//主菜单的背景图片
	sf::Sprite BackgroundImage;
	//用于显示玩法介绍图片
	sf::Sprite Introduction1;
	sf::Sprite Introduction2;
	sf::Sprite Introduction3;
	sf::Sprite Introduction4;
};

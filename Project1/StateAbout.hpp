#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "StateManager.hpp"
#include "Button.hpp"
#include "AssetManager.hpp"
// -------------------- 类设计 --------------------
/*
	【关于场景类】（未完成）
	负责人：朱

	功能：实现关于界面的功能
	1.显示返回按钮
	2.显示团队开发人员以及所负责的模块
	3.处理点击和触碰按钮的相关事件响应
	4.显示标题字
*/
class StateAbout : public State {
public:
	//构造方法
	StateAbout(StateManager& manager);

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
	//标题
	sf::Text title;
	//主菜单的背景图片
	sf::Sprite BackgroundImage;
	//用来直接贴我们人员的图片
	sf::Sprite About;
	//设置我的项目按钮
	sf::Text visitLink;
};
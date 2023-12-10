#ifndef APPRECIATE_HPP
#define APPRECIATE_HPP

#include"Button.hpp"
#include"State.hpp"
#include"AssetManager.hpp"
#include"StateManager.hpp"
#include "AudioManager.hpp"
#include"SettingsManager.hpp"

// -------------------- 类设计 --------------------
/*
	【鉴赏场景类】（未完成）
	负责人：Tiant

	功能：实现鉴赏界面的功能
*/
//鉴赏类1
class StateAppreciate :public State
{
public:

	//构造方法
	StateAppreciate(StateManager& manager);


	//处理输入的事件（未完成）
	void handleInput(sf::RenderWindow& window) override;

	//更新（未完成）
	void update(float deltaTime) override;

	//渲染（未完成）
	void draw(sf::RenderWindow& window) override;
private:
	//常见管理器的引用
	StateManager& stateManager;

	//返回按钮
	Button home;
	//下一页按钮
	Button Next;
	// 上一页按钮
	Button Prior;
	//标题字
	sf::Text title;
	//主菜单的背景图片
	sf::Sprite BackgroundImage;

	//矩形圆角框
	sf::RectangleShape roundedRect1;
	sf::RectangleShape roundedRect2;
	sf::RectangleShape roundedRect3;
	sf::RectangleShape roundedRect4;
	sf::RectangleShape roundedRect5;
	sf::RectangleShape roundedRect6;

protected:
	//所要鉴赏的图片精灵
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	sf::Sprite sprite3;
	sf::Sprite sprite4;
	sf::Sprite sprite5;
	sf::Sprite sprite6;
	//覆盖鉴赏图片精灵的背景图
	sf::Sprite CGBackground1;
	sf::Sprite CGBackground2;
	sf::Sprite CGBackground3;
	sf::Sprite CGBackground4;
	sf::Sprite CGBackground5;
	sf::Sprite CGBackground6;

	//控制点击第几张图片就生成哪张图片场景的静态成员
	static int SelectImage;
};
//-------------------------------------------------------------
//鉴赏界面2
class StateAppreciate2 :public State
{
public:

	//构造方法
	StateAppreciate2(StateManager& manager);


	//处理输入的事件（未完成）
	void handleInput(sf::RenderWindow& window) override;

	//更新（未完成）
	void update(float deltaTime) override;

	//渲染（未完成）
	void draw(sf::RenderWindow& window) override;
private:
	//常见管理器的引用
	StateManager& stateManager;


	//下一页按钮
	Button Next;
	// 上一页按钮
	Button Prior;
	//标题字
	sf::Text title;
	//主菜单的背景图片
	sf::Sprite BackgroundImage;

	//矩形圆角框
	sf::RectangleShape roundedRect7;
	sf::RectangleShape roundedRect8;
	sf::RectangleShape roundedRect9;
	sf::RectangleShape roundedRect10;
	sf::RectangleShape roundedRect11;
	sf::RectangleShape roundedRect12;
protected:
	/*图片精灵*/
	sf::Sprite sprite7;
	sf::Sprite sprite8;
	sf::Sprite sprite9;
	sf::Sprite sprite10;
	sf::Sprite sprite11;
	sf::Sprite sprite12;
	//覆盖鉴赏图片精灵的背景图
	sf::Sprite CGBackground7;
	sf::Sprite CGBackground8;
	sf::Sprite CGBackground9;
	sf::Sprite CGBackground10;
	sf::Sprite CGBackground11;
	sf::Sprite CGBackground12;
	//控制点击第几张图片就生成哪张图片场景的静态成员
	static int SelectImage2;
};
//---------------------------------------------------------------------------
//打开图片的类
class MagnifyAppreciate :public StateAppreciate
{
public:
	//构造方法
	MagnifyAppreciate(StateManager& manager);

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
};

//--------------------------------------------------------------------------
//仿照MagnifyAppreciate建立MagnifyAppreciate2来打开Appreciate2的图片
class MagnifyAppreciate2 :public StateAppreciate2
{
public:
	//构造方法
	MagnifyAppreciate2(StateManager& manager);

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
};

#endif 

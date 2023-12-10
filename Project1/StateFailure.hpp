#ifndef STATEFAILURE_HPP
#define STATEFAILURE_HPP

/*
   【失败界面】
   负责人：Tiant
   功能：当玩家血条归零时跳转到失败场景，显示玩家所用总时间和所得分数
		 随机打开一张战败CG图片

*/
#include"Button.hpp"
#include"State.hpp"
#include"AssetManager.hpp"
#include"StateManager.hpp"
#include "AudioManager.hpp"
#include"StateMainGame.hpp"
#include"Player.hpp"
#include "EntityManager.hpp"
#include"SettingsManager.hpp"
#include <sstream>
#include <iomanip>
#include <string>
//向前声明
class OpenFailureCG;
class StateFailure :public State
{
	friend class OpenFailureCG;
public:
	//构造方法
	StateFailure(StateManager& manager);
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
	static int SelectFailureCG;//选择战败CG图（最后确定要打开的战败CG图的值1-10）
	int UnlockFailureCG;//随机解锁的战败CG图（目标想要解锁的战败CG图的值1-10）
	bool isUnlock;//判断这次失败是否成功解锁战败CG图
};

class OpenFailureCG :public State
{
public:
	//构造方法
	OpenFailureCG(StateManager& manager);

	//处理输入的事件
	void handleInput(sf::RenderWindow& window) override;

	//更新
	void update(float deltaTime) override;

	//渲染
	void draw(sf::RenderWindow& window) override;
private:
	//常见管理器的引用
	StateManager& stateManager;
	//文本
	sf::Text GameOver;
	//返回按钮
	Button home;
	//要打开的战败CG
	sf::Sprite FailureCG1;
	sf::Sprite FailureCG2;
	sf::Sprite FailureCG3;
	sf::Sprite FailureCG4;
	sf::Sprite FailureCG5;
	sf::Sprite FailureCG6;
	sf::Sprite FailureCG7;
	sf::Sprite FailureCG8;
	sf::Sprite FailureCG9;
	sf::Sprite FailureCG10;
	int SelectFailureCG;//选择战败CG图
};
#endif // !STATEFAILURE

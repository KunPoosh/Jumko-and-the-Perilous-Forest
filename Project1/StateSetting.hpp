#ifndef WINDOW1STATE_HPP
#define WINDOW1STATE_HPP

#include "Button.hpp"
#include "StateManager.hpp"
#include "State.hpp"
#include "AssetManager.hpp"


// -------------------- 类设计 --------------------
/*
	【设置场景类】（未完成）
	负责人：

	功能：实现设置界面的功能
*/

class StateSetting : public State {
public:
	//构造方法（未完成）
	StateSetting(StateManager& manager);

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
	//标题字
	sf::Text title;
	//音乐音量
	sf::Text MusicVolume;
	//音效音量
	sf::Text SoundVolume;
	//无敌模式
	sf::Text Mod;
	//音量条
	sf::RectangleShape Background1;
	sf::RectangleShape VolumeBar1;
	sf::CircleShape VolumeBall1;
	sf::Text MusicText;
	//音效条
	sf::RectangleShape Background2;
	sf::RectangleShape VolumeBar2;
	sf::CircleShape VolumeBall2;
	sf::Text SoundText;
	//无敌模式
	sf::RectangleShape ModBar;
	sf::RectangleShape Background3;
	sf::CircleShape ModBall;
	//主菜单的背景图片
	sf::Sprite BackgroundImage;
	//键位调整
	sf::Text wasd;
	sf::Text not_wasd;
	sf::CircleShape wasd_shape;
	sf::CircleShape not_wasd_shape;
	sf::CircleShape wasd_ball;
	sf::CircleShape not_wasd_ball;
};

#endif // WINDOW1STATE

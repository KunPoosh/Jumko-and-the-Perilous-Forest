#ifndef BUTTON_HPP
#define BUTTON_HPP

#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING

#include <locale>
#include <codecvt>

#include <SFML/Graphics.hpp>

// -------------------- 类设计 --------------------
/*
	【按钮类】
	负责人： 波波沙

	功能：
		实现按钮的功能：
		0.初始化设置按钮的大小，位置，文本，字体。
		1.按钮的形状背景，边框。
		2.悬停时改变颜色。
		3.返回当前是否被点击。
		4.返回按钮当前的位置。
		5.渲染自身。
*/

class Button {
public:
	//空构造方法。
	Button();

	//渲染按钮所有内容。
	void draw(sf::RenderWindow& window);

	//判断当前window中的鼠标是否在按钮的上方。
	bool isMouseOver(sf::Vector2f mousePos);

	//设置按钮颜色，内框，外框，选中时
	void setColor(sf::Color insideColor, sf::Color outsideColor, sf::Color chosenColor);

	//设置按钮的位置,大小
	void setPosition(float x, float y, float width, float height);

	//设置按钮的字体和内容和颜色
	void setFont(const sf::Font& font, sf::Color fontColor, const std::wstring& content, unsigned int characterSize);

	//悬停时改变按钮的颜色。
	void onHover();

	//将颜色设置回初始化时的颜色。
	void resetColor();

	//向上返回当前按钮判定的边界（测试用）。
	sf::FloatRect getBounds() const;

private:



	//SFML的矩形类，是按钮的主体。
	sf::RectangleShape shape;

	//按钮的边框
	sf::RectangleShape frameShape;

	//SFML的Text类，用来显示按钮的文字。
	sf::Text text;

	//SFML的颜色类，内框颜色
	sf::Color colorInSide;

	//外框颜色
	sf::Color colorOutSide;

	//选择时的颜色
	sf::Color colorChose;


};

#endif

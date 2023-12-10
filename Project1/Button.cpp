#include "Button.hpp"

Button::Button() {
	//空构造方法。
	/*
	负责人: 波波沙

	功能:
		不让程序报错。

	参数: void

	返回值: Button
	*/
	//----------------------实现------------------------//
}

void Button::draw(sf::RenderWindow& window) {
	//渲染按钮所有内容。
	/*
	负责人: 波波沙

	功能:
		将当前按钮的所有信息渲染到窗口缓冲中。

	参数:
		sf::RenderWindow& window    //要渲染到的地方。

	返回值: void
	*/
	//----------------------实现------------------------//

	//渲染背景图形。
	window.draw(frameShape);
	window.draw(shape);
	//渲染文字。
	window.draw(text);
}

bool Button::isMouseOver(sf::Vector2f mousePos) {
	//判断当前window中的鼠标是否在按钮的上方。
	/*
	负责人: 波波沙

	功能:
		判断窗口中的鼠标是否在按钮图形的上方。

	参数:
		sf::RenderWindow& window    //要获取鼠标信息的地方。

	返回值: bool
	*/
	//----------------------实现------------------------//

	//获取鼠标的坐标
	//sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	//获取按钮的全局边界，存储到一个矩形类中。
	sf::FloatRect bounds = shape.getGlobalBounds();
	//先将鼠标坐标转化成Vector2f向量，然后调用FloatRect的方法判断点是否在矩形中，是则返回true，反之返回false.
	return bounds.contains(static_cast<sf::Vector2f>(mousePos));
}

void Button::onHover() {
	//悬停时改变按钮的颜色。
	/*
	负责人: 波波沙

	功能:
		把按钮图形的颜色改变，让用户知道自己选中了这个按钮。

	参数:
		void

	返回值: void
	*/
	//----------------------实现------------------------//

	//设置按钮颜色。
	shape.setFillColor(colorChose);
}

void Button::resetColor() {
	//将颜色设置回初始化时的颜色。
	/*
	负责人: 波波沙

	功能:
		当鼠标离开按钮时恢复颜色。

	参数:
		void

	返回值: void
	*/
	//----------------------实现------------------------//

	//设置按钮颜色。
	shape.setFillColor(colorInSide);
}

sf::FloatRect Button::getBounds() const {
	//向上返回当前按钮判定的边界（测试用）。
	/*
	负责人: 波波沙

	功能:
		将当前按钮的全局边界信息向上返回，用于调试。

	参数:
		void

	返回值: sf::FloatRect
	*/
	//----------------------实现------------------------//

	//获取按钮图形的全局边界并且返回。
	return shape.getGlobalBounds();
}

void Button::setColor(sf::Color insideColor, sf::Color outsideColor, sf::Color chosenColor) {
	//设置按钮颜色，内框，外框，选中时
	/*
	负责人: 波波沙

	功能:
		设置三个关于按钮的颜色

	参数:
		sf::Color insideColor   //内框颜色和透明度
		sf::Color outsideColor  //外框颜色和透明度
		sf::Color chosenColor   //选中时的颜色和透明度

	返回值: void
	*/
	//----------------------实现------------------------//

	//设置三个对应的颜色
	colorInSide = insideColor;
	colorOutSide = outsideColor;
	colorChose = chosenColor;

	shape.setFillColor(colorInSide); // 设置内框颜色
	frameShape.setFillColor(colorOutSide); // 设置外框颜色
}

void Button::setPosition(float x, float y, float width, float height) {
	//设置按钮的位置,大小
	/*
	负责人: 波波沙

	功能:
		设置按钮的位置,大小

	参数:
		float x         //按钮的x轴位置
		float y         //按钮的y轴位置
		float width     //按钮的宽度
		float height    //按钮的高度

	返回值: void
	*/
	//----------------------实现------------------------//

	// 设置内框位置和大小
	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(width, height));

	// 外框相对于内框四周均匀扩大10像素
	float borderWidth = 3;
	frameShape.setPosition(x - borderWidth, y - borderWidth);
	frameShape.setSize(sf::Vector2f(width + 2 * borderWidth, height + 2 * borderWidth));

	// 重新设置文本位置，以保证其在按钮中居中
	float textX = x + (width - text.getLocalBounds().width) / 2;
	float textY = y + (height - text.getLocalBounds().height) / 2 - text.getLocalBounds().top;

	text.setPosition(textX, textY);
}


void Button::setFont(const sf::Font& font, sf::Color fontColor, const std::wstring& content, unsigned int characterSize) {
	//设置按钮的字体和内容
	/*
	负责人: 波波沙

	功能:
		设置按钮的位置,大小

	参数:
		const sf::Font& font        //设置字体
		const std::string& content  //设置内容
		unsigned int characterSize  //设置字号
		sf::Color fontColor         //设置颜色

	返回值: void
	*/
	//----------------------实现------------------------//

	//设置字体，内容，字号，颜色
	text.setFont(font);
	text.setString(content);
	text.setCharacterSize(characterSize);
	text.setFillColor(fontColor);
}
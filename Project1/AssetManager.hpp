#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>

// -------------------- 类设计 --------------------
/*
	【素材管理类】
	负责人： 波波沙

	功能：单例模式，存储所有的图片和字体素材
		1.读取所有的素材
		2.在需要的地方随时使用
*/

class AssetManager {
private:

	// 私有构造函数和赋值运算符确保单例
	AssetManager();
	AssetManager(const AssetManager&) = delete;
	AssetManager& operator=(const AssetManager&) = delete;

	// 存储资源的容器
	//储存所有的纹理
	std::map<std::string, sf::Texture> textures;
	//储存所有的字体
	std::map<std::string, sf::Font> fonts;

public:
	// 获取单例的静态方法
	static AssetManager& getInstance() {
		static AssetManager instance;
		return instance;
	}

	// 资源加载函数
	void loadTexture(const std::string& name, const std::string& filename);
	void loadFont(const std::string& name, const std::string& filename);

	// 资源获取函数
	sf::Texture& getTexture(const std::string& name);
	sf::Font& getFont(const std::string& name);
};

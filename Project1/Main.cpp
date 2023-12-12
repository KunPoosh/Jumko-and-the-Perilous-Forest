#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "StateManager.hpp"
#include "StateMenu.hpp"
#include "StateSetting.hpp"
#include "AssetManager.hpp"
#include "AudioManager.hpp"
#include "SettingsManager.hpp"
#include "EntityManager.hpp"

int main() {
	//程序入口
	/*
	负责人: 波波沙

	功能:
		运行程序基本逻辑

	参数: void

	返回值: int
	*/
	//----------------------实现------------------------//

	//创建窗口
	sf::RenderWindow window(sf::VideoMode(960, 960), L"酱可与危险之森");
	//限制游戏帧率上限为200FPS
	window.setFramerateLimit(200);


	//创建场景管理器
	StateManager stateManager;

	// 初始化EntityManager单例
	EntityManager* entityManager = EntityManager::getInstance();

	//使用音频管理器
	AudioManager& audioManager = AudioManager::getInstance();

	//使用文件管理器
	SettingsManager& settingsManager = SettingsManager::getInstance();

	//将场景管理器初始化场景设置为主界面(使用智能指针)
	stateManager.changeState(std::make_unique<StateMenu>(stateManager));
	//默认初始播放BGM
	audioManager.playMusic("MenuMusic1", true);

	//读取一次存档
	settingsManager.loadSettings("Asset/save.txt");
	audioManager.setSoundVolume(settingsManager.soundVolume / 100.f);
	audioManager.setMusicVolume(settingsManager.musicVolume / 100.f);

	//创建全局时钟
	sf::Clock clock;

	//初始随机数
	srand(time(NULL));

	//----------------游戏主循环------------------//
	while (window.isOpen()) {
		//统一时间
		float deltaTime = clock.restart().asSeconds();

		//将窗口下传
		stateManager.handleInputCurrentState(window);

		//进行场景的普通的每帧更新
		stateManager.updateCurrentState(deltaTime);

		//清理播放的音效
		audioManager.update();

		//清空缓冲
		window.clear();

		//渲染当前场景的内容
		stateManager.drawCurrentState(window);

		//显示渲染完成的场景
		window.display();
	}

	return 0;
}






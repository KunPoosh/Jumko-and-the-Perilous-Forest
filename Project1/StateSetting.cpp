#include "StateSetting.hpp"
#include "StateMenu.hpp"
#include "SettingsManager.hpp"

StateSetting::StateSetting(StateManager& manager) : stateManager(manager) {
	//构造方法
	/*
	负责人: 小柱

	功能:
		初始化设置场景
			设置字体
			设置音乐条

	参数:
		StateManager& manager    //窗口管理器

	返回值: StateSetting
	*/
	//----------------------实现------------------------//

	//音效，素材管理器单例
	AssetManager& assetManager = AssetManager::getInstance();
	AudioManager& audioManager = AudioManager::getInstance();
	SettingsManager& settingsManager = SettingsManager::getInstance();
	//设置"设置"按钮的位置等信息。
	home.setFont(assetManager.getFont("SIMYOU"), sf::Color::Black, L"返回", 30);
	home.setColor(sf::Color(200, 200, 200, 150), sf::Color(100, 100, 100, 150), sf::Color(150, 150, 150, 150));
	home.setPosition(50, 50, 200, 50);

	//设置背景图片
	BackgroundImage.setTexture(assetManager.getTexture("JumkoMenu"));
	// 使图片变暗但仍然可见
	BackgroundImage.setColor(sf::Color(128, 128, 128, 255));

	//初始化标题
	title.setFont(assetManager.getFont("simhei"));
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(70);
	title.setString(L"游戏设置");
	title.setPosition(350, 50);

	//初始化音乐音量的标签
	MusicVolume.setFont(assetManager.getFont("simhei"));
	MusicVolume.setFillColor(sf::Color::White);
	MusicVolume.setCharacterSize(35);
	MusicVolume.setString(L"音乐音量");
	MusicVolume.setPosition(150, 300);
	//初始化音效音量的标签
	SoundVolume.setFont(assetManager.getFont("simhei"));
	SoundVolume.setFillColor(sf::Color::White);
	SoundVolume.setCharacterSize(35);
	SoundVolume.setString(L"音效音量");
	SoundVolume.setPosition(150, 400);
	//初始化无敌模式的标签
	Mod.setFont(assetManager.getFont("simhei"));
	Mod.setFillColor(sf::Color::White);
	Mod.setCharacterSize(35);
	Mod.setString(L"无敌模式");
	Mod.setPosition(150, 600);
	//初始化音量条

	Background1.setSize(sf::Vector2f(350, 20));
	Background2.setSize(sf::Vector2f(350, 20));
	VolumeBar1.setSize(sf::Vector2f(350 * (audioManager.getVolumeMusic()), 20));
	VolumeBar2.setSize(sf::Vector2f(350 * (audioManager.getVolumeSound()), 20));
	Background1.setFillColor(sf::Color::Black);
	Background2.setFillColor(sf::Color::Black);
	VolumeBar1.setFillColor(sf::Color(200, 200, 200));
	VolumeBar2.setFillColor(sf::Color(200, 200, 200));
	Background1.setPosition(400, 310);
	Background2.setPosition(400, 410);
	VolumeBar1.setPosition(400, 310);
	VolumeBar2.setPosition(400, 410);
	//初始化音量条上面的那个球
	VolumeBall1.setRadius(15.f);
	VolumeBall2.setRadius(15.f);
	VolumeBall1.setPosition(380 + 350 * audioManager.getVolumeMusic(), 305);
	VolumeBall2.setPosition(380 + 350 * audioManager.getVolumeSound(), 405);
	//初始化音量数字
	MusicText.setFont(assetManager.getFont("simhei"));
	MusicText.setFillColor(sf::Color::White);
	MusicText.setCharacterSize(30);
	MusicText.setString(std::to_string(static_cast<int>(audioManager.getVolumeMusic() * 100)));
	MusicText.setPosition(800, 300);
	//初始化音效数字
	SoundText.setFont(assetManager.getFont("simhei"));
	SoundText.setFillColor(sf::Color::White);
	SoundText.setCharacterSize(30);
	SoundText.setString(std::to_string(static_cast<int>(audioManager.getVolumeSound() * 100)));
	SoundText.setPosition(800, 400);

	//初始化无敌模式
	Background3.setSize(sf::Vector2f(50, 20));
	Background3.setFillColor(sf::Color::Black);
	Background3.setPosition(400, 610);
	ModBar.setPosition(400, 610);
	ModBar.setFillColor(sf::Color(200, 200, 200));
	ModBall.setRadius(18.f);
	if (settingsManager.isInvincible) {
		ModBar.setSize(sf::Vector2f(50, 20));
		ModBall.setPosition(430, 602);
	}
	else {
		ModBar.setSize(sf::Vector2f(0, 20));
		ModBall.setPosition(380, 602);
	}
	//初始化键位
	wasd.setFont(assetManager.getFont("simhei"));
	wasd.setFillColor(sf::Color::White);
	wasd.setCharacterSize(35);
	wasd.setString(L"wasd键位");
	wasd.setPosition(150, 475);

	not_wasd.setFont(assetManager.getFont("simhei"));
	not_wasd.setFillColor(sf::Color::White);
	not_wasd.setCharacterSize(35);
	not_wasd.setString(L"方向键键位");
	not_wasd.setPosition(150, 525);

	wasd_shape.setRadius(18.f);
	wasd_shape.setFillColor(sf::Color(0, 0, 0, 128));
	wasd_shape.setPosition(400, 480);

	not_wasd_shape.setRadius(18.f);
	not_wasd_shape.setFillColor(sf::Color(0, 0, 0, 128));
	not_wasd_shape.setPosition(400, 530);

	wasd_ball.setRadius(14.f);
	wasd_ball.setFillColor(sf::Color::White);
	wasd_ball.setPosition(404, 484);

	not_wasd_ball.setRadius(14.f);
	not_wasd_ball.setFillColor(sf::Color::White);
	not_wasd_ball.setPosition(404, 534);


}

bool isMusicChange;

bool isSoundChange;

bool isSelect = false;

//bool is

void StateSetting::handleInput(sf::RenderWindow& window) {
	//处理输入
	/*
	负责人: 小柱

	功能:
		处理用户的输入
			返回主菜单
			调节音效音乐音量

	参数:
		sf::RenderWindow& window    //时间发生的地方

	返回值: void
	*/
	//----------------------实现------------------------//

	AudioManager& audioManager = AudioManager::getInstance();
	SettingsManager& settingsManager = SettingsManager::getInstance();
	sf::Event event;


	while (window.pollEvent(event))
	{

		//获取鼠标位置
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		//当点击关闭时关闭窗口
		if (event.type == sf::Event::Closed) {
			SettingsManager::getInstance().saveSettings("Asset/save.txt");
			window.close();
		}
		// ... 处理按钮点击事件，使用stateManager.changeState(...)
		if (event.type == sf::Event::MouseButtonPressed) {
			bool getground1 = Background1.getGlobalBounds().contains(mousePosition);
			bool getground2 = Background2.getGlobalBounds().contains(mousePosition);
			bool getground3 = Background3.getGlobalBounds().contains(mousePosition);
			bool getground4 = wasd_shape.getGlobalBounds().contains(mousePosition);
			bool getground5 = not_wasd_shape.getGlobalBounds().contains(mousePosition);
			if (this->home.isMouseOver(mousePosition)) {
				SettingsManager::getInstance().saveSettings("Asset/save.txt");
				this->stateManager.changeState(std::make_unique<StateMenu>(stateManager));
			}
			if (getground1)
			{
				isMusicChange = true;
				audioManager.playSound("ClickButton");
			}
			else isMusicChange = false;
			if (getground2)
			{
				isSoundChange = true;
				audioManager.playSound("ClickButton");
			}
			else isSoundChange = false;

			if (getground3)
			{
				if (settingsManager.isInvincible)
				{
					settingsManager.isInvincible = false;
					ModBar.setSize(sf::Vector2f(0, 20));
					ModBall.setPosition(380, 602);
				}
				else
				{
					settingsManager.isInvincible = true;
					ModBar.setSize(sf::Vector2f(50, 20));
					ModBall.setPosition(430, 602);
				}
				audioManager.playSound("ClickButton");
			}

			if (getground4)
			{
				settingsManager.iswasd = true;
				audioManager.playSound("ClickButton");
			}

			if (getground5)
			{
				settingsManager.iswasd = false;
				audioManager.playSound("ClickButton");
			}

			if (home.isMouseOver(mousePosition)) {
				audioManager.playSound("ClickButton");
			}

		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			isMusicChange = false;
			isSoundChange = false;
			VolumeBall1.setFillColor(sf::Color::White);
			VolumeBall1.setRadius(15.f);
			VolumeBall2.setFillColor(sf::Color::White);
			VolumeBall2.setRadius(15.f);
		}
		if (event.type == sf::Event::MouseMoved) {

			if (home.isMouseOver(mousePosition)) {
				home.onHover();
				if (!isSelect) {
					isSelect = true;
					audioManager.playSound("SelectButton");
				}
			}
			else {
				//当鼠标不再悬停在按钮上时恢复原始颜色
				home.resetColor();
				isSelect = false;

			}

			if (isMusicChange)
			{
				VolumeBall1.setFillColor(sf::Color(128, 128, 175));

				if (mousePosition.x >= 400 && mousePosition.x <= 750)
				{
					VolumeBar1.setSize(sf::Vector2f(mousePosition.x - 400, 20));
					VolumeBall1.setPosition(mousePosition.x - 10, 305);
					audioManager.setMusicVolume((mousePosition.x - 400) / 350);
					settingsManager.musicVolume = (mousePosition.x - 400) / 350 * 100;
					MusicText.setString(std::to_string(static_cast<int>(audioManager.getVolumeMusic() * 100)));
				}

			}
			else if (isSoundChange)
			{
				VolumeBall2.setFillColor(sf::Color(128, 128, 175));

				if (mousePosition.x >= 400 && mousePosition.x <= 750)
				{
					VolumeBar2.setSize(sf::Vector2f(mousePosition.x - 400, 20));
					VolumeBall2.setPosition(mousePosition.x - 10, 405);
					audioManager.setSoundVolume((mousePosition.x - 400) / 350);
					settingsManager.soundVolume = (mousePosition.x - 400) / 350 * 100;
					SoundText.setString(std::to_string(static_cast<int>(audioManager.getVolumeSound() * 100)));
				}

			}

		}
	}

}

void StateSetting::update(float deltaTime) {
	// ... 更新逻辑
	/*
	负责人: 小柱

	功能:
		没用

	参数:
		float deltaTime    //全局间隔时间

	返回值: void
	*/
	//----------------------实现------------------------//

}

void StateSetting::draw(sf::RenderWindow& window) {
	//渲染
	/*
	负责人: 小柱

	功能:
		渲染画面

	参数:
		sf::RenderWindow& window    //要渲染到的地方

	返回值: void
	*/
	//----------------------实现------------------------//
	//最先渲染背景图片
	window.draw(BackgroundImage);

	// ... 绘制按钮
	this->home.draw(window);

	//绘制文字
	window.draw(this->title);
	window.draw(this->MusicVolume);
	window.draw(this->SoundVolume);
	window.draw(this->Mod);
	//绘制音量条
	window.draw(this->Background1);
	window.draw(this->Background2);
	window.draw(this->Background3);
	window.draw(this->VolumeBar1);
	window.draw(this->VolumeBar2);
	window.draw(this->VolumeBall1);
	window.draw(this->VolumeBall2);
	window.draw(this->MusicText);
	window.draw(this->SoundText);
	//绘制无敌模式
	window.draw(this->ModBar);
	window.draw(this->ModBall);
	//绘制键位
	SettingsManager& settingsManager = SettingsManager::getInstance();
	window.draw(this->wasd);
	window.draw(this->not_wasd);
	window.draw(this->wasd_shape);
	window.draw(this->not_wasd_shape);
	if(settingsManager.iswasd) window.draw(this->wasd_ball);
	else window.draw(this->not_wasd_ball);
	
	
}
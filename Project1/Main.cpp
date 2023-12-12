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
	//�������
	/*
	������: ����ɳ

	����:
		���г�������߼�

	����: void

	����ֵ: int
	*/
	//----------------------ʵ��------------------------//

	//��������
	sf::RenderWindow window(sf::VideoMode(960, 960), L"������Σ��֮ɭ");
	//������Ϸ֡������Ϊ200FPS
	window.setFramerateLimit(200);


	//��������������
	StateManager stateManager;

	// ��ʼ��EntityManager����
	EntityManager* entityManager = EntityManager::getInstance();

	//ʹ����Ƶ������
	AudioManager& audioManager = AudioManager::getInstance();

	//ʹ���ļ�������
	SettingsManager& settingsManager = SettingsManager::getInstance();

	//��������������ʼ����������Ϊ������(ʹ������ָ��)
	stateManager.changeState(std::make_unique<StateMenu>(stateManager));
	//Ĭ�ϳ�ʼ����BGM
	audioManager.playMusic("MenuMusic1", true);

	//��ȡһ�δ浵
	settingsManager.loadSettings("Asset/save.txt");
	audioManager.setSoundVolume(settingsManager.soundVolume / 100.f);
	audioManager.setMusicVolume(settingsManager.musicVolume / 100.f);

	//����ȫ��ʱ��
	sf::Clock clock;

	//��ʼ�����
	srand(time(NULL));

	//----------------��Ϸ��ѭ��------------------//
	while (window.isOpen()) {
		//ͳһʱ��
		float deltaTime = clock.restart().asSeconds();

		//�������´�
		stateManager.handleInputCurrentState(window);

		//���г�������ͨ��ÿ֡����
		stateManager.updateCurrentState(deltaTime);

		//�����ŵ���Ч
		audioManager.update();

		//��ջ���
		window.clear();

		//��Ⱦ��ǰ����������
		stateManager.drawCurrentState(window);

		//��ʾ��Ⱦ��ɵĳ���
		window.display();
	}

	return 0;
}






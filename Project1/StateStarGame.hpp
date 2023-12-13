#ifndef STATESTARE_HPP
#define STATESTARE_HPP

#include "Button.hpp"
#include "StateManager.hpp"
#include "State.hpp"
#include "AssetManager.hpp"
#include "AudioManager.hpp"
#include "SettingsManager.hpp"


// -------------------- ����� --------------------
/*
	����ʼ�����ࡿ
	�����ˣ�����ɳ

	���ܣ����ſ�����������ת��ѡ���Ѷȳ���
*/

class StateStartGame : public State {
public:
	//���췽��
	StateStartGame(StateManager& manager);

	//����������¼�
	void handleInput(sf::RenderWindow& window) override;

	//���£�δ��ɣ�
	void update(float deltaTime) override;

	//��Ⱦ��δ��ɣ�
	void draw(sf::RenderWindow& window) override;

private:
	//����������������
	StateManager& stateManager;

	//��һ����ť
	Button Next;
	
	//һ��ͼƬ
	sf::Sprite Pic1;
	//һ������
	sf::Text text1;
	sf::Text text2;
	sf::Text text3;
	sf::Text text4;

	//��ʱ��
	float TotalTime;

	//�����ʾ���
	float animationDuration;

	
};

// -------------------- ����� --------------------
/*
	��ѡ���Ѷ��ࡿ
	�����ˣ�����ɳ

	���ܣ������Ѷ�ѡһ�������Ҵ��볡��
*/
class StateSelectDifficulty : public State {
public:
	// ���췽��
	StateSelectDifficulty(StateManager& manager);

	// ����������¼�
	void handleInput(sf::RenderWindow& window) override;

	// ���£�δ��ɣ�
	void update(float deltaTime) override;

	// ��Ⱦ��δ��ɣ�
	void draw(sf::RenderWindow& window) override;

private:
	// ״̬������������
	StateManager& stateManager;

	// ѡ���Ѷȵİ�ť
	Button easyButton;
	Button hardButton;
	Button EXButton;
	//�Ƿ񲥷Ź���Ч
	bool isEasyButton;
	bool ishardButton;
	bool isEXButton;
	// ��ʾ�Ѷ�ѡ�������
	sf::Text difficultyText;

	// ������Ҫ��������Ա����...
};

#endif

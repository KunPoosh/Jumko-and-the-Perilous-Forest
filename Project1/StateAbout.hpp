#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "StateManager.hpp"
#include "Button.hpp"
#include "AssetManager.hpp"
// -------------------- ����� --------------------
/*
	�����ڳ����ࡿ��δ��ɣ�
	�����ˣ���

	���ܣ�ʵ�ֹ��ڽ���Ĺ���
	1.��ʾ���ذ�ť
	2.��ʾ�Ŷӿ�����Ա�Լ��������ģ��
	3.�������ʹ�����ť������¼���Ӧ
	4.��ʾ������
*/
class StateAbout : public State {
public:
	//���췽��
	StateAbout(StateManager& manager);

	//����������¼�
	void handleInput(sf::RenderWindow& window) override;

	//����
	void update(float deltaTime) override;

	//��Ⱦ
	void draw(sf::RenderWindow& window) override;

private:

	//������������
	StateManager& stateManager;
	//���ذ�ť
	Button home;
	//����
	sf::Text title;
	//���˵��ı���ͼƬ
	sf::Sprite BackgroundImage;
	//����ֱ����������Ա��ͼƬ
	sf::Sprite About;
	//�����ҵ���Ŀ��ť
	sf::Text visitLink;
};
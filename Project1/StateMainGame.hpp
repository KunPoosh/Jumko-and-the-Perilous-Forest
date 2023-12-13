#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"
#include "Button.hpp"
#include "StateManager.hpp"
#include "AssetManager.hpp"
#include "AudioManager.hpp"
#include "EntityManager.hpp"
#include "SettingsManager.hpp"
#include "EnemyFactory.hpp"
#include "Player.hpp"
#include <sstream>
#include <iomanip>
#include <string>

// -------------------- ����� --------------------
/*
    ����Ϸ�������ࡿ(δ���)
    �����ˣ� ����ɳ

    ���ܣ�
        ʵ����Ϸ����Ϸ�����Ĺ���
        1.��ʾ��Ϸ����
            ��Ϸս������ı���ͼƬ
            �ұ�UI�ı�������
            ��������
            ������µ�һ����ɫ����
            һ�����ܵ�ͼ��ͼƬ
            ������ʾ���ܵ���ɫ����
            һ���ڼ������·��ļ�����ȴ��
            һ����ҵ�Ѫ��
            �ı� ʱ��
            �ı� ����
            �ı� ��ҵ�ǰ������ֵ

        2.����͸�����Ϸʵ�壨����ҽ�ɫ�����ˣ��ϰ���ȣ�
        3.������Ϸ�߼�����������룬��ײ���ȣ�
        4.��Ⱦ��Ϸʵ��ͽ���Ԫ��

        ����
            ����Ƿ���������ģʽ
            ��ǰ�ۼ�ʱ��
            ��ǰ����
*/

class StateMainGame : public State {
    friend class StateFailure;
public:
    //���췽��������һ�����������������ã�������ó����������ķ�����(δ���)
    StateMainGame(StateManager& manager);

    //������Ϸ�߼�����������롢��ײ���ȡ�(δ���)
    void handleInput(sf::RenderWindow& window) override;

    //������Ϸ״̬����ʵ��λ�á���Ϸ�����ȡ�(δ���)
    void update(float deltaTime) override;

    //��Ⱦ��Ϸʵ��ͽ���Ԫ�ء�(δ���)
    void draw(sf::RenderWindow& window) override;

    //----------��ӵ���---------//
    //                          //
    void ADDENEMYS();           //
    //                          //
    //----------��ӵ���---------//

private:
    // ����������
    StateManager& stateManager;

    // ��Ϸ����
    sf::Sprite gameBackground;

    // UIԪ��
    sf::RectangleShape uiBackground;        // �ұ�UI�ı�������
    sf::Sprite characterPortrait;           // ��������
    sf::RectangleShape portraitBackground;  // ������µĻ�ɫ����
    sf::Sprite skillIcon;                   // ����ͼ��
    sf::RectangleShape energyBars1;         // ������ʾ���ܵ���ɫ����
    sf::RectangleShape energyBars2;
    sf::RectangleShape skillCooldownBar;    // ������ȴ��
    sf::RectangleShape healthBar;           // ���Ѫ��
    sf::RectangleShape healthBarBackground; // ���Ѫ���װ�
    sf::RectangleShape skillBar;            // ������ȴ��
    sf::RectangleShape skillBarBackground;  // ������ȴ���װ�
    sf::RectangleShape ground;              // ��ͣ������
    sf::RectangleShape ground2;
    Button Continue;
    Button Return;

    // �ı�Ԫ��
    sf::Text timeText;   // ��ʾʱ��
    sf::Text scoreText;  // ��ʾ����
    sf::Text powerText;  // ��ʾ��ҵ�ǰ������ֵ
    sf::Text HP;         // ��ʾ���Ѫ��
    sf::Text FPS;        // ��ʾ��ǰ��Ϸ֡��

    // ��Ϸ�߼��������
    float elapsedTime;   // ��ǰ�ۼ�ʱ��(����ʹ��)
    bool isHardMode;     // ����Ƿ���������ģʽ
    float fpsUpdateTime; // �ۼ�ʱ�䣬���ڸ���FPS��ʾ
    float TOTALTIME;     // ��ʱ��
    int score;           // ��ǰ����
    int TIMEFORPLAY;     // �����л���ֵ
    int ENEMYOUT2S;      // С�����л�������
    float ENEMYOUT2STIME;// С������ʱ��
    //static float RecordTotalTime;//Ϊ����������¼���ʱ��
    bool isEXMode;       //����Ƿ�����EXģʽ

    int playerHealth;    //��ҵĵ�ǰ����ֵ
    int maxPlayerHealth; //��ҵ���������

    float skillCD;       //����CD
    float CDTime;        //��ǰ�ۼƵļ���CDʱ��
    int skillCharging;   //���ܳ��ܵ���
    float skillUseCd;    //���ܼ���ͷ�CD
    float useTime;       //���ܼ�ļ�ʱ
    //...

    bool isEsc = false;          //�Ƿ������ͣ
    bool isContinue = false;
    bool isReturn = false;

};

#endif // GAMESTATE_HPP

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"
#include "EntityManager.hpp"
#include "Bullet.hpp"
#include "AudioManager.hpp"
#include <iostream>


// -------------------- ����� --------------------
/*
    ������ࡿ��δ��ɣ�
    �����ˣ� ����ɳ

    ���ܣ����
        1.�ƶ�
        2.�����¼�
            .�����ƶ�
            .������
        3.����
            .�����ָ�
            .����Ч�������ã�
        4.ӵ�е���(����)

*/

class Player : public Entity {
private:
    sf::Sprite sprite;             // ��ҽ�ɫ�ľ���
    sf::Sprite hitboxSprite;       // �ж���ľ���

    int health;                    // ����ֵ
    int maxHealth;                 // ����ֵ����
    int strength;                  // ����ֵ
    float moveSpeed;               // �ƶ��ٶ�

    float accumulatedTime;         // �ۼ�ʱ��(����)
    float attackInterval;          // �������
    float timeTohealth;            // �ۼ�ʱ��(��������)
    int healthRegenerationRate;    // ���������ٶ�
    int skillCharging;             // ���ܳ��ܵ���

    int atkBullet;                 // �ӵ����˺�
    int helthBullet;               // �ӵ���Ѫ��
    int speedBullet;               // �ӵ����ٶ�

    float TotalTime;
    int score;          // ����
    bool isHard;        // �Ƿ�������ģʽ
    bool isBoss;
    bool isGameOver;    // �Ƿ�ͨ��
    bool isInvincible;  // �Ƿ����޵�ģʽ
    bool isSkill;       // �Ƿ�����ͷż���
    bool isEX;          //�Ƿ���EXģʽ
    //�¼�����
    bool movingUp;      // ���ڸ��� �� ���Ƿ񱻰���
    bool movingDown;    // ���ڸ��� �� ���Ƿ񱻰���
    bool movingLeft;    // ���ڸ��� �� ���Ƿ񱻰���
    bool movingRight;   // ���ڸ��� �� ���Ƿ񱻰���
    bool slowMovement;  // ���ڸ��� Shift ���Ƿ񱻰���
    bool openFire;      // ���ڸ��� Z ���Ƿ񱻰���


public:

    //���췽�����ֶ�����
    Player();

    //����
    void update(float deltaTime) override;

    //�����¼�
    void handleInput(sf::Event& event);

    //��Ⱦ
    void draw(sf::RenderWindow& window) override;


    //�����ж������ĵ�λ��
    sf::Vector2f getHitboxPosition() const;

    //��������ģʽ��
    void hardCore();

    //����EXģʽ
    void exCord();

    //�����޵�ģʽ
    void Invincible();

    //�������λ��

    //开启Boss战模�?
    void bossCore();

    //设置玩家位置

    void setPosition(sf::Vector2f position);

    // ���ض���Ҿ��������
    const sf::Sprite& getSprite() const;

    // ���ض�����ж��������
    const sf::Sprite& getHitBox() const;

    // ��ȡ��ҵķ���
    int getScore() const;

    // ������ҵķ���
    void addScore(int score);

    // �����������
    void addPower(int power);

    // ����ܵ��˺��ķ���
    void takeDamage(int damage);

    //��ȡ��ҵ�ǰ������ֵ
    int getHealth();

    //��ȡ��ҵ�ǰ����������
    int getMaxHealth();

    //������ҵļ��ܵ���
    void setSkill(int skill);

    //ʹ�ü���
    void SkillFire();

    //������ʱ��
    void setTime(float time) {
        TotalTime = time;
    }

    //��ȡ��ʱ��
    float getTime() {
        return TotalTime;
    }

    // ��һ�ʤ
    void victory() {
        isGameOver = true;
    }

    //��ȡ����Ƿ��ʤ
    bool isVictory() {
        return isGameOver;
    }

    //��ȡ����Ƿ�������ģʽ
    bool isHardCore() {
        return isHard;
    }

    // ���úͻ�ȡ���Եķ���
    // ...
};

#endif

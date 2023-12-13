#include "Player.hpp"

Player::Player() {
	//���췽��
	/*
	������: ����ɳ

	����:
		��ʼ����ҵ�������Ϣ

	����: void

	����ֵ: void
	*/
	//----------------------ʵ��------------------------//

	//�ٻ��زģ�
	AssetManager& assetManager = AssetManager::getInstance();

	sprite.setTexture(assetManager.getTexture("Jumko"));
	hitboxSprite.setTexture(assetManager.getTexture("HitBox"));

	health = 1000;
	maxHealth = 1000;
	strength = 1000;
	moveSpeed = 600;

	accumulatedTime = 0.f;
	attackInterval = 0.08f;
	timeTohealth = 0.f;
	healthRegenerationRate = 10;
	skillCharging = 0;

	atkBullet = 400;
	helthBullet = 1;
	speedBullet = 1500;

	TotalTime = 0.f;
	score = 0;
	isHard = false;
	isEX = false;
	isBoss = false;
	isGameOver = false;
	isInvincible = false;
	isSkill = false;
	movingUp = false;
	movingDown = false;
	movingLeft = false;
	movingRight = false;
	slowMovement = false;
	openFire = false;

	//�����ĵ����õ�ͼƬ���ĵ�
	//����
	sf::Vector2u textureSize = assetManager.getTexture("Jumko").getSize(); // ��ȡ��ͼ�ĳߴ�
	sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f); // ���þ����ԭ��Ϊ��ͼ����
	//�ж���
	textureSize = assetManager.getTexture("HitBox").getSize(); // ��ȡ��ͼ�ĳߴ�
	hitboxSprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f); // ���þ����ԭ��Ϊ��ͼ����
}


sf::Vector2f Player::getHitboxPosition() const {
	//�����ж������ĵ�λ��
	/*
	������: ����ɳ

	����:
		��������һ��λ�ã�����ָ��

	����: void

	����ֵ: sf::Vector2f
	*/
	//----------------------ʵ��------------------------//
	return hitboxSprite.getPosition();
}

void Player::hardCore() {
	//��������ģʽ��
	/*
	������: ����ɳ

	����:
		ʹ��ҽ�������ģʽ,�ı���ҵĻ�����ֵ

	����: void

	����ֵ: void
	*/
	//----------------------ʵ��------------------------//

	isHard = true;
	//�����Ĳ�������
	//...
	health = 600;
	maxHealth = 600;
	healthRegenerationRate = 5;
}


void Player::exCord() {

	//����EXģʽ
	isEX = true;
	health = 300;
	maxHealth = 500;
	healthRegenerationRate = 3;

}
void Player::bossCore() {
	//开启Boss战模式！
	/*
	负责�? 波波�?

	功能:
		使玩家进入困难模�?改变玩家的基础数�?

	参数: void

	返回�? void
	*/
	//----------------------实现------------------------//

	isBoss = true;
	//其他的参数调�?
	//...
	health = 1800;
	maxHealth = 1800;
	healthRegenerationRate = 20;
	atkBullet = 600;
	strength = 3000;
}

void Player::Invincible() {
	//开启无敌模式！
	/*
	 �����ˣ�Tiant
	 ���ܣ�
	 ��ҽ���EXģʽ
	 �ı������ֵ
	 ������void
	 ����ֵ��void
	*/
	isEX = true;
	health = 300;
	maxHealth = 500;
	healthRegenerationRate = 3;
}
void Player::Invincible() {
	//�����޵�ģʽ��
	/*
	������: ����ɳ

	����:
		ʹ��ҽ�������ģʽ,�ı���ҵĻ�����ֵ

	����: void

	����ֵ: void
	*/
	//----------------------ʵ��------------------------//

	isInvincible = true;
	//������������
	maxHealth = 2000000000;
	health = 2000000000;
	healthRegenerationRate = 100000;
	//...
}


void Player::setPosition(sf::Vector2f position) {
	//�������λ��
	/*
	������: ����ɳ

	����:
		����һ��λ�ã�������ʼ�����λ��

	����: 
		sf::Vector2f position	//��ҵ�λ��

	����ֵ: void
	*/
	//----------------------ʵ��------------------------//

	sprite.setPosition(position);
}

const sf::Sprite& Player::getSprite() const {
	// ���ض���Ҿ��������
	/*
	������: ����ɳ

	����:
		������Ҿ��������

	����:
		void

	����ֵ: const sf::Sprite&
	*/
	//----------------------ʵ��------------------------//

	return sprite;
}

const sf::Sprite& Player::getHitBox() const {
	// ���ض���Ҿ��������
	/*
	������: ����ɳ

	����:
		��������ж��������

	����:
		void

	����ֵ: const sf::Sprite&
	*/
	//----------------------ʵ��------------------------//

	return hitboxSprite;
}

void Player::takeDamage(int damage) {
	// ����ܵ��˺��ķ���
	/*
	������: ����ɳ

	����:
		������ܵ��˺�

	����:
		int damage	//�˺���

	����ֵ: void
	*/
	//----------------------ʵ��------------------------//

	health -= damage;
	
}

int Player::getScore() const {
	// ��ȡ��ҵķ���
	/*
	������: ����ɳ

	����:
		������ҵķ���������

	����:
		void

	����ֵ: int
	*/
	//----------------------ʵ��------------------------//
	return score;
}

void Player::addScore(int scoreToAdd) {
	// ������ҵķ���
	/*
	������: ����ɳ

	����:
		������ҵķ���

	����:
		int scoreToAdd	//���ӵ�ֵ

	����ֵ: void
	*/
	//----------------------ʵ��------------------------//
	score += scoreToAdd;
}

int Player::getHealth() {
	//��ȡ��ҵ�ǰ������ֵ
	/*
	������: ����ɳ

	����:
		������ҵ�����ֵ

	����:
		void

	����ֵ: int
	*/
	//----------------------ʵ��------------------------//
	return health;
}

int Player::getMaxHealth() {
	//��ȡ��ҵ�ǰ������ֵ����
	/*
	������: ����ɳ

	����:
		������ҵ�����ֵ����

	����:
		void

	����ֵ: int
	*/
	//----------------------ʵ��------------------------//
	return maxHealth;
}

void Player::setSkill(int skill) {
	//������ҵļ��ܳ���
	/*
	������: ����ɳ

	����:
		ͬ���������ļ��ܳ���

	����:
		int skill		//�������ļ��ܳ���ֵ

	����ֵ: void
	*/
	//----------------------ʵ��------------------------//
	skillCharging = skill;
}

void Player::SkillFire() {
	//ʹ�ü���
	/*
	������: ����ɳ

	����:
		�ͷ�һ�μ���

	����:
		void

	����ֵ: void
	*/
	//----------------------ʵ��------------------------//
	isSkill = true;
}

void Player::addPower(int power) {
	// �����������
	/*
	������: ����ɳ

	����:
		�ͷ�һ�μ���

	����:
		void

	����ֵ: void
	*/
	//----------------------ʵ��------------------------//

	strength += power;
}


void Player::update(float deltaTime) {
	// �������״̬
	/*
	������: ����ɳ,����

	����:
		������ƶ������

	����:
		float deltaTime		//ȫ�ּ��ʱ��

	����ֵ: void
	*/
	//----------------------ʵ��------------------------//

	accumulatedTime += deltaTime;

	// �����߼�
	if (accumulatedTime >= attackInterval) {
		// ִ�й���
		accumulatedTime -= attackInterval;  // �����ۼ�ʱ��

		if (openFire) {

			//�ٻ�ʵ����������׼�������ӵ�
			EntityManager* entityManager = EntityManager::getInstance();
			//�ٻ��زĴ��
			AssetManager& assetManager = AssetManager::getInstance();
			//������Ƶ���ŵ���
			AudioManager& audioManager = AudioManager::getInstance();

			if (strength < 2000) {
				//һ������
				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet->setPosition(sprite.getPosition() + sf::Vector2f(-8,-5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet2 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet2->setPosition(sprite.getPosition() + sf::Vector2f(8, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet2);

				//�����Ч
				audioManager.playSound("PlayerAttack1");
			}
			else if (strength < 3000) {
				//��������
				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet->setPosition(sprite.getPosition() + sf::Vector2f(-16, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet2 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet2->setPosition(sprite.getPosition() + sf::Vector2f(16, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet2);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet3 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet3"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					(atkBullet * 2)
				);
				//�����ӵ���λ��
				newBullet3->setPosition(sprite.getPosition() + sf::Vector2f(0, -10));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet3);

				//�����Ч
				audioManager.playSound("PlayerAttack1");
			}
			else if (strength < 4000) {
				//��������
				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet->setPosition(sprite.getPosition() + sf::Vector2f(-15, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet2 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet2->setPosition(sprite.getPosition() + sf::Vector2f(15, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet2);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet3 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet3"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					(atkBullet * 2)
				);
				//�����ӵ���λ��
				newBullet3->setPosition(sprite.getPosition() + sf::Vector2f(0, -10));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet3);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet4 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(-0.173648, -0.98526),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet4->setPosition(sprite.getPosition() + sf::Vector2f(-15, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet4);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet5 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0.173648, -0.98526),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet5->setPosition(sprite.getPosition() + sf::Vector2f(15, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet5);

				//�����Ч
				audioManager.playSound("PlayerAttack1");
			}
			else if (strength < 5000) {
				//�ļ�����
				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet->setPosition(sprite.getPosition() + sf::Vector2f(-15, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet2 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet2->setPosition(sprite.getPosition() + sf::Vector2f(15, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet2);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet3 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet3"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					(atkBullet * 2)
				);
				//�����ӵ���λ��
				newBullet3->setPosition(sprite.getPosition() + sf::Vector2f(0, -10));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet3);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet4 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(-0.173648, -0.98526),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet4->setPosition(sprite.getPosition() + sf::Vector2f(-15, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet4);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet5 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0.173648, -0.98526),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet5->setPosition(sprite.getPosition() + sf::Vector2f(15, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet5);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet6 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0.136824, -0.98713),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet6->setPosition(sprite.getPosition() + sf::Vector2f(-20, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet6);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet7 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(-0.136824, -0.98713),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet7->setPosition(sprite.getPosition() + sf::Vector2f(20, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet7);

				//�����Ч
				audioManager.playSound("PlayerAttack1");
			}
			else
			{
				//�弶����
				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet->setPosition(sprite.getPosition() + sf::Vector2f(-10, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet2 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet2->setPosition(sprite.getPosition() + sf::Vector2f(10, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet2);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet3 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet3"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					(atkBullet * 2)
				);
				//�����ӵ���λ��
				newBullet3->setPosition(sprite.getPosition() + sf::Vector2f(0, -10));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet3);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet4 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(-0.173648, -0.98526),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet4->setPosition(sprite.getPosition() + sf::Vector2f(-15, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet4);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet5 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0.173648, -0.98526),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet5->setPosition(sprite.getPosition() + sf::Vector2f(15, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet5);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet6 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0.136824, -0.98713),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet6->setPosition(sprite.getPosition() + sf::Vector2f(-20, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet6);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet7 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(-0.136824, -0.98713),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet7->setPosition(sprite.getPosition() + sf::Vector2f(20, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet7);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet8 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet8->setPosition(sprite.getPosition() + sf::Vector2f(20, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet8);

				// ����һ���µ��ӵ�ʵ����
				std::shared_ptr<Bullet> newBullet9 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//�����ӵ���λ��
				newBullet9->setPosition(sprite.getPosition() + sf::Vector2f(-20, -5));

				// ���ӵ���ӵ�EntityManager��
				entityManager->getInstance()->addBullet(newBullet9);

				//�����Ч
				audioManager.playSound("PlayerAttack1");
			}

		}
	}

	// �����ָ��߼�
	timeTohealth += deltaTime;
	if (timeTohealth >= 1.f) { 
		health += healthRegenerationRate;
		timeTohealth -= 1.f;
		if (health >= maxHealth) health = maxHealth;  // ��������ֵ����
	}


	// �����ͷ��߼�
	if (isSkill) {
		//��Ƶ������
		AudioManager& audioManager = AudioManager::getInstance();
		//�زĹ�����
		AssetManager& assetManager = AssetManager::getInstance();
		//ʵ�������
		EntityManager* entityManager = EntityManager::getInstance();

		isSkill = false;
		//���ܵ���ϸʵ��
		//...
		// ����һ���µ��ӵ�ʵ����
		std::shared_ptr<Bullet> newBullet9 = std::make_shared<PlayerMagicBullet>(
			assetManager.getTexture("SkillButton"),
			sf::Vector2f(0, -1),
			1500,
			10000,
			100
		);
		//�����ӵ���λ��
		newBullet9->setPosition(sprite.getPosition() + sf::Vector2f(-20, -5));

		// ���ӵ���ӵ�EntityManager��
		entityManager->getInstance()->addBullet(newBullet9);


		//���ż�����Ч
		audioManager.playSound("PlayerAttack2");
		audioManager.playSound("PlayerAttack3");
	}

	// �ƶ��߼�
	float currentMoveSpeed = slowMovement ? moveSpeed * 0.4f : moveSpeed;  // ����ʱ�����ٶ�
	sf::Vector2f movement(0.f, 0.f);

	if (movingUp) movement.y -= 1.f;
	if (movingDown) movement.y += 1.f;
	if (movingLeft) movement.x -= 1.f;
	if (movingRight) movement.x += 1.f;

	// ���ͬʱ�ƶ���������������ƶ��������й�һ��
	if (movement.x != 0.f && movement.y != 0.f) {
		movement /= std::sqrt(2.f); // �Խ��ƶ�ʱ���������� 1/sqrt(2)
	}

	// Ӧ���ٶȺ�ʱ����
	movement *= currentMoveSpeed * deltaTime;

	// �ƶ����
	sprite.move(movement);

	//�������λ��
	// ��ȡ�µ����λ��
	sf::Vector2f position = sprite.getPosition();
	// Լ�����λ������Ϸ������
	if (position.x < 0) position.x = 0;
	if (position.x > 640) position.x = 640;
	if (position.y < 0) position.y = 0;
	if (position.y > 960) position.y = 960;
	// ������ҵ�λ��
	sprite.setPosition(position);

	//���ж������õ��������
	hitboxSprite.setPosition(sprite.getPosition());

	//����������޵�ģʽ�򲻻��÷���
	if (isInvincible) {
		score = 0;
	}

	//������
	//std::cout << health << "   " << maxHealth << std::endl;
	
}

void Player::handleInput(sf::Event& event) {
	//�����¼�

	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
		case sf::Keyboard::Up:
			movingUp = true;
			break;
		case sf::Keyboard::Down:
			movingDown = true;
			break;
		case sf::Keyboard::Left:
			movingLeft = true;
			break;
		case sf::Keyboard::Right:
			movingRight = true;
			break;
		case sf::Keyboard::LShift:
			slowMovement = true;
			break;
		case sf::Keyboard::Z:
			openFire = true;
			break;
			// ... ���������¼� ...
		}
	}
	else if (event.type == sf::Event::KeyReleased) {
		switch (event.key.code) {
		case sf::Keyboard::Up:
			movingUp = false;
			break;
		case sf::Keyboard::Down:
			movingDown = false;
			break;
		case sf::Keyboard::Left:
			movingLeft = false;
			break;
		case sf::Keyboard::Right:
			movingRight = false;
			break;
		case sf::Keyboard::LShift:
			slowMovement = false;
			break;
		case sf::Keyboard::Z:
			openFire = false;
			break;
			// ... ���������¼� ...
		}
	}
}

void Player::draw(sf::RenderWindow& window) {
	//��Ⱦ
	window.draw(sprite);
	window.draw(hitboxSprite);
}
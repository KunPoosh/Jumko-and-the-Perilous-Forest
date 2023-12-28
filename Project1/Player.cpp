#include "Player.hpp"

Player::Player() {
	//构造方法
	/*
	负责人: 波波沙

	功能:
		初始化玩家的所有信息

	参数: void

	返回值: void
	*/
	//----------------------实现------------------------//

	//召唤素材！
	AssetManager& assetManager = AssetManager::getInstance();

	sprite.setTexture(assetManager.getTexture("Jumko"));
	hitboxSprite.setTexture(assetManager.getTexture("HitBox"));

	health = 2500;
	maxHealth = 2500;
	strength = 2000;
	moveSpeed = 600;

	HitTimer = 0.f;
	accumulatedTime = 0.f;
	attackInterval = 0.08f;
	timeTohealth = 0.f;
	healthRegenerationRate = 30;
	skillCharging = 0;

	atkBullet = 900;
	helthBullet = 1;
	speedBullet = 1500;

	TotalTime = 0.f;
	score = 0;
	isHard = false;
	isBoss = false;
	isEX = false;
	isGameOver = false;
	isInvincible = false;
	isSkill = false;
	isBeHit = false;

	movingUp = false;
	movingDown = false;
	movingLeft = false;
	movingRight = false;
	slowMovement = false;
	openFire = false;

	//将中心点设置到图片中心点
	//酱可
	sf::Vector2u textureSize = assetManager.getTexture("Jumko").getSize(); // 获取贴图的尺寸
	sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f); // 设置精灵的原点为贴图中心
	//判定点
	textureSize = assetManager.getTexture("HitBox").getSize(); // 获取贴图的尺寸
	hitboxSprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f); // 设置精灵的原点为贴图中心
}


sf::Vector2f Player::getHitboxPosition() const {
	//返回判定点中心的位置
	/*
	负责人: 波波沙

	功能:
		仅仅返回一个位置，用于指向

	参数: void

	返回值: sf::Vector2f
	*/
	//----------------------实现------------------------//
	return hitboxSprite.getPosition();
}

void Player::hardCore() {
	//开启困难模式！
	/*
	负责人: 波波沙

	功能:
		使玩家进入困难模式,改变玩家的基础数值

	参数: void

	返回值: void
	*/
	//----------------------实现------------------------//

	isHard = true;
	//其他的参数调整
	//...
	health = 1800;
	maxHealth = 1800;
	healthRegenerationRate = 20;
	strength = 1000;
	atkBullet = 600;
}

void Player::bossCore() {
	//开启Boss战模式！
	/*
	负责人: 波波沙

	功能:
		使玩家进入困难模式,改变玩家的基础数值

	参数: void

	返回值: void
	*/
	//----------------------实现------------------------//

	isBoss = true;
	//其他的参数调整
	//...
	health = 1800;
	maxHealth = 1800;
	healthRegenerationRate = 20;
	atkBullet = 600;
	strength = 3000;
}

void Player::exCord() {
	//开启EX模式
	/*
	 负责人：Tiant
	 功能：
	 玩家进入EX模式
	 改变基础数值
	 参数：void
	 返回值：void
	*/
	isEX = true;
	health = 2000;
	maxHealth = 2000;
	healthRegenerationRate = 0;
	atkBullet = 500;
	strength = 1000;
}

void Player::Invincible() {
	//开启无敌模式！
	/*
	负责人: 波波沙

	功能:
		使玩家进入困难模式,改变玩家的基础数值

	参数: void

	返回值: void
	*/
	//----------------------实现------------------------//

	isInvincible = true;
	//其他参数调整
	maxHealth = 2000000000;
	health = 2000000000;
	healthRegenerationRate = 100000;
	//...
}


void Player::setPosition(sf::Vector2f position) {
	//设置玩家位置
	/*
	负责人: 波波沙

	功能:
		输入一个位置，用来初始化玩家位置

	参数: 
		sf::Vector2f position	//玩家的位置

	返回值: void
	*/
	//----------------------实现------------------------//

	sprite.setPosition(position);
}

const sf::Sprite& Player::getSprite() const {
	// 返回对玩家精灵的引用
	/*
	负责人: 波波沙

	功能:
		返回玩家精灵的引用

	参数:
		void

	返回值: const sf::Sprite&
	*/
	//----------------------实现------------------------//

	return sprite;
}

const sf::Sprite& Player::getHitBox() const {
	// 返回对玩家精灵的引用
	/*
	负责人: 波波沙

	功能:
		返回玩家判定点的引用

	参数:
		void

	返回值: const sf::Sprite&
	*/
	//----------------------实现------------------------//

	return hitboxSprite;
}

void Player::takeDamage(int damage) {
	// 玩家受到伤害的方法
	/*
	负责人: 波波沙

	功能:
		让玩家受到伤害

	参数:
		int damage	//伤害量

	返回值: void
	*/
	//----------------------实现------------------------//

	health -= damage;
	//播放受击角色声音
	isBeHit = true;
}

int Player::getScore() const {
	// 获取玩家的分数
	/*
	负责人: 波波沙

	功能:
		返回玩家的分数给场景

	参数:
		void

	返回值: int
	*/
	//----------------------实现------------------------//
	return score;
}

void Player::addScore(int scoreToAdd) {
	// 增加玩家的分数
	/*
	负责人: 波波沙

	功能:
		增加玩家的分数

	参数:
		int scoreToAdd	//增加的值

	返回值: void
	*/
	//----------------------实现------------------------//
	if (isHard) {
		score += scoreToAdd * 1.5;
	}
	else if (isEX) {
		score += scoreToAdd * 2;
	}
	else
	{
		score += scoreToAdd;
	}
	
}

int Player::getHealth() {
	//获取玩家当前的生命值
	/*
	负责人: 波波沙

	功能:
		返回玩家的生命值

	参数:
		void

	返回值: int
	*/
	//----------------------实现------------------------//
	return health;
}

int Player::getMaxHealth() {
	//获取玩家当前的生命值上限
	/*
	负责人: 波波沙

	功能:
		返回玩家的生命值上限

	参数:
		void

	返回值: int
	*/
	//----------------------实现------------------------//
	return maxHealth;
}

void Player::setSkill(int skill) {
	//设置玩家的技能充能
	/*
	负责人: 波波沙

	功能:
		同步主场景的技能充能

	参数:
		int skill		//主场景的技能充能值

	返回值: void
	*/
	//----------------------实现------------------------//
	skillCharging = skill;
}

void Player::SkillFire() {
	//使用技能
	/*
	负责人: 波波沙

	功能:
		释放一次技能

	参数:
		void

	返回值: void
	*/
	//----------------------实现------------------------//
	isSkill = true;
}

void Player::addPower(int power) {
	// 增加玩家力量
	/*
	负责人: 波波沙

	功能:
		释放一次技能

	参数:
		void

	返回值: void
	*/
	//----------------------实现------------------------//

	strength += power;
}


void Player::update(float deltaTime) {
	// 更新玩家状态
	/*
	负责人: 波波沙,刘智

	功能:
		让玩家移动，射击

	参数:
		float deltaTime		//全局间隔时间

	返回值: void
	*/
	//----------------------实现------------------------//

	accumulatedTime += deltaTime;

	// 攻击逻辑
	if (accumulatedTime >= attackInterval) {
		// 执行攻击
		accumulatedTime -= attackInterval;  // 重置累计时间

		if (openFire) {

			//召唤实体管理器大哥准备接受子弹
			EntityManager* entityManager = EntityManager::getInstance();
			//召唤素材大哥
			AssetManager& assetManager = AssetManager::getInstance();
			//引用音频播放单例
			AudioManager& audioManager = AudioManager::getInstance();

			if (strength < 2000) {
				//一级攻击
				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet->setPosition(sprite.getPosition() + sf::Vector2f(-8,-5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet2 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet2->setPosition(sprite.getPosition() + sf::Vector2f(8, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet2);

				//射击音效
				audioManager.playSound("PlayerAttack1");
			}
			else if (strength < 3000) {
				//二级攻击
				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet->setPosition(sprite.getPosition() + sf::Vector2f(-16, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet2 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet2->setPosition(sprite.getPosition() + sf::Vector2f(16, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet2);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet3 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet3"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					(atkBullet * 2)
				);
				//设置子弹的位置
				newBullet3->setPosition(sprite.getPosition() + sf::Vector2f(0, -10));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet3);

				//射击音效
				audioManager.playSound("PlayerAttack1");
			}
			else if (strength < 4000) {
				//三级攻击
				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet->setPosition(sprite.getPosition() + sf::Vector2f(-15, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet2 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet2->setPosition(sprite.getPosition() + sf::Vector2f(15, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet2);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet3 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet3"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					(atkBullet * 2)
				);
				//设置子弹的位置
				newBullet3->setPosition(sprite.getPosition() + sf::Vector2f(0, -10));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet3);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet4 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(-0.173648, -0.98526),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet4->setPosition(sprite.getPosition() + sf::Vector2f(-15, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet4);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet5 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0.173648, -0.98526),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet5->setPosition(sprite.getPosition() + sf::Vector2f(15, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet5);

				//射击音效
				audioManager.playSound("PlayerAttack1");
			}
			else if (strength < 5000) {
				//四级攻击
				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet->setPosition(sprite.getPosition() + sf::Vector2f(-15, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet2 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet2->setPosition(sprite.getPosition() + sf::Vector2f(15, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet2);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet3 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet3"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					(atkBullet * 2)
				);
				//设置子弹的位置
				newBullet3->setPosition(sprite.getPosition() + sf::Vector2f(0, -10));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet3);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet4 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(-0.173648, -0.98526),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet4->setPosition(sprite.getPosition() + sf::Vector2f(-15, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet4);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet5 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0.173648, -0.98526),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet5->setPosition(sprite.getPosition() + sf::Vector2f(15, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet5);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet6 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0.136824, -0.98713),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet6->setPosition(sprite.getPosition() + sf::Vector2f(-20, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet6);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet7 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(-0.136824, -0.98713),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet7->setPosition(sprite.getPosition() + sf::Vector2f(20, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet7);

				//射击音效
				audioManager.playSound("PlayerAttack1");
			}
			else
			{
				//五级攻击
				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet->setPosition(sprite.getPosition() + sf::Vector2f(-10, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet2 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet2->setPosition(sprite.getPosition() + sf::Vector2f(10, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet2);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet3 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet3"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					(atkBullet * 2)
				);
				//设置子弹的位置
				newBullet3->setPosition(sprite.getPosition() + sf::Vector2f(0, -10));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet3);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet4 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(-0.173648, -0.98526),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet4->setPosition(sprite.getPosition() + sf::Vector2f(-15, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet4);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet5 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0.173648, -0.98526),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet5->setPosition(sprite.getPosition() + sf::Vector2f(15, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet5);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet6 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0.136824, -0.98713),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet6->setPosition(sprite.getPosition() + sf::Vector2f(-20, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet6);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet7 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(-0.136824, -0.98713),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet7->setPosition(sprite.getPosition() + sf::Vector2f(20, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet7);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet8 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet8->setPosition(sprite.getPosition() + sf::Vector2f(20, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet8);

				// 创建一个新的子弹实例，
				std::shared_ptr<Bullet> newBullet9 = std::make_shared<PlayerBullet1>(
					assetManager.getTexture("Bullet2"),
					sf::Vector2f(0, -1),
					speedBullet,
					helthBullet,
					atkBullet
				);
				//设置子弹的位置
				newBullet9->setPosition(sprite.getPosition() + sf::Vector2f(-20, -5));

				// 将子弹添加到EntityManager中
				entityManager->getInstance()->addBullet(newBullet9);

				//射击音效
				audioManager.playSound("PlayerAttack1");
			}

		}
	}

	// 生命恢复逻辑
	timeTohealth += deltaTime;
	if (timeTohealth >= 1.f) { 
		health += healthRegenerationRate;
		timeTohealth -= 1.f;
		if (health >= maxHealth) health = maxHealth;  // 限制生命值上限
	}

	// 受击声音播放逻辑
	HitTimer += deltaTime;
	if (isBeHit == true && HitTimer >= 3.0f) {
		//音频管理器
		AudioManager& audioManager = AudioManager::getInstance();

		HitTimer = 0.f;

		// 生成一个0到6的随机数
		int randomSoundIndex = rand() % 7;

		// 根据生成的随机数播放对应的音效
		switch (randomSoundIndex) {
		case 0:
			audioManager.playSound("Jumko_Hit1");
			break;
		case 1:
			audioManager.playSound("Jumko_Hit2");
			break;
		case 2:
			audioManager.playSound("Jumko_Hit3");
			break;
		case 3:
			audioManager.playSound("Jumko_Hit4");
			break;
		case 4:
			audioManager.playSound("Jumko_Hit5");
			break;
		default:
			break;
		}
	}
	else
	{
		isBeHit = false;
	}


	// 技能释放逻辑
	if (isSkill) {
		//音频管理器
		AudioManager& audioManager = AudioManager::getInstance();
		//素材管理器
		AssetManager& assetManager = AssetManager::getInstance();
		//实体管理器
		EntityManager* entityManager = EntityManager::getInstance();

		isSkill = false;
		//技能的详细实现
		//...
		// 创建一个新的子弹实例，
		std::shared_ptr<Bullet> newBullet9 = std::make_shared<PlayerMagicBullet>(
			assetManager.getTexture("SkillButton"),
			sf::Vector2f(0, -1),
			1500,
			10000,
			atkBullet * 0.3
		);
		//设置子弹的位置
		newBullet9->setPosition(sprite.getPosition() + sf::Vector2f(-20, -5));

		// 将子弹添加到EntityManager中
		entityManager->getInstance()->addBullet(newBullet9);


		//播放技能音效
		audioManager.playSound("PlayerAttack2");
		audioManager.playSound("PlayerAttack3");
	}

	// 移动逻辑
	float currentMoveSpeed = slowMovement ? moveSpeed * 0.4f : moveSpeed;  // 减速时减半速度
	sf::Vector2f movement(0.f, 0.f);

	if (movingUp) movement.y -= 1.f;
	if (movingDown) movement.y += 1.f;
	if (movingLeft) movement.x -= 1.f;
	if (movingRight) movement.x += 1.f;

	// 如果同时移动在两个方向，则对移动向量进行归一化
	if (movement.x != 0.f && movement.y != 0.f) {
		movement /= std::sqrt(2.f); // 对角移动时分量长度是 1/sqrt(2)
	}

	// 应用速度和时间间隔
	movement *= currentMoveSpeed * deltaTime;

	// 移动玩家
	sprite.move(movement);

	//限制玩家位置
	// 获取新的玩家位置
	sf::Vector2f position = sprite.getPosition();
	// 约束玩家位置在游戏区域内
	if (position.x < 0) position.x = 0;
	if (position.x > 640) position.x = 640;
	if (position.y < 0) position.y = 0;
	if (position.y > 960) position.y = 960;
	// 设置玩家的位置
	sprite.setPosition(position);

	//将判定点设置到玩家中心
	hitboxSprite.setPosition(sprite.getPosition());

	//如果开启了无敌模式则不会获得分数
	if (isInvincible) {
		score = 0;
	}

	//测试区
	//std::cout << health << "   " << maxHealth << std::endl;
	
}

void Player::handleInput(sf::Event& event) {
	//处理事件
	SettingsManager& settingsManager = SettingsManager::getInstance();
	if (event.type == sf::Event::KeyPressed) {
		if (!settingsManager.iswasd)
		{
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
				// ... 其他键盘事件 ...
			}
		}
		else
		{
			switch (event.key.code) {
			case sf::Keyboard::W:
				movingUp = true;
				break;
			case sf::Keyboard::S:
				movingDown = true;
				break;
			case sf::Keyboard::A:
				movingLeft = true;
				break;
			case sf::Keyboard::D:
				movingRight = true;
				break;
			case sf::Keyboard::LShift:
				slowMovement = true;
				break;
			case sf::Keyboard::J:
				openFire = true;
				break;
				// ... 其他键盘事件 ...
			}
		}
		
	}
	else if (event.type == sf::Event::KeyReleased) {
		if (!settingsManager.iswasd)
		{
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
				// ... 其他键盘事件 ...
			}
		}
		else
		{
			switch (event.key.code) {
			case sf::Keyboard::W:
				movingUp = false;
				break;
			case sf::Keyboard::S:
				movingDown = false;
				break;
			case sf::Keyboard::A:
				movingLeft = false;
				break;
			case sf::Keyboard::D:
				movingRight = false;
				break;
			case sf::Keyboard::LShift:
				slowMovement = false;
				break;
			case sf::Keyboard::J:
				openFire = false;
				break;
				// ... 其他键盘事件 ...
			}
		}
		
	}
}

void Player::draw(sf::RenderWindow& window) {
	//渲染
	window.draw(sprite);
	window.draw(hitboxSprite);
}
#include "Enemy.hpp"
#include "Player.hpp"

sf::Vector2f Enemy::getPosition() {
	// 获取敌人的位置
	/*
	负责人: 波波沙

	功能:
		将当前敌人对象的位置返回

	参数:
		void

	返回值: sf::Vector2f
	*/
	//----------------------实现------------------------//
	return sprite.getPosition();
}

void Enemy::setPosition(sf::Vector2f position) {
	//设置敌人的位置
	/*
	负责人: 波波沙

	功能:
		一般用于初始化敌人

	参数:
		sf::Vector2f position	//位置

	返回值: sf::Vector2f
	*/
	//----------------------实现------------------------//
	sprite.setPosition(position);
}

sf::Vector2f Enemy::getDirectionTowardsPlayer() {
	// 计算指向玩家的单位向量
	/*
	负责人: 波波沙

	功能:
		返回一个从敌人指向玩家的单位向量

	参数:


	返回值: sf::Vector2f
	*/
	//----------------------实现------------------------//
	auto entityManager = EntityManager::getInstance();
	auto player = entityManager->getPlayer(); // 假设这会返回玩家的shared_ptr

	if (player) {
		sf::Vector2f playerPosition = player->getHitboxPosition(); // 或 getPosition，取决于你的需求
		sf::Vector2f direction = playerPosition - sprite.getPosition();
		float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

		if (length != 0) {
			direction /= length;
		}

		return direction;
	}
	else {
		// 如果没有找到玩家，返回零向量或者合适的默认值
		return sf::Vector2f(0, 0);
	}
}

void Enemy::takeDamage(int damage) {
	// 敌人受到伤害的方法
	/*
	负责人: 波波沙

	功能:
		使敌人掉血

	参数:void

	返回值: void
	*/
	//----------------------实现------------------------//

	health -= damage;

}


Enemy1::Enemy1(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd)
	: Enemy(texture, hp, dir, spd) {
	//构造方法
	/*
	负责人: 波波沙

	功能:
		构造敌人，这种类型的攻击模式的敌人的射速可以在这里调

	参数:
		const sf::Texture& texture    //敌人的贴图。

	返回值: void
	*/
	//----------------------实现------------------------//

	//将中心点设置到图片中心点
	sf::Vector2u textureSize = texture.getSize(); // 获取贴图的尺寸
	sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f); // 设置精灵的原点为贴图中心


	//射速
	attackCooldown = 3.0f;

	//初始化计时器
	attackTimer = 1.5f;
}

void Enemy1::update(float deltaTime) {
	// 实现特定的更新逻辑（未实现）
	/*
	负责人: 波波沙

	功能:
		将当前按钮的所有信息渲染到窗口缓冲中。

	参数:
		sf::RenderWindow& window    //要渲染到的地方。

	返回值: void
	*/
	//----------------------实现------------------------//

	// 计算新位置
	sf::Vector2f movement = direction * speed * deltaTime;

	// 更新精灵的位置
	sprite.move(movement);

	//发射子弹
	attackTimer += deltaTime;
	if (attackTimer >= attackCooldown) {
		attackTimer -= attackCooldown;
		//召唤大哥
		AssetManager& assetManager = AssetManager::getInstance();
		//引用音频播放单例
		AudioManager& audioManager = AudioManager::getInstance();

		// 创建一个新的子弹实例，
		std::shared_ptr<Bullet> newBullet = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet6"),
			sf::Vector2f(0, 1),
			250,
			1,
			150
		);
		//设置子弹的位置
		newBullet->setPosition(this->getPosition());

		// 将子弹添加到EntityManager中
		EntityManager::getInstance()->addBullet(newBullet);

		//播放开火音效
		audioManager.playSound("EnemyAttack1");
	}

	//敌人离开屏幕被销毁
	// 获取敌人位置...
	sf::Vector2f position = sprite.getPosition();
	// 设置额外的边界缓冲区
	float buffer = 80.0f; // 例如，80像素的缓冲区
	// 检查边界
	if (position.x < -buffer || position.x > 660 + buffer ||
		position.y < -buffer || position.y > 960 + buffer) {
		markForDestruction(); // 标记为待销毁
	}

	//血量情况的敌人要死亡并且爆金币
	if (health <= 0) {
		//引用音频播放单例
		AudioManager& audioManager = AudioManager::getInstance();
		//素材大哥
		AssetManager& assetManager = AssetManager::getInstance();
		//销毁敌人呢
		markForDestruction();
		//爆金币

		// 设定爆率阈值（0到100之间）
		int scorePointDropRate = 20; // 分数点的爆率
		int powerUpDropRate = 20; // 力量点的爆率
		// 随机决定是否爆出分数点
		if (rand() % 100 < scorePointDropRate) {
			std::shared_ptr<Bullet> newItem = std::make_shared<ScorePointItem>(
				assetManager.getTexture("ScorePoint"),
				sf::Vector2f(0, 1),
				130,
				10000,
				100
			);
			newItem->setPosition(this->getPosition() + sf::Vector2f(-5, 5));
			EntityManager::getInstance()->addBullet(newItem);
		}

		// 随机决定是否爆出力量点
		if (rand() % 100 < powerUpDropRate) {
			std::shared_ptr<Bullet> newItem2 = std::make_shared<PowerUpItem>(
				assetManager.getTexture("PowerPoint"),
				sf::Vector2f(0, 1),
				70,
				10000,
				15
			);
			newItem2->setPosition(this->getPosition() + sf::Vector2f(5, -5));
			EntityManager::getInstance()->addBullet(newItem2);
		}

		//播放死亡音效
		audioManager.playSound("EnemyDead1");
		//玩家加分
		EntityManager::getInstance()->getPlayer()->addScore(20);
	}
}

void Enemy1::draw(sf::RenderWindow& window) {
	// 渲染敌人
	/*
	负责人: 波波沙

	功能:
		将敌人渲染

	参数:
		sf::RenderWindow& window    //要渲染到的地方。

	返回值: void
	*/
	//----------------------实现------------------------//
	window.draw(sprite);
}

Enemy2::Enemy2(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd)
	: Enemy(texture, hp, dir, spd) {
	//构造方法
		/*
		负责人: 马亚楠

		功能:
			实现自机狙，实现朝向玩家发射

		参数:
			const sf::Texture& texture    //敌人的贴图。

		返回值: void
		*/
		//----------------------实现------------------------//

	//将中心点设置到图片中心点
	sf::Vector2u textureSize = texture.getSize(); // 获取贴图的尺寸
	sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f); // 设置精灵的原点为贴图中心


	//射速
	attackCooldown = 4.0f;

	//初始化计时器
	attackTimer = 3.0f;
}

void Enemy2::update(float deltaTime) {
	// 实现特定的更新逻辑（未实现）
	/*
	负责人: 马亚楠

	功能:
		将当前按钮的所有信息渲染到窗口缓冲中。

	参数:
		sf::RenderWindow& window    //要渲染到的地方。

	返回值: void
	*/
	//----------------------实现------------------------//

	// 计算新位置
	sf::Vector2f movement = direction * speed * deltaTime;

	// 更新精灵的位置
	sprite.move(movement);

	//发射子弹
	attackTimer += deltaTime;
	if (attackTimer >= attackCooldown) {
		attackTimer -= attackCooldown;
		//召唤大哥
		//引用音频播放单例
		AudioManager& audioManager = AudioManager::getInstance();
		AssetManager& assetManager = AssetManager::getInstance();

		//获得玩家的位置
		sf::Vector2f playerDirection = getDirectionTowardsPlayer();

		// 创建一个新的子弹实例，
		std::shared_ptr<Bullet> newBullet = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet8"),
			playerDirection,  //设置子弹朝向
			200,
			1,
			100
		);
		//设置子弹的位置
		newBullet->setPosition(this->getPosition());

		// 将子弹添加到EntityManager中
		EntityManager::getInstance()->addBullet(newBullet);

		//播放开火音效
		audioManager.playSound("EnemyAttack1");
	}

	//敌人离开屏幕被销毁
	// 获取敌人位置...
	sf::Vector2f position = sprite.getPosition();
	// 设置额外的边界缓冲区
	float buffer = 80.0f; // 例如，80像素的缓冲区
	// 检查边界
	if (position.x < -buffer || position.x > 660 + buffer ||
		position.y < -buffer || position.y > 960 + buffer) {
		markForDestruction(); // 标记为待销毁
	}

	//血量情况的敌人要死亡并且爆金币
	if (health <= 0) {
		//引用音频播放单例
		AudioManager& audioManager = AudioManager::getInstance();
		//素材大哥
		AssetManager& assetManager = AssetManager::getInstance();
		//销毁敌人呢
		markForDestruction();
		//爆金币

		// 设定爆率阈值（0到100之间）
		int scorePointDropRate = 20; // 分数点的爆率
		int powerUpDropRate = 40; // 力量点的爆率
		// 随机决定是否爆出分数点
		if (rand() % 100 < scorePointDropRate) {
			std::shared_ptr<Bullet> newItem = std::make_shared<ScorePointItem>(
				assetManager.getTexture("ScorePoint"),
				sf::Vector2f(0, 1),
				130,
				10000,
				100
			);
			newItem->setPosition(this->getPosition() + sf::Vector2f(-5, 5));
			EntityManager::getInstance()->addBullet(newItem);
		}

		// 随机决定是否爆出力量点
		if (rand() % 100 < powerUpDropRate) {
			std::shared_ptr<Bullet> newItem2 = std::make_shared<PowerUpItem>(
				assetManager.getTexture("PowerPoint"),
				sf::Vector2f(0, 1),
				70,
				10000,
				15
			);
			newItem2->setPosition(this->getPosition() + sf::Vector2f(5, -5));
			EntityManager::getInstance()->addBullet(newItem2);
		}

		//播放死亡音效
		audioManager.playSound("EnemyDead1");
		//玩家加分
		EntityManager::getInstance()->getPlayer()->addScore(30);
	}
}

void Enemy2::draw(sf::RenderWindow& window) {
	// 渲染敌人
	/*
	负责人: 马亚楠

	功能:
		将敌人渲染

	参数:
		sf::RenderWindow& window    //要渲染到的地方。

	返回值: void
	*/
	//----------------------实现------------------------//
	window.draw(sprite);
}

Enemy3::Enemy3(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd)
	: Enemy(texture, hp, dir, spd) {
	//构造方法
	/*
	负责人: 小杨

	功能:
		发射三发散弹

	参数:
		const sf::Texture& texture    //敌人的贴图。

	返回值: void
	*/
	//----------------------实现------------------------//
	//将中心点设置到图片中心点
	sf::Vector2u textureSize = texture.getSize(); // 获取贴图的尺寸
	sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f); // 设置精灵的原点为贴图中心


	//射速
	attackCooldown = 4.0f;

	//初始化计时器
	attackTimer = 3.0f;
}



void Enemy3::update(float deltaTime) {
	// 实现特定的更新逻辑（未实现）
	/*
	负责人: 小杨

	功能:
		将当前按钮的所有信息渲染到窗口缓冲中。

	参数:
		sf::RenderWindow& window    //要渲染到的地方。

	返回值: void
	*/
	//----------------------实现------------------------//

	// 计算新位置
	sf::Vector2f movement = direction * speed * deltaTime;

	// 更新精灵的位置
	sprite.move(movement);

	// 发射 3 发散弹
	attackTimer += deltaTime;
	if (attackTimer >= attackCooldown) {
		attackTimer -= attackCooldown;
		//引用音频播放单例
		AudioManager& audioManager = AudioManager::getInstance();
		AssetManager& assetManager = AssetManager::getInstance();
		float angleInRadians = 20.0f * (3.14159265359f / 180.0f);
		sf::Vector2f sideDirection1(-std::sin(angleInRadians), std::cos(angleInRadians));
		sf::Vector2f sideDirection2(-std::sin(-angleInRadians), std::cos(-angleInRadians));

		// 创建三个新的子弹实例，
		std::shared_ptr<Bullet> newBullet1 = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet1"),
			sf::Vector2f(0, 1),  //设置子弹朝向
			250,
			1,
			150
		);
		std::shared_ptr<Bullet> newBullet2 = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet1"),
			sideDirection1,  //设置子弹朝向
			250,
			1,
			150
		);
		std::shared_ptr<Bullet> newBullet3 = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet1"),
			sideDirection2,  //设置子弹朝向
			250,
			1,
			150
		);
		//设置子弹的位置
		newBullet1->setPosition(this->getPosition());
		newBullet2->setPosition(this->getPosition());
		newBullet3->setPosition(this->getPosition());
		// 将子弹添加到EntityManager中
		EntityManager::getInstance()->addBullet(newBullet1);
		EntityManager::getInstance()->addBullet(newBullet2);
		EntityManager::getInstance()->addBullet(newBullet3);
		//播放开火音效
		audioManager.playSound("EnemyAttack1");
	}

	//敌人离开屏幕被销毁
	// 获取敌人位置...
	sf::Vector2f position = sprite.getPosition();
	// 设置额外的边界缓冲区
	float buffer = 80.0f; // 例如，80像素的缓冲区
	// 检查边界
	if (position.x < -buffer || position.x > 660 + buffer ||
		position.y < -buffer || position.y > 960 + buffer) {
		markForDestruction(); // 标记为待销毁
	}

	//血量情况的敌人要死亡并且爆金币
	if (health <= 0) {
		//引用音频播放单例
		AudioManager& audioManager = AudioManager::getInstance();
		//素材大哥
		AssetManager& assetManager = AssetManager::getInstance();
		//销毁敌人呢
		markForDestruction();
		//爆金币

		// 设定爆率阈值（0到100之间）
		int scorePointDropRate = 30; // 分数点的爆率
		int powerUpDropRate = 40; // 力量点的爆率
		// 随机决定是否爆出分数点
		if (rand() % 100 < scorePointDropRate) {
			std::shared_ptr<Bullet> newItem = std::make_shared<ScorePointItem>(
				assetManager.getTexture("ScorePoint"),
				sf::Vector2f(0, 1),
				130,
				10000,
				100
			);
			newItem->setPosition(this->getPosition() + sf::Vector2f(-5, 5));
			EntityManager::getInstance()->addBullet(newItem);
		}

		// 随机决定是否爆出力量点
		if (rand() % 100 < powerUpDropRate) {
			std::shared_ptr<Bullet> newItem2 = std::make_shared<PowerUpItem>(
				assetManager.getTexture("PowerPoint"),
				sf::Vector2f(0, 1),
				70,
				10000,
				15
			);
			newItem2->setPosition(this->getPosition() + sf::Vector2f(5, -5));
			EntityManager::getInstance()->addBullet(newItem2);
		}

		//播放死亡音效
		audioManager.playSound("EnemyDead1");
		//玩家加分
		EntityManager::getInstance()->getPlayer()->addScore(40);
	}
}

void Enemy3::draw(sf::RenderWindow& window) {
	// 渲染敌人
	/*
	负责人: 小杨

	功能:
		将敌人渲染

	参数:
		sf::RenderWindow& window    //要渲染到的地方。

	返回值: void
	*/
	//----------------------实现------------------------//
	window.draw(sprite);
}


Enemy4::Enemy4(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd)
	: Enemy(texture, hp, dir, spd) {
	//构造方法
	/*
	负责人: 小杨

	功能:发射五发散弹


	参数:
		const sf::Texture& texture    //敌人的贴图。

	返回值: void
	*/
	//----------------------实现------------------------//

	//将中心点设置到图片中心点
	sf::Vector2u textureSize = texture.getSize(); // 获取贴图的尺寸
	sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f); // 设置精灵的原点为贴图中心


	//射速
	attackCooldown = 5.0f;

	//初始化计时器
	attackTimer = 4.0f;
}



void Enemy4::update(float deltaTime) {
	// 实现特定的更新逻辑（未实现）
	/*
	负责人: 小杨

	功能:
		将当前按钮的所有信息渲染到窗口缓冲中。

	参数:
		sf::RenderWindow& window    //要渲染到的地方。

	返回值: void
	*/
	//----------------------实现------------------------//

	// 计算新位置
	sf::Vector2f movement = direction * speed * deltaTime;

	// 更新精灵的位置
	sprite.move(movement);
	// 发射 5 发散弹
	attackTimer += deltaTime;
	if (attackTimer >= attackCooldown) {
		attackTimer -= attackCooldown;
		//引用音频播放单例
		AudioManager& audioManager = AudioManager::getInstance();
		AssetManager& assetManager = AssetManager::getInstance();
		// 计算两边合适的角度
		float angleInRadians = 20.0f * (3.14159265359f / 180.0f);
		sf::Vector2f sideDirection1(-std::sin(angleInRadians), std::cos(angleInRadians)
		);
		sf::Vector2f sideDirection2(-std::sin(-angleInRadians), std::cos(-angleInRadians)
		);

		float angleInRadians1 = 10.0f * (3.14159265359f / 180.0f);
		sf::Vector2f sideDirection3(-std::sin(angleInRadians1), std::cos(angleInRadians1)
		);
		sf::Vector2f sideDirection4(-std::sin(-angleInRadians1), std::cos(-angleInRadians1)
		);
		// 创建五个新的子弹实例，
		std::shared_ptr<Bullet> newBullet1 = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet10"),
			sf::Vector2f(0, 1),  //设置子弹朝向
			250,
			1,
			100
		);
		std::shared_ptr<Bullet> newBullet2 = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet10"),
			sideDirection1,  //设置子弹朝向
			250,
			1,
			100
		);
		std::shared_ptr<Bullet> newBullet3 = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet10"),
			sideDirection2,  //设置子弹朝向
			250,
			1,
			100
		);
		std::shared_ptr<Bullet> newBullet4 = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet10"),
			sideDirection3,  //设置子弹朝向
			250,
			1,
			100
		);
		std::shared_ptr<Bullet> newBullet5 = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet10"),
			sideDirection4,  //设置子弹朝向
			250,
			1,
			100
		);
		//设置子弹的位置
		newBullet1->setPosition(this->getPosition());

		// 将子弹添加到EntityManager中
		EntityManager::getInstance()->addBullet(newBullet1);
		//设置子弹的位置
		newBullet2->setPosition(this->getPosition());

		// 将子弹添加到EntityManager中
		EntityManager::getInstance()->addBullet(newBullet2);
		//设置子弹的位置
		newBullet3->setPosition(this->getPosition());

		// 将子弹添加到EntityManager中
		EntityManager::getInstance()->addBullet(newBullet3);
		//设置子弹的位置
		newBullet4->setPosition(this->getPosition());

		// 将子弹添加到EntityManager中
		EntityManager::getInstance()->addBullet(newBullet4);
		//设置子弹的位置
		newBullet5->setPosition(this->getPosition());

		// 将子弹添加到EntityManager中
		EntityManager::getInstance()->addBullet(newBullet5);

		//播放开火音效
		audioManager.playSound("EnemyAttack1");
	}

	//敌人离开屏幕被销毁
	// 获取敌人位置...
	sf::Vector2f position = sprite.getPosition();
	// 设置额外的边界缓冲区
	float buffer = 80.0f; // 例如，80像素的缓冲区
	// 检查边界
	if (position.x < -buffer || position.x > 660 + buffer ||
		position.y < -buffer || position.y > 960 + buffer) {
		markForDestruction(); // 标记为待销毁
	}

	//血量情况的敌人要死亡并且爆金币
	if (health <= 0) {
		//引用音频播放单例
		AudioManager& audioManager = AudioManager::getInstance();
		//素材大哥
		AssetManager& assetManager = AssetManager::getInstance();
		//销毁敌人呢
		markForDestruction();
		//爆金币

		// 设定爆率阈值（0到100之间）
		int scorePointDropRate = 40; // 分数点的爆率
		int powerUpDropRate = 50; // 力量点的爆率
		// 随机决定是否爆出分数点
		if (rand() % 100 < scorePointDropRate) {
			std::shared_ptr<Bullet> newItem = std::make_shared<ScorePointItem>(
				assetManager.getTexture("ScorePoint"),
				sf::Vector2f(0, 1),
				130,
				10000,
				100
			);
			newItem->setPosition(this->getPosition() + sf::Vector2f(-5, 5));
			EntityManager::getInstance()->addBullet(newItem);
		}

		// 随机决定是否爆出力量点
		if (rand() % 100 < powerUpDropRate) {
			std::shared_ptr<Bullet> newItem2 = std::make_shared<PowerUpItem>(
				assetManager.getTexture("PowerPoint"),
				sf::Vector2f(0, 1),
				70,
				10000,
				15
			);
			newItem2->setPosition(this->getPosition() + sf::Vector2f(5, -5));
			EntityManager::getInstance()->addBullet(newItem2);
		}

		//播放死亡音效
		audioManager.playSound("EnemyDead1");
		//玩家加分
		EntityManager::getInstance()->getPlayer()->addScore(60);
	}
}

void Enemy4::draw(sf::RenderWindow& window) {
	// 渲染敌人
	/*
	负责人: 波波沙

	功能:
		将敌人渲染

	参数:
		sf::RenderWindow& window    //要渲染到的地方。

	返回值: void
	*/
	//----------------------实现------------------------//
	window.draw(sprite);
}


Enemy5::Enemy5(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd)
	: Enemy(texture, hp, dir, spd) {
	//构造方法
	/*
	负责人: 马亚楠

	功能:
		向敌人方向发射三发散弹

	参数:
		const sf::Texture& texture    //敌人的贴图。

	返回值: void
	*/
	//----------------------实现------------------------//
	//将中心点设置到图片中心点
	sf::Vector2u textureSize = texture.getSize(); // 获取贴图的尺寸
	sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f); // 设置精灵的原点为贴图中心


	//射速
	attackCooldown = 5.0f;

	//初始化计时器
	attackTimer = 4.0f;
}
void Enemy5::update(float deltaTime) {
	// 实现特定的更新逻辑（未实现）
	/*
	负责人: 马亚楠

	功能:
		将当前按钮的所有信息渲染到窗口缓冲中。

	参数:
		sf::RenderWindow& window    //要渲染到的地方。

	返回值: void
	*/
	//----------------------实现------------------------//

	// 计算新位置
	sf::Vector2f movement = direction * speed * deltaTime;

	// 更新精灵的位置
	sprite.move(movement);

	//发射子弹
	attackTimer += deltaTime;
	if (attackTimer >= attackCooldown) {
		attackTimer -= attackCooldown;
		//召唤大哥
		AssetManager& assetManager = AssetManager::getInstance();
		//引用音频播放单例
		AudioManager& audioManager = AudioManager::getInstance();

		//获得玩家的位置
		sf::Vector2f playerDirection = getDirectionTowardsPlayer();

		// 计算朝向敌人的方向
		float angleInRadians = 20.0f * (3.14159265359f / 180.0f);
		sf::Vector2f sideDirection1(
			playerDirection.x * std::cos(angleInRadians) - playerDirection.y * std::sin(angleInRadians),
			playerDirection.x * std::sin(angleInRadians) + playerDirection.y * std::cos(angleInRadians)
		);
		sf::Vector2f sideDirection2(
			playerDirection.x * std::cos(-angleInRadians) - playerDirection.y * std::sin(-angleInRadians),
			playerDirection.x * std::sin(-angleInRadians) + playerDirection.y * std::cos(-angleInRadians)
		);

		// 创建三个新的子弹实例，
		std::shared_ptr<Bullet> newBullet1 = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet7"),
			playerDirection,  //设置子弹朝向
			200,
			1,
			100
		);
		std::shared_ptr<Bullet> newBullet2 = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet7"),
			sideDirection1,  //设置子弹朝向
			200,
			1,
			100
		);
		std::shared_ptr<Bullet> newBullet3 = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet7"),
			sideDirection2,  //设置子弹朝向
			200,
			1,
			100
		);
		//设置子弹的位置
		newBullet1->setPosition(this->getPosition());

		// 将子弹添加到EntityManager中
		EntityManager::getInstance()->addBullet(newBullet1);
		//设置子弹的位置
		newBullet2->setPosition(this->getPosition());

		// 将子弹添加到EntityManager中
		EntityManager::getInstance()->addBullet(newBullet2);
		//设置子弹的位置
		newBullet3->setPosition(this->getPosition());

		// 将子弹添加到EntityManager中
		EntityManager::getInstance()->addBullet(newBullet3);

		//播放开火音效
		audioManager.playSound("EnemyAttack1");
	}

	//敌人离开屏幕被销毁
	// 获取敌人位置...
	sf::Vector2f position = sprite.getPosition();
	// 设置额外的边界缓冲区
	float buffer = 80.0f; // 例如，80像素的缓冲区
	// 检查边界
	if (position.x < -buffer || position.x > 660 + buffer ||
		position.y < -buffer || position.y > 960 + buffer) {
		markForDestruction(); // 标记为待销毁
	}

	//血量情况的敌人要死亡并且爆金币
	if (health <= 0) {
		//引用音频播放单例
		AudioManager& audioManager = AudioManager::getInstance();
		//素材大哥
		AssetManager& assetManager = AssetManager::getInstance();
		//销毁敌人呢
		markForDestruction();
		//爆金币

		// 设定爆率阈值（0到100之间）
		int scorePointDropRate = 40; // 分数点的爆率
		int powerUpDropRate = 60; // 力量点的爆率
		// 随机决定是否爆出分数点
		if (rand() % 100 < scorePointDropRate) {
			std::shared_ptr<Bullet> newItem = std::make_shared<ScorePointItem>(
				assetManager.getTexture("ScorePoint"),
				sf::Vector2f(0, 1),
				130,
				10000,
				100
			);
			newItem->setPosition(this->getPosition() + sf::Vector2f(-5, 5));
			EntityManager::getInstance()->addBullet(newItem);
		}

		// 随机决定是否爆出力量点
		if (rand() % 100 < powerUpDropRate) {
			std::shared_ptr<Bullet> newItem2 = std::make_shared<PowerUpItem>(
				assetManager.getTexture("PowerPoint"),
				sf::Vector2f(0, 1),
				70,
				10000,
				15
			);
			newItem2->setPosition(this->getPosition() + sf::Vector2f(5, -5));
			EntityManager::getInstance()->addBullet(newItem2);
		}

		//播放死亡音效
		audioManager.playSound("EnemyDead1");
		//玩家加分
		EntityManager::getInstance()->getPlayer()->addScore(70);
	}
}
void Enemy5::draw(sf::RenderWindow& window) {
	// 渲染敌人
	/*
	负责人: 马亚楠

	功能:
		将敌人渲染

	参数:
		sf::RenderWindow& window    //要渲染到的地方。

	返回值: void
	*/
	//----------------------实现------------------------//
	window.draw(sprite);
}
Enemy6::Enemy6(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd)
	: Enemy(texture, hp, dir, spd) {
	//构造方法
	/*
	负责人: 马亚楠

	功能:
		向敌人方向发射五发散弹

	参数:
		const sf::Texture& texture    //敌人的贴图。

	返回值: void
	*/
	//----------------------实现------------------------//

	//将中心点设置到图片中心点
	sf::Vector2u textureSize = texture.getSize(); // 获取贴图的尺寸
	sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f); // 设置精灵的原点为贴图中心


	//射速
	attackCooldown = 6.0f;

	//初始化计时器
	attackTimer = 5.0f;
}


void Enemy6::update(float deltaTime) {
	// 实现特定的更新逻辑（未实现）
	/*
	负责人: 马亚楠

	功能:
		将当前按钮的所有信息渲染到窗口缓冲中。

	参数:
		sf::RenderWindow& window    //要渲染到的地方。

	返回值: void
	*/
	//----------------------实现------------------------//

	// 计算新位置
	sf::Vector2f movement = direction * speed * deltaTime;

	// 更新精灵的位置
	sprite.move(movement);

	//发射子弹
	attackTimer += deltaTime;
	if (attackTimer >= attackCooldown) {
		attackTimer -= attackCooldown;
		//引用音频播放单例
		AudioManager& audioManager = AudioManager::getInstance();
		//召唤大哥
		AssetManager& assetManager = AssetManager::getInstance();

		//获得玩家的位置
		sf::Vector2f playerDirection = getDirectionTowardsPlayer();

		// 计算两边合适的角度
		float angleInRadians = 20.0f * (3.14159265359f / 180.0f);
		sf::Vector2f sideDirection1(
			playerDirection.x * std::cos(angleInRadians) - playerDirection.y * std::sin(angleInRadians),
			playerDirection.x * std::sin(angleInRadians) + playerDirection.y * std::cos(angleInRadians)
		);
		sf::Vector2f sideDirection2(
			playerDirection.x * std::cos(-angleInRadians) - playerDirection.y * std::sin(-angleInRadians),
			playerDirection.x * std::sin(-angleInRadians) + playerDirection.y * std::cos(-angleInRadians)
		);

		float angleInRadians1 = 10.0f * (3.14159265359f / 180.0f);
		sf::Vector2f sideDirection3(
			playerDirection.x * std::cos(angleInRadians1) - playerDirection.y * std::sin(angleInRadians1),
			playerDirection.x * std::sin(angleInRadians1) + playerDirection.y * std::cos(angleInRadians1)
		);
		sf::Vector2f sideDirection4(
			playerDirection.x * std::cos(-angleInRadians1) - playerDirection.y * std::sin(-angleInRadians1),
			playerDirection.x * std::sin(-angleInRadians1) + playerDirection.y * std::cos(-angleInRadians1)
		);


		// 创建五个新的子弹实例，
		std::shared_ptr<Bullet> newBullet1 = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet9"),
			playerDirection,  //设置子弹朝向
			200,
			1,
			100
		);
		std::shared_ptr<Bullet> newBullet2 = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet9"),
			sideDirection1,  //设置子弹朝向
			200,
			1,
			100
		);
		std::shared_ptr<Bullet> newBullet3 = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet9"),
			sideDirection2,  //设置子弹朝向
			200,
			1,
			100
		);
		std::shared_ptr<Bullet> newBullet4 = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet9"),
			sideDirection3,  //设置子弹朝向
			200,
			1,
			100
		);
		std::shared_ptr<Bullet> newBullet5 = std::make_shared<EnemyBullet1>(
			assetManager.getTexture("Bullet9"),
			sideDirection4,  //设置子弹朝向
			200,
			1,
			100
		);
		//设置子弹的位置
		newBullet1->setPosition(this->getPosition());

		// 将子弹添加到EntityManager中
		EntityManager::getInstance()->addBullet(newBullet1);
		//设置子弹的位置
		newBullet2->setPosition(this->getPosition());

		// 将子弹添加到EntityManager中
		EntityManager::getInstance()->addBullet(newBullet2);
		//设置子弹的位置
		newBullet3->setPosition(this->getPosition());

		// 将子弹添加到EntityManager中
		EntityManager::getInstance()->addBullet(newBullet3);
		//设置子弹的位置
		newBullet4->setPosition(this->getPosition());

		// 将子弹添加到EntityManager中
		EntityManager::getInstance()->addBullet(newBullet4);
		//设置子弹的位置
		newBullet5->setPosition(this->getPosition());

		// 将子弹添加到EntityManager中
		EntityManager::getInstance()->addBullet(newBullet5);

		//播放开火音效
		audioManager.playSound("EnemyAttack1");
	}

	//敌人离开屏幕被销毁
	// 获取敌人位置...
	sf::Vector2f position = sprite.getPosition();
	// 设置额外的边界缓冲区
	float buffer = 80.0f; // 例如，80像素的缓冲区
	// 检查边界
	if (position.x < -buffer || position.x > 660 + buffer ||
		position.y < -buffer || position.y > 960 + buffer) {
		markForDestruction(); // 标记为待销毁
	}

	//血量情况的敌人要死亡并且爆金币
	if (health <= 0) {
		//引用音频播放单例
		AudioManager& audioManager = AudioManager::getInstance();
		//素材大哥
		AssetManager& assetManager = AssetManager::getInstance();
		//销毁敌人呢
		markForDestruction();
		//爆金币

		// 设定爆率阈值（0到100之间）
		int scorePointDropRate = 50; // 分数点的爆率
		int powerUpDropRate = 70; // 力量点的爆率
		// 随机决定是否爆出分数点
		if (rand() % 100 < scorePointDropRate) {
			std::shared_ptr<Bullet> newItem = std::make_shared<ScorePointItem>(
				assetManager.getTexture("ScorePoint"),
				sf::Vector2f(0, 1),
				130,
				10000,
				100
			);
			newItem->setPosition(this->getPosition() + sf::Vector2f(-5, 5));
			EntityManager::getInstance()->addBullet(newItem);
		}

		// 随机决定是否爆出力量点
		if (rand() % 100 < powerUpDropRate) {
			std::shared_ptr<Bullet> newItem2 = std::make_shared<PowerUpItem>(
				assetManager.getTexture("PowerPoint"),
				sf::Vector2f(0, 1),
				70,
				10000,
				15
			);
			newItem2->setPosition(this->getPosition() + sf::Vector2f(5, -5));
			EntityManager::getInstance()->addBullet(newItem2);
		}

		//播放死亡音效
		audioManager.playSound("EnemyDead1");
		//玩家加分
		EntityManager::getInstance()->getPlayer()->addScore(80);
	}
}

void Enemy6::draw(sf::RenderWindow& window) {
	// 渲染敌人
	/*
	负责人: 马亚楠

	功能:
		将敌人渲染

	参数:
		sf::RenderWindow& window    //要渲染到的地方。

	返回值: void
	*/
	//----------------------实现------------------------//
	window.draw(sprite);
}

EliteEnemy1::EliteEnemy1(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd)
	:Enemy(texture, hp, dir, spd) {

	//将中心点设置到图片中心点
	sf::Vector2u textureSize = texture.getSize(); // 获取贴图的尺寸
	sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f); // 设置精灵的原点为贴图中心


	//射速
	attackCooldown = 1.f;

	//初始化计时器
	attackTimer = 0.f;

	timer = 0.0f;
	SelectDirect = 1;//默认=1为向下移动
	upgradeAttack = 0.0f;
	SelectAttack = 1;
}

void EliteEnemy1::update(float deltaTime) {

	timer += deltaTime;
	if (timer > 1.8f)
	{
		SelectDirect++;
		timer = 0.0f;
	}
	if (SelectDirect == 1)
	{
		direction = sf::Vector2f(0, 1);
	}
	else if (SelectDirect == 2)
	{
		direction = sf::Vector2f(1, 0);
	}
	else if (SelectDirect == 3)
	{
		direction = sf::Vector2f(-1.2, 0);
	}
	else if (SelectDirect >= 4)
	{
		SelectDirect = 1;
	}
	// 计算新位置
	sf::Vector2f movement = direction * speed * deltaTime;
	// 更新精灵的位置
	sprite.move(movement);
	//发射子弹
	upgradeAttack += deltaTime;

	if (upgradeAttack > 2.5f)//每隔2.5秒换一次攻击方式
	{
		SelectAttack++;
		upgradeAttack = 0.0f;
	}
	if (SelectAttack == 1) //选择攻击方式1
	{
		attackTimer += deltaTime;
		if (attackTimer >= attackCooldown) {
			attackTimer -= attackCooldown;
			AssetManager& assetManager = AssetManager::getInstance();

			// 创建一个新的子弹实例，
			std::shared_ptr<Bullet> newBullet = std::make_shared<EnemyBullet1>(
				assetManager.getTexture("Bullet1"),
				sf::Vector2f(0, 1),
				500,
				1,
				10
			);
			//设置子弹的位置
			newBullet->setPosition(this->getPosition());

			// 将子弹添加到EntityManager中
			EntityManager::getInstance()->addBullet(newBullet);
		}
	}
	else if (SelectAttack == 2) //选择攻击方式2
	{
		attackTimer += deltaTime;
		if (attackTimer >= attackCooldown) {
			attackTimer -= attackCooldown;
			AssetManager& assetManager = AssetManager::getInstance();

			// 创建一个新的子弹实例，
			std::shared_ptr<Bullet> newBullet1 = std::make_shared<EnemyBullet1>(
				assetManager.getTexture("Bullet1"),
				sf::Vector2f(0, 1),
				500,
				1,
				10
			);
			std::shared_ptr<Bullet> newBullet2 = std::make_shared<EnemyBullet1>(
				assetManager.getTexture("Bullet1"),
				sf::Vector2f(0, 1),
				500,
				1,
				10
			);
			//设置子弹的位置
			newBullet1->setPosition(this->getPosition() + sf::Vector2f(-8, -5));
			newBullet2->setPosition(this->getPosition() + sf::Vector2f(8, -5));
			// 将子弹添加到EntityManager中
			EntityManager::getInstance()->addBullet(newBullet1);
			EntityManager::getInstance()->addBullet(newBullet2);
		}
	}
	else if (SelectAttack >= 3)//重置攻击选择
	{
		SelectAttack = 1;
	}


	//敌人离开屏幕被销毁
	// 获取敌人位置...
	sf::Vector2f position = sprite.getPosition();
	// 设置额外的边界缓冲区
	float buffer = 80.0f; // 例如，80像素的缓冲区
	// 检查边界
	if (position.x < -buffer || position.x > 660 + buffer ||
		position.y < -buffer || position.y > 960 + buffer) {
		markForDestruction(); // 标记为待销毁
	}

	//血量情况的敌人要死亡并且爆金币
	if (health <= 0) {
		markForDestruction();
		//爆金币
		//...
	}
}

void EliteEnemy1::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

Spider::Spider(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd)
	:Enemy(texture, hp, dir, spd) {

	//将中心点设置到图片中心点
	sf::Vector2u textureSize = texture.getSize(); // 获取贴图的尺寸
	sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f); // 设置精灵的原点为贴图中心

	//记录最大血量
	MaxHealth = health;

	//射速
	attackCooldown = 1.f;

	//初始化计时器
	attackTimer = 0.f;

	timer = 0.0f;
	SelectDirect = 1;//默认=1为向下移动
	upgradeAttack = 0.0f;
	SelectAttack = 1;
	isInRedMode1 = false;
	isInRedMode2 = true;
}

void Spider::update(float deltaTime) {
	//-------------蜘蛛精英怪的更新逻辑----------------
	/*
		负责人: 朱
		功能: 实现蜘蛛怪的运行逻辑
			  蜘蛛进入屏幕的时候（假设从480.0f, 0.0f）进来

			  循环三次以下
			  蜘蛛左右移动向左移动 移动到屏幕左端 停留 2s
			  (移动时候从最左边移动到最右边需要2s)
			  蜘蛛移动到屏幕右边 停留 2s

			  最后从最右端移动到屏幕进入位置停留2s ，若其没死 就原路返回

		返回值: void
		参数: float deltaTime //系统传入的时间
	*/
	timer += deltaTime;
	//召唤素材大哥
	AssetManager& assetManager = AssetManager::getInstance();

	if (timer < 1.0f) {
		direction = sf::Vector2f(0, 0);
	}
	else if (timer >= 1.0f && timer < 2.0f) { // 1s 进入屏幕 中间位置
		direction = sf::Vector2f(0, 1);
	}
	else if (timer >= 2.0f && timer < 3.0f) { // 向左移动1s
		direction = sf::Vector2f(-1, 0);
		SelectAttack = 1;
	}
	else if (timer >= 3.0f && timer < 5.0f) {
		direction = sf::Vector2f(0, 0);// 左端停留2s
		SelectAttack = 2;
	}
	else if (timer >= 5.0f && timer < 7.0f) {//向右移动2s
		direction = sf::Vector2f(1, 0);
		SelectAttack = 1;
	}
	else if (timer >= 7.0f && timer < 9.0f) {// 右端停留2s
		direction = sf::Vector2f(0, 0);
		SelectAttack = 2;
	}
	else if (timer >= 9.0f && timer < 11.0f) {//向左移动2s
		direction = sf::Vector2f(-1, 0);
		SelectAttack = 1;
	}
	if (timer >= 11.0f && timer < 13.0f) { // 左端停留2s
		direction = sf::Vector2f(0, 0);
		SelectAttack = 2;
	}
	else if (timer >= 13.0f && timer < 15.0f) { //向右边移动2s
		direction = sf::Vector2f(1, 0);
		SelectAttack = 1;
	}
	else if (timer >= 15.0f && timer < 17.0f) {// 右端停2s
		direction = sf::Vector2f(0, 0);
		SelectAttack = 2;
	}
	else if (timer >= 17.0f && timer < 19.0f) {//向左移动2s
		direction = sf::Vector2f(-1, 0);
		SelectAttack = 1;
	}
	if (timer >= 19.0f && timer < 21.0f) { // 左端停留2s
		direction = sf::Vector2f(0, 0);
		SelectAttack = 2;
	}
	else if (timer >= 21.0f && timer < 23.0f) { //向右边移动2s
		direction = sf::Vector2f(1, 0);
		SelectAttack = 1;
	}
	else if (timer >= 23.0f && timer < 25.0f) {// 右端停2s
		direction = sf::Vector2f(0, 0);
		SelectAttack = 2;
	}
	else if (timer >= 25.0f && timer < 26.0f) {// 向左移动1s 停在中间位置
		direction = sf::Vector2f(-1, 0);
		SelectAttack = 1;
	}
	else if (timer >= 26.0f && timer < 28.0f) {// 中间位置停2s
		direction = sf::Vector2f(0, 0);
		SelectAttack = 2;
	}
	else if (timer >= 28.0f && timer < 30.0f) { //向上快速移动离开屏幕
		direction = sf::Vector2f(0, -1);
	}
	if (health > MaxHealth * 0.4 && health <= MaxHealth * 0.7) {
		isInRedMode1 = true;
		attackCooldown = 0.5f;
	}
	else if (health <= MaxHealth * 0.4) {
		isInRedMode2 = true;
	}
	// 计算新位置
	sf::Vector2f movement = direction * speed * deltaTime;
	// 更新精灵的位置
	sprite.move(movement);
	//发射子弹
	upgradeAttack += deltaTime;

	if (SelectAttack == 1) //选择攻击方式1 移动的时候射击
	{
		attackTimer += deltaTime;
		if (attackTimer >= attackCooldown) {
			attackTimer -= attackCooldown;
			//获得玩家的位置
			sf::Vector2f playerDirection = getDirectionTowardsPlayer();
			// 创建一个新的子弹实例，
			std::shared_ptr<Bullet> newBullet = std::make_shared<EnemyBullet1>(
				assetManager.getTexture("Bullet5"),
				playerDirection,
				300,
				1,
				200
			);
			//设置子弹的位置
			newBullet->setPosition(this->getPosition());

			// 将子弹添加到EntityManager中
			EntityManager::getInstance()->addBullet(newBullet);
		}
	}
	else if (SelectAttack == 2) //选择攻击方式2
	{
		//获得玩家的位置
		sf::Vector2f playerDirection = getDirectionTowardsPlayer();
		attackTimer += deltaTime;
		if (attackTimer >= attackCooldown / 4) {
			// Calculate the direction of the side bullets (rotate by +/- 45 degrees)
			float angleInRadians = 20.0f * (3.14159265359f / 180.0f);
			sf::Vector2f sideDirection1(
				playerDirection.x * std::cos(angleInRadians) - playerDirection.y * std::sin(angleInRadians),
				playerDirection.x * std::sin(angleInRadians) + playerDirection.y * std::cos(angleInRadians)
			);
			sf::Vector2f sideDirection2(
				playerDirection.x * std::cos(-angleInRadians) - playerDirection.y * std::sin(-angleInRadians),
				playerDirection.x * std::sin(-angleInRadians) + playerDirection.y * std::cos(-angleInRadians)
			);

			float angleInRadians1 = 10.0f * (3.14159265359f / 180.0f);
			sf::Vector2f sideDirection3(
				playerDirection.x * std::cos(angleInRadians1) - playerDirection.y * std::sin(angleInRadians1),
				playerDirection.x * std::sin(angleInRadians1) + playerDirection.y * std::cos(angleInRadians1)
			);
			sf::Vector2f sideDirection4(
				playerDirection.x * std::cos(-angleInRadians1) - playerDirection.y * std::sin(-angleInRadians1),
				playerDirection.x * std::sin(-angleInRadians1) + playerDirection.y * std::cos(-angleInRadians1)
			);


			// 创建一个新的子弹实例，
			std::shared_ptr<Bullet> newBullet1 = std::make_shared<EnemyBullet1>(
				assetManager.getTexture("Bullet4"),
				playerDirection,  //设置子弹朝向
				200,
				1,
				50
			);
			// 创建一个新的子弹实例，
			std::shared_ptr<Bullet> newBullet2 = std::make_shared<EnemyBullet1>(
				assetManager.getTexture("Bullet4"),
				sideDirection1,  //设置子弹朝向
				200,
				1,
				50
			);
			// 创建一个新的子弹实例，
			std::shared_ptr<Bullet> newBullet3 = std::make_shared<EnemyBullet1>(
				assetManager.getTexture("Bullet4"),
				sideDirection2,  //设置子弹朝向
				200,
				1,
				50
			);
			// 创建一个新的子弹实例，
			std::shared_ptr<Bullet> newBullet4 = std::make_shared<EnemyBullet1>(
				assetManager.getTexture("Bullet4"),
				sideDirection3,  //设置子弹朝向
				200,
				1,
				50
			);
			// 创建一个新的子弹实例，
			std::shared_ptr<Bullet> newBullet5 = std::make_shared<EnemyBullet1>(
				assetManager.getTexture("Bullet4"),
				sideDirection4,  //设置子弹朝向
				200,
				1,
				50
			);
			//设置子弹的位置
			newBullet1->setPosition(this->getPosition());

			// 将子弹添加到EntityManager中
			EntityManager::getInstance()->addBullet(newBullet1);
			//设置子弹的位置
			newBullet2->setPosition(this->getPosition());

			// 将子弹添加到EntityManager中
			EntityManager::getInstance()->addBullet(newBullet2);
			//设置子弹的位置
			newBullet3->setPosition(this->getPosition());

			// 将子弹添加到EntityManager中
			EntityManager::getInstance()->addBullet(newBullet3);
			//设置子弹的位置
			newBullet4->setPosition(this->getPosition());

			// 将子弹添加到EntityManager中
			EntityManager::getInstance()->addBullet(newBullet4);
			//设置子弹的位置
			newBullet5->setPosition(this->getPosition());

			// 将子弹添加到EntityManager中
			EntityManager::getInstance()->addBullet(newBullet5);

		}
		if (isInRedMode2 == true) {
			if (attackTimer >= attackCooldown / 4) {
				attackTimer = 0.f;
				for (int i = -1; i <= 1; ++i) {

					if (i == 0) {
						std::shared_ptr<Bullet> newBullet = std::make_shared<EnemyBullet1>(
							assetManager.getTexture("Bullet4"),
							sf::Vector2f(i, 1),
							100,
							1,
							50
						);
						newBullet->setPosition(this->getPosition());
						EntityManager::getInstance()->addBullet(newBullet);
					}
					else
					{
						std::shared_ptr<Bullet> newBullet = std::make_shared<EnemyBullet1>(
							assetManager.getTexture("Bullet4"),
							sf::Vector2f(i * 0.3, 1),
							90,
							1,
							50
						);
						newBullet->setPosition(this->getPosition());
						EntityManager::getInstance()->addBullet(newBullet);
					}
				}
			}
		}
		else
		{
			attackTimer = 0.f;
		}
	}
	//敌人离开屏幕被销毁

	// 获取敌人位置...
	sf::Vector2f position = sprite.getPosition();
	// 设置额外的边界缓冲区
	float buffer = 80.0f; // 例如，80像素的缓冲区

	// 检查边界

	if (position.x < -buffer || position.x > 660 + buffer ||
		position.y < -buffer || position.y > 960 + buffer) {
		markForDestruction(); // 标记为待销毁
	}

	//血量情况的敌人要死亡并且爆金币
	if (health <= 0) {
		//引用音频播放单例
		AudioManager& audioManager = AudioManager::getInstance();

		markForDestruction();
		//播放死亡音效
		audioManager.playSound("EnemyDead1");
		//玩家加分
		EntityManager::getInstance()->getPlayer()->addScore(1000);
		//爆金币
		// 

		// 分数点的半径
		float r1 = 15.0f; // 第一圈半径
		// 力量点的半径
		float r2 = 30.0f; // 第二圈半径

		// 爆出分数点（4个）
		for (int i = 0; i < 4; ++i) {
			float angle = i * (3.14159265f / 2); // 每90度一个点
			sf::Vector2f offset(std::cos(angle) * r1, std::sin(angle) * r1);
			std::shared_ptr<Bullet> newItem = std::make_shared<ScorePointItem>(
				assetManager.getTexture("ScorePoint"),
				sf::Vector2f(0, 1),
				130,
				10000,
				100
			);
			newItem->setPosition(this->getPosition() + offset);
			EntityManager::getInstance()->addBullet(newItem);
		}

		// 爆出力量点（10个）
		for (int i = 0; i < 10; ++i) {
			float angle = i * (2 * 3.14159265f / 10); // 每36度一个点
			sf::Vector2f offset(std::cos(angle) * r2, std::sin(angle) * r2);
			std::shared_ptr<Bullet> newItem2 = std::make_shared<PowerUpItem>(
				assetManager.getTexture("PowerPoint"),
				sf::Vector2f(0, 1),
				70,
				10000,
				10
			);
			newItem2->setPosition(this->getPosition() + offset);
			EntityManager::getInstance()->addBullet(newItem2);
		}



		// 
		//...
	}
}

void Spider::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}



BigSlime::BigSlime(const sf::Texture& texture, int hp, const sf::Vector2f& dir, float spd)
	:Enemy(texture, hp, dir, spd) {

	//将中心点设置到图片中心点
	sf::Vector2u textureSize = texture.getSize(); // 获取贴图的尺寸
	sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f); // 设置精灵的原点为贴图中心

	//记录最大血量
	MaxHealth = health;

	//射速
	attackCooldown = 1.f;

	//初始化计时器
	attackTimer = 0.f;

	timer = 0.0f;
	attackMode = -1;
	FireMode = -1;
	ModeTimer = 0.0f;
	angleOffset = 0.0f;
}

void BigSlime::moveToPosition(sf::Vector2f targetPosition, float deltaTime) {
	sf::Vector2f currentPosition = sprite.getPosition();
	sf::Vector2f directionToTarget = targetPosition - currentPosition;
	float distanceToTarget = sqrt(pow(directionToTarget.x, 2) + pow(directionToTarget.y, 2));

	if (distanceToTarget > 5.f) { // 假设5像素作为到达的阈值
		directionToTarget /= distanceToTarget; // 单位化向量
		sprite.move(directionToTarget * speed * deltaTime);
	}
}

void BigSlime::update(float deltaTime) {
	//-------------史莱姆BOSS----------------
	/*
		负责人: 波波沙
		功能: 5个阶段的史莱姆BOSS

		返回值: void
		参数: float deltaTime //系统传入的全局时间
	*/

	timer += deltaTime;
	//召唤素材大哥
	AssetManager& assetManager = AssetManager::getInstance();



	//计时改变行为模式
	if (timer < 40.0f && attackMode < 1) {
		ModeTimer = 0.f;
		attackMode = 1;
	}
	else if (timer >= 40.0f && timer < 80.0f && attackMode < 2) {
		ModeTimer = 0.f;
		attackMode = 2;
	}
	else if (timer >= 80.0f && timer < 120.0f && attackMode < 3) {
		ModeTimer = 0.f;
		attackMode = 3;
	}
	else if (timer >= 120.0f && timer < 160.0f && attackMode < 4) {
		ModeTimer = 0.f;
		attackMode = 4;
	}
	else if (timer >= 160.0f && timer < 175.0f && attackMode < 5) {
		ModeTimer = 0.f;
		attackMode = 5;
	}
	else if (timer >= 175.0f) {
		takeDamage(2000000000);
	}

	if (health <= MaxHealth * 0.75f && attackMode < 2) {
		ModeTimer = 0.f;
		attackMode = 2;
	}
	else if (health <= MaxHealth * 0.5f && attackMode < 3) {
		ModeTimer = 0.f;
		attackMode = 3;
	}
	else if (health <= MaxHealth * 0.25f && attackMode < 4) {
		ModeTimer = 0.f;
		attackMode = 4;
	}

	//更新模式计时器
	ModeTimer += deltaTime;
	float cycleDuration = 0.f;
	float cycleProgress = 0.f;



	//移动的逻辑
	if (attackMode == 1) {
		if (ModeTimer < 1.0f) {
			// 移动到指定位置
			speed = 300.f;
			moveToPosition(sf::Vector2f(520.f, 150.f), deltaTime);
			FireMode = -1;
			attackTimer = 0.f;
		}
		else {
			// 循环移动逻辑
			cycleDuration = 6.0f;
			cycleProgress = fmod(ModeTimer - 1.0f, cycleDuration);

			if (cycleProgress < 2.0f) {
				direction = sf::Vector2f(-1, 0); // 向左移动
				speed = 180.f; // 设置速度
				FireMode = 1;
			}
			else if (cycleProgress < 3.0f) {
				direction = sf::Vector2f(0, 0); // 停留
				speed = 0;
				FireMode = 2;
			}
			else if (cycleProgress < 5.0f) {
				direction = sf::Vector2f(1, 0); // 向右移动
				speed = 180.f; // 设置速度
				FireMode = 1;
			}
			else {
				direction = sf::Vector2f(0, 0); // 停留
				speed = 0;
				FireMode = 2;
			}
		}
	}
	if (attackMode == 2) {
		if (ModeTimer < 1.0f) {
			// 移动到指定位置
			speed = 300.f;
			moveToPosition(sf::Vector2f(330.f, 200.f), deltaTime);
			FireMode = -1;
			attackTimer = 0.f;
		}
		else {
			// 循环移动逻辑
			// 循环移动逻辑
			cycleDuration = 8.0f;
			cycleProgress = fmod(ModeTimer - 1.0f, cycleDuration);

			if (cycleProgress < 4.0f) {
				direction = sf::Vector2f(0, 0); // 停留
				speed = 0;
				FireMode = 3;
			}
			else {
				direction = sf::Vector2f(0, 0); // 停留
				speed = 0;
				FireMode = 2;
			}
		}
	}
	if (attackMode == 3) {
		if (ModeTimer < 1.0f) {
			// 移动到指定位置
			speed = 300.f;
			moveToPosition(sf::Vector2f(330.f, 100.f), deltaTime);
			FireMode = -1;
			attackTimer = 0.f;
		}
		else {
			// 循环移动逻辑
			// 循环移动逻辑
			cycleDuration = 9.0f;
			cycleProgress = fmod(ModeTimer - 1.0f, cycleDuration);

			if (cycleProgress < 2.0f) {
				direction = sf::Vector2f(0, 0); // 停留
				speed = 0;
				FireMode = 1;
			}
			else if (cycleProgress < 3.0f) {
				direction = sf::Vector2f(0, 1); // 向下移动
				speed = 300;
				FireMode = 3;
			}
			else if (cycleProgress < 8.0f) {
				direction = sf::Vector2f(0, 0); // 停留
				speed = 0;
				FireMode = 4;
			}
			else
			{
				direction = sf::Vector2f(0, -1); // 向上移动
				speed = 300;
				FireMode = 3;
			}
		}
	}
	if (attackMode == 4) {
		if (ModeTimer < 1.0f) {
			// 移动到指定位置
			speed = 500.f;
			moveToPosition(sf::Vector2f(330.f, 100.f), deltaTime);
			FireMode = -1;
			attackTimer = 0.f;
		}
		else
		{
			direction = sf::Vector2f(0, 0); // 停留
			speed = 0;
			FireMode = 5;
		}
	}
	if (attackMode == 5) {
		if (ModeTimer < 2.0f) {
			// 移动到指定位置
			speed = 300.f;
			moveToPosition(sf::Vector2f(330.f, 330.f), deltaTime);
			FireMode = -1;
			attackTimer = 0.f;
		}
		else
		{
			direction = sf::Vector2f(0, 0); // 停留
			speed = 0;
			FireMode = 6;
		}
	}



	//测试
	std::cout << "ModeTimer: " << ModeTimer << " cycleProgress: " << cycleProgress << std::endl;

	// 计算新位置
	sf::Vector2f movement = direction * speed * deltaTime;
	// 更新精灵的位置
	sprite.move(movement);

	attackTimer += deltaTime;



	//选择开火方式1 
	if (FireMode == 1)
	{
		if (attackTimer >= 0.1f) {
			attackTimer -= 0.1f;
			//发射逻辑
			//获得玩家的位置
			sf::Vector2f playerDirection = getDirectionTowardsPlayer();
			// Calculate the direction of the side bullets (rotate by +/- 45 degrees)
			float angleInRadians = 20.0f * (3.14159265359f / 180.0f);
			sf::Vector2f sideDirection1(
				playerDirection.x * std::cos(angleInRadians) - playerDirection.y * std::sin(angleInRadians),
				playerDirection.x * std::sin(angleInRadians) + playerDirection.y * std::cos(angleInRadians)
			);
			sf::Vector2f sideDirection2(
				playerDirection.x * std::cos(-angleInRadians) - playerDirection.y * std::sin(-angleInRadians),
				playerDirection.x * std::sin(-angleInRadians) + playerDirection.y * std::cos(-angleInRadians)
			);

			float angleInRadians1 = 10.0f * (3.14159265359f / 180.0f);
			sf::Vector2f sideDirection3(
				playerDirection.x * std::cos(angleInRadians1) - playerDirection.y * std::sin(angleInRadians1),
				playerDirection.x * std::sin(angleInRadians1) + playerDirection.y * std::cos(angleInRadians1)
			);
			sf::Vector2f sideDirection4(
				playerDirection.x * std::cos(-angleInRadians1) - playerDirection.y * std::sin(-angleInRadians1),
				playerDirection.x * std::sin(-angleInRadians1) + playerDirection.y * std::cos(-angleInRadians1)
			);


			// 创建一个新的子弹实例，
			std::shared_ptr<Bullet> newBullet1 = std::make_shared<EnemyBullet1>(
				assetManager.getTexture("Bullet9"),
				playerDirection,  //设置子弹朝向
				200,
				1,
				70
			);
			// 创建一个新的子弹实例，
			std::shared_ptr<Bullet> newBullet2 = std::make_shared<EnemyBullet1>(
				assetManager.getTexture("Bullet9"),
				sideDirection1,  //设置子弹朝向
				200,
				1,
				70
			);
			// 创建一个新的子弹实例，
			std::shared_ptr<Bullet> newBullet3 = std::make_shared<EnemyBullet1>(
				assetManager.getTexture("Bullet9"),
				sideDirection2,  //设置子弹朝向
				200,
				1,
				70
			);
			// 创建一个新的子弹实例，
			std::shared_ptr<Bullet> newBullet4 = std::make_shared<EnemyBullet1>(
				assetManager.getTexture("Bullet9"),
				sideDirection3,  //设置子弹朝向
				200,
				1,
				70
			);
			// 创建一个新的子弹实例，
			std::shared_ptr<Bullet> newBullet5 = std::make_shared<EnemyBullet1>(
				assetManager.getTexture("Bullet9"),
				sideDirection4,  //设置子弹朝向
				200,
				1,
				70
			);
			//设置子弹的位置
			newBullet1->setPosition(this->getPosition());

			// 将子弹添加到EntityManager中
			EntityManager::getInstance()->addBullet(newBullet1);
			//设置子弹的位置
			newBullet2->setPosition(this->getPosition());

			// 将子弹添加到EntityManager中
			EntityManager::getInstance()->addBullet(newBullet2);
			//设置子弹的位置
			newBullet3->setPosition(this->getPosition());

			// 将子弹添加到EntityManager中
			EntityManager::getInstance()->addBullet(newBullet3);
			//设置子弹的位置
			newBullet4->setPosition(this->getPosition());

			// 将子弹添加到EntityManager中
			EntityManager::getInstance()->addBullet(newBullet4);
			//设置子弹的位置
			newBullet5->setPosition(this->getPosition());

			// 将子弹添加到EntityManager中
			EntityManager::getInstance()->addBullet(newBullet5);
		}
	}
	//选择开火方式2
	else if (FireMode == 2)
	{
		if (attackTimer >= 0.5f) {
			attackTimer -= 0.5f;
			//发射逻辑
			//获得玩家的位置
			sf::Vector2f playerDirection = getDirectionTowardsPlayer();
			// 创建一个新的子弹实例，
			std::shared_ptr<Bullet> newBullet = std::make_shared<EnemyBullet1>(
				assetManager.getTexture("Bullet6"),
				playerDirection,
				700,
				1,
				300
			);
			//设置子弹的位置
			newBullet->setPosition(this->getPosition());

			// 将子弹添加到EntityManager中
			EntityManager::getInstance()->addBullet(newBullet);
		}
	}
	//开火方式3
	if (FireMode == 3) // 假设3代表新的攻击模式
	{
		if (attackTimer >= 0.2f) { // 设定攻击的间隔时间
			attackTimer -= 0.2f;

			for (int i = 0; i < 10; ++i) { // 生成10颗子弹
				// 随机方向（向下且在145度范围内居中）
				float angleOffset = -72.5f + static_cast<float>(rand() % 145); // 在-72.5度到+72.5度之间随机
				float angle = 90.f + angleOffset; // 总的角度
				float radian = angle * (3.14159265359f / 180.0f); // 角度转弧度

				sf::Vector2f direction(
					std::cos(radian),
					std::sin(radian)
				);

				// 随机速度（50到250之间）
				float speed = 50.f + static_cast<float>(rand() % 200);

				// 创建一个新的子弹实例
				std::shared_ptr<Bullet> newBullet = std::make_shared<EnemyBullet1>(
					assetManager.getTexture("Bullet7"), // 子弹纹理
					direction, // 设置子弹方向
					speed, // 随机速度
					1, // 其他参数
					100 // 其他参数
				);

				// 设置子弹的位置
				newBullet->setPosition(this->getPosition());

				// 将子弹添加到EntityManager中
				EntityManager::getInstance()->addBullet(newBullet);
			}
		}
	}
	//开火方式4
	else if (FireMode == 4)
	{
		if (attackTimer >= 0.3f) { // 设定攻击的间隔时间
			attackTimer -= 0.3f;

			for (int i = 0; i < 36; ++i) { // 生成30颗子弹
				// 计算每颗子弹的方向（均匀分布在360度）
				float angle = (360.f / 36) * i; // 每颗子弹的角度
				float radian = angle * (3.14159265359f / 180.0f); // 角度转弧度

				sf::Vector2f direction(
					std::cos(radian),
					std::sin(radian)
				);

				// 设置子弹速度
				float speed = 200.f; // 可以根据需要调整速度

				// 创建一个新的子弹实例
				std::shared_ptr<Bullet> newBullet = std::make_shared<EnemyBullet1>(
					assetManager.getTexture("Bullet6"), // 子弹纹理
					direction, // 设置子弹方向
					speed, // 固定速度
					1, // 其他参数
					150 // 其他参数
				);

				// 设置子弹的位置
				newBullet->setPosition(this->getPosition());

				// 将子弹添加到EntityManager中
				EntityManager::getInstance()->addBullet(newBullet);
			}
		}
	}
	//开火方式5
	else if (FireMode == 5) {
		if (attackTimer >= 0.4f) { // 攻击间隔
			attackTimer -= 0.4f;

			// 发射点的位置设置
			sf::Vector2f leftPosition = this->getPosition() + sf::Vector2f(-30, 0); // BOSS左侧
			sf::Vector2f rightPosition = this->getPosition() + sf::Vector2f(30, 0); // BOSS右侧

			for (int i = 0; i < 36; ++i) {
				// 计算每颗子弹的方向（加上偏移角度）
				float angle = (360.f / 36) * i + angleOffset;
				float radian = angle * (3.14159265359f / 180.0f);

				sf::Vector2f direction(std::cos(radian), std::sin(radian));

				// 从左侧发射
				std::shared_ptr<Bullet> newBulletLeft = std::make_shared<EnemyBullet1>(
					assetManager.getTexture("Bullet1"),
					direction,
					160, // 速度
					1,
					100
				);
				newBulletLeft->setPosition(leftPosition);
				EntityManager::getInstance()->addBullet(newBulletLeft);

				// 从右侧发射
				std::shared_ptr<Bullet> newBulletRight = std::make_shared<EnemyBullet1>(
					assetManager.getTexture("Bullet10"),
					direction,
					160, // 速度
					1,
					100
				);
				newBulletRight->setPosition(rightPosition);
				EntityManager::getInstance()->addBullet(newBulletRight);
			}

			// 增加角度偏移，以改变下一次攻击的模式
			angleOffset += 3.0f; // 每次攻击增加1度
		}
	}
	//最终阶段6
	else if (FireMode == 6) {
		if (attackTimer >= 0.2f) { // 攻击间隔
			attackTimer -= 0.2f;

			// 发射点的位置设置
			sf::Vector2f leftPosition = this->getPosition() + sf::Vector2f(-30, 0); // BOSS左侧
			sf::Vector2f rightPosition = this->getPosition() + sf::Vector2f(30, 0); // BOSS右侧

			for (int i = 0; i < 36; ++i) {
				// 计算每颗子弹的方向（加上偏移角度）
				float angle = (360.f / 36) * i + angleOffset;
				float radian = angle * (3.14159265359f / 180.0f);

				sf::Vector2f direction(std::cos(radian), std::sin(radian));

				// 从左侧发射
				std::shared_ptr<Bullet> newBulletLeft = std::make_shared<EnemyBullet1>(
					assetManager.getTexture("Bullet1"),
					direction,
					100, // 速度
					1,
					100
				);
				newBulletLeft->setPosition(leftPosition);
				EntityManager::getInstance()->addBullet(newBulletLeft);

				// 从右侧发射
				std::shared_ptr<Bullet> newBulletRight = std::make_shared<EnemyBullet1>(
					assetManager.getTexture("Bullet10"),
					direction,
					100, // 速度
					1,
					100
				);
				newBulletRight->setPosition(rightPosition);
				EntityManager::getInstance()->addBullet(newBulletRight);
			}

			// 增加角度偏移，以改变下一次攻击的模式
			angleOffset += 3.0f; // 每次攻击增加1度
		}
	}
	//...



	//血量情况的敌人要死亡并且爆金币
	if (health <= 0) {
		//引用音频播放单例
		AudioManager& audioManager = AudioManager::getInstance();
		
		EntityManager* entityManager = EntityManager::getInstance();

		markForDestruction();
		//播放死亡音效
		audioManager.playSound("Explode1");
		audioManager.playSound("Explode2");

		//发射技能子弹
		 // 发射一圈特殊子弹
		for (int i = 0; i < 16; ++i) {
			// 计算每个子弹的发射角度
			float angle = (360.f / 16) * i; // 将360度等分为16份，每个子弹的角度
			float radian = angle * (3.14159265359f / 180.0f); // 将角度转换为弧度
			// 计算子弹的方向
			sf::Vector2f direction(std::cos(radian), std::sin(radian));

			// 创建特殊子弹实例
			std::shared_ptr<Bullet> specialBullet = std::make_shared<PlayerMagicBullet>(
				assetManager.getTexture("SkillButton"),
				direction,  // 使用计算出的方向
				1500,
				10000,
				500
			);
			// 设置子弹的位置
			specialBullet->setPosition(sprite.getPosition());

			// 将子弹添加到EntityManager中
			entityManager->getInstance()->addBullet(specialBullet);
		}

		//玩家加分
		EntityManager::getInstance()->getPlayer()->addScore(5000);
		//玩家获胜
		EntityManager::getInstance()->getPlayer()->victory();
		//爆金币
		//...

		// 第一圈 - 6个点数
		for (int i = 0; i < 6; ++i) {
			float angle = (360.f / 6) * i;
			float radian = angle * (3.14159265359f / 180.0f);
			sf::Vector2f offset(std::cos(radian) * 15.0f, std::sin(radian) * 15.0f);

			std::shared_ptr<Bullet> newItem = std::make_shared<ScorePointItem>(
				assetManager.getTexture("ScorePoint"),
				sf::Vector2f(0, 1),
				130,
				10000,
				100
			);
			newItem->setPosition(this->getPosition() + offset);
			EntityManager::getInstance()->addBullet(newItem);
		}

		// 第二圈 - 12个点数
		for (int i = 0; i < 12; ++i) {
			float angle = (360.f / 12) * i;
			float radian = angle * (3.14159265359f / 180.0f);
			sf::Vector2f offset(std::cos(radian) * 30.0f, std::sin(radian) * 30.0f);

			std::shared_ptr<Bullet> newItem = std::make_shared<ScorePointItem>(
				assetManager.getTexture("ScorePoint"),
				sf::Vector2f(0, 1),
				130,
				10000,
				100
			);
			newItem->setPosition(this->getPosition() + offset);
			EntityManager::getInstance()->addBullet(newItem);
		}

		// 第三圈 - 20个力量点
		for (int i = 0; i < 20; ++i) {
			float angle = (360.f / 20) * i;
			float radian = angle * (3.14159265359f / 180.0f);
			sf::Vector2f offset(std::cos(radian) * 45.0f, std::sin(radian) * 45.0f);

			std::shared_ptr<Bullet> newItem = std::make_shared<PowerUpItem>(
				assetManager.getTexture("PowerPoint"),
				sf::Vector2f(0, 1),
				70,
				10000,
				10
			);
			newItem->setPosition(this->getPosition() + offset);
			EntityManager::getInstance()->addBullet(newItem);


		}
	}
}

void BigSlime::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

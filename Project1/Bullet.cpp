#include "Bullet.hpp"
#include "EntityManager.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

void Bullet::setPosition(const sf::Vector2f& position) {
	// 设置子弹的位置
	/*
	负责人: 波波沙

	功能:
		输入一个位置，将子弹移动过来

	参数:
		const sf::Vector2f& position    //一个位置坐标

	返回值: void
	*/
	//----------------------实现------------------------//
	sprite.setPosition(position);
}

void Bullet::setAngle() {
	// 设置子弹图片的角度
	/*
	负责人: 管兴成

	功能:
		根据当前子弹的移动方向direction来改变图片指向，使得不是全向对称的子弹可以清晰的判断移动方向
		（让子弹指向它自己的移动方向）

	参数:
		const sf::Vector2f& position    //一个位置坐标

	返回值: void
	*/
	//----------------------实现------------------------//
// 计算子弹应该指向的角度
// 计算子弹应该指向的角度
	float angle = std::atan2(direction.x, -direction.y);
	// 将弧度转换为角度
	angle = angle * 180.0 / 3.14159;
	// 设置子弹的旋转角度
	sprite.setRotation(angle);
}

sf::Sprite& Bullet::getSprite() {
	//返回子弹的精灵
	/*
	负责人: 波波沙

	功能:
		返回子弹的精灵的引用

	参数:
		void

	返回值: sf::Sprite&
	*/
	//----------------------实现------------------------//

	return sprite;
}

void Bullet::atkHealth(int atk) {
	//减少子弹的生命值
	/*
	负责人: 波波沙

	功能:
		让子弹扣血

	参数:
		atk		//子弹受到的伤害

	返回值: void
	*/
	//----------------------实现------------------------//

	health -= atk;
}

void EnemyBullet1::update(float deltaTime) {
	// 更新子弹的位置（未完成）
	/*
	负责人: 波波沙

	功能:
		更新子弹的位置，并且实现碰撞判定

	参数:
		float deltaTime //全局统一间隔时间

	返回值: void
	*/
	//----------------------实现------------------------//

	//移动子弹
	sprite.move(direction * speed * deltaTime);

	//碰撞判定
	// 获取子弹的边界框
	sf::FloatRect bulletBounds = sprite.getGlobalBounds();

	// 获取玩家对象和边界框
	auto player = EntityManager::getInstance()->getPlayer();
	if (player) {
		//取得判定点
		sf::FloatRect playerBounds = player->getHitBox().getGlobalBounds();
		sf::FloatRect JumkoBouns = player->getSprite().getGlobalBounds();

		// 检测和玩家的碰撞
		if (bulletBounds.intersects(playerBounds)) {
			//引用音频播放单例
			AudioManager& audioManager = AudioManager::getInstance();
			// 碰撞发生，对玩家造成伤害
			player->takeDamage(this->atk); // 假设玩家类有一个 takeDamage 方法
			//播放击中玩家的音效
			audioManager.playSound("HitPlayer");

			// 标记子弹为待销毁
			this->health -= 1;
		}

		if (bulletBounds.intersects(JumkoBouns)) {
			if (!isHitPlayer) {
				isHitPlayer = true;
				//引用音频播放单例
				AudioManager& audioManager = AudioManager::getInstance();
				//擦弹加分
				player->addScore(5);
				//播放擦弹音效
				audioManager.playSound("Summary");
			}

		}
	}
	//....

	//子弹离开屏幕被销毁
	// 获取子弹位置...
	sf::Vector2f position = sprite.getPosition();
	// 设置额外的边界缓冲区
	float buffer = 30.0f; // 例如，50像素的缓冲区
	// 检查边界
	if (position.x < -buffer || position.x > 660 + buffer ||
		position.y < -buffer || position.y > 960 + buffer) {
		markForDestruction(); // 标记为待销毁
	}

	//命中过的子弹要被销毁
	if (health <= 0) {
		markForDestruction();
	}
}

void EnemyBullet1::draw(sf::RenderWindow& window) {
	//渲染子弹
	/*
	负责人: 波波沙

	功能:
		显示子弹

	参数:
		sf::RenderWindow& window    //要渲染的地方

	返回值: void
	*/
	//----------------------实现------------------------//

	//渲染
	window.draw(sprite);
}

void PlayerBullet1::update(float deltaTime) {
	// 更新子弹的位置（未完成）
	/*
	负责人: 波波沙

	功能:
		更新子弹的位置，并且实现碰撞判定

	参数:
		float deltaTime //全局统一间隔时间

	返回值: void
	*/
	//----------------------实现------------------------//

	//更新子弹位置
	sprite.move(direction * speed * deltaTime);

	//和所有敌人进行碰撞判定 O(mn)
	// 获取子弹的边界框
	sf::FloatRect bulletBounds = sprite.getGlobalBounds();

	// 检测和敌人的碰撞
	for (auto& enemyPtr : EntityManager::getInstance()->getEnemies()) {
		if (enemyPtr && bulletBounds.intersects(enemyPtr->getSprite().getGlobalBounds())) {
			// 碰撞发生，处理逻辑
			//引用音频播放单例
			AudioManager& audioManager = AudioManager::getInstance();
			//子弹血量减一
			this->health -= 1;
			//敌人受到伤害
			enemyPtr->takeDamage(this->atk);
			//播放击中音效
			audioManager.playSound("HitEnemy1");

			//击中敌人加分
			EntityManager::getInstance()->getPlayer()->addScore(1);
		}
	}


	//子弹离开屏幕被销毁
	// 获取子弹位置...
	sf::Vector2f position = sprite.getPosition();
	// 设置额外的边界缓冲区
	float buffer = 30.0f; // 例如，50像素的缓冲区
	// 检查边界
	if (position.x < -buffer || position.x > 660 + buffer ||
		position.y < -buffer || position.y > 960 + buffer) {
		markForDestruction(); // 标记为待销毁
	}

	//命中过的子弹要被销毁
	if (health <= 0) {
		markForDestruction();
	}
}

void PlayerBullet1::draw(sf::RenderWindow& window) {
	//渲染子弹
	/*
	负责人: 波波沙

	功能:
		显示子弹

	参数:
		sf::RenderWindow& window    //要渲染的地方

	返回值: void
	*/
	//----------------------实现------------------------//

	//渲染
	window.draw(sprite);
}

void PlayerMagicBullet::update(float deltaTime)
{
	sprite.move(direction * speed * deltaTime);

	//碰撞判定
	// 获取子弹的边界框
	sf::FloatRect bulletBounds = sprite.getGlobalBounds();

	// 检测和子弹的碰撞
	for (auto& bulletPtr : EntityManager::getInstance()->getBullets()) {
		if (bulletPtr && bulletBounds.intersects(bulletPtr->getSprite().getGlobalBounds())) {
			// 碰撞发生，处理逻辑
			
			//子弹销毁
			if(bulletPtr)
			bulletPtr->atkHealth(1);
		}
	}
	// 检测和敌人的碰撞
	for (auto& enemyPtr : EntityManager::getInstance()->getEnemies()) {
		if (enemyPtr && bulletBounds.intersects(enemyPtr->getSprite().getGlobalBounds())) {
			// 碰撞发生，处理逻辑
			//引用音频播放单例
			AudioManager& audioManager = AudioManager::getInstance();
			//敌人受到伤害
			enemyPtr->takeDamage(150);
			//播放击中音效
			audioManager.playSound("HitEnemy1");

		}
	}

	//子弹离开屏幕被销毁
	// 获取子弹位置...
	sf::Vector2f position = sprite.getPosition();
	// 设置额外的边界缓冲区
	float buffer = 30.0f; // 例如，50像素的缓冲区
	// 检查边界
	if (position.x < -buffer || position.x > 660 + buffer ||
		position.y < -buffer || position.y > 960 + buffer) {
		markForDestruction(); // 标记为待销毁
	}
}

void PlayerMagicBullet::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void PowerUpItem::update(float deltaTime) {
	// 更新子弹的位置（未完成）
	/*
	负责人: 朱

	功能:
		更新力量道具的位置，并且实现碰撞判定

	参数:
		float deltaTime //全局统一间隔时间

	返回值: void
	*/
	//----------------------实现------------------------//

	//移动道具
	if (!isBeingAbsorbed) {
		sprite.move(direction * speed * deltaTime);
		totalTime = 0.0f;  // 重置 totalTime
	}

	//碰撞判定
	// 获取道具的边界框
	sf::FloatRect bulletBounds = sprite.getGlobalBounds();

	// 获取玩家对象和边界框
	auto player = EntityManager::getInstance()->getPlayer();
	if (player) {
		//取得玩家的判定框(非判定点)
		sf::FloatRect JumkoBouns = player->getSprite().getGlobalBounds();

		if (isWithinDistance(JumkoBouns.getPosition())) {

			totalTime += deltaTime;

			float progress = std::min(totalTime / 3.0f, 1.0f);

			adsorbToPlayer(JumkoBouns.getPosition(), progress);

		}

		// 检测和玩家的碰撞
		if (bulletBounds.intersects(JumkoBouns)) {
			//引用音频播放单例
			AudioManager& audioManager = AudioManager::getInstance();

			//播放玩家得到道具的音效
			audioManager.playSound("Summary");

			// 碰撞发生，给玩家加上对应分数
			player->addPower(atk);

			// 标记道具为待销毁
			this->health -= 10000;
		}

	}

	//道具离开屏幕被销毁
	// 获取道具位置...
	sf::Vector2f position = sprite.getPosition();
	// 设置额外的边界缓冲区
	float buffer = 30.0f; // 例如，50像素的缓冲区
	// 检查边界
	if (position.x < -buffer || position.x > 660 + buffer ||
		position.y < -buffer || position.y > 960 + buffer) {
		Entity::markForDestruction(); // 标记为待销毁
	}

	//拾取后的要被销毁
	if (health <= 0) {
		Entity::markForDestruction();
	}
}

void PowerUpItem::draw(sf::RenderWindow& window) {
	//渲染子弹
	/*
	负责人: 朱

	功能:
		显示力量道具

	参数:
		sf::RenderWindow& window    //要渲染的地方

	返回值: void
	*/
	//----------------------实现------------------------//
	window.draw(sprite);
}

void ScorePointItem::update(float deltaTime) {
	// 更新子弹的位置（未完成）
	/*
	负责人: 朱

	功能:
		更新得分道具的位置，并且实现碰撞判定

	参数:
		float deltaTime //全局统一间隔时间

	返回值: void
	*/

	//----------------------实现------------------------//

	//移动道具
	if (!isBeingAbsorbed) {
		sprite.move(direction * speed * deltaTime);
		totalTime = 0.0f;  // 重置 totalTime
	}

	//碰撞判定
	// 获取道具的边界框
	sf::FloatRect bulletBounds = sprite.getGlobalBounds();

	// 获取玩家对象和边界框
	auto player = EntityManager::getInstance()->getPlayer();
	if (player) {
		//取得玩家的判定框(非判定点)
		sf::FloatRect JumkoBouns = player->getSprite().getGlobalBounds();

		if (isWithinDistance(JumkoBouns.getPosition())) {

			totalTime += deltaTime;

			float progress = std::min(totalTime / 3.0f, 1.0f);

			adsorbToPlayer(JumkoBouns.getPosition(), progress);

		}

		// 检测和玩家的碰撞
		if (bulletBounds.intersects(JumkoBouns)) {
			//引用音频播放单例
			AudioManager& audioManager = AudioManager::getInstance();

			//播放玩家得到道具的音效
			audioManager.playSound("Summary");

			// 碰撞发生，给玩家加上对应分数
			player->addScore(this->atk);

			// 标记道具为待销毁
			this->health -= 10000;
		}

	}

	//道具离开屏幕被销毁
	// 获取道具位置...
	sf::Vector2f position = sprite.getPosition();
	// 设置额外的边界缓冲区
	float buffer = 30.0f; // 例如，50像素的缓冲区
	// 检查边界
	if (position.x < -buffer || position.x > 660 + buffer ||
		position.y < -buffer || position.y > 960 + buffer) {
		Entity::markForDestruction(); // 标记为待销毁
	}

	//拾取后的要被销毁
	if (health <= 0) {
		Entity::markForDestruction();
	}
}

void ScorePointItem::draw(sf::RenderWindow& window) {
	//渲染子弹
	/*
	负责人: 朱

	功能:
		显示得分道具

	参数:
		sf::RenderWindow& window    //要渲染的地方

	返回值: void
	*/
	//----------------------实现------------------------//
	window.draw(sprite);
}
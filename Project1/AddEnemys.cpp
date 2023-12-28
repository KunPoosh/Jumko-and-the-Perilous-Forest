#include "StateMainGame.hpp"
#include <iostream>
#include "Animation.hpp"

void StateMainGame::ADDENEMYS()
{

	//-------------------------添加敌人----------------------------//
	//														      //
	//  负责人： 全体组员											  //
	//															  //
	//  功能： 在游戏进行到固定的时间时创建固定的敌人。				  //
	//															  //
	//--------------------------实现------------------------------//


	/*
	//2s框架开始
	switch (ENEMYOUT2S)
	{
	case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
		//释放敌人
		break;
	case 1: if (ENEMYOUT2STIME >= 0.2f) {
		ENEMYOUT2S++;
		//释放敌人
	} break;
	case 2: if (ENEMYOUT2STIME >= 0.4f) {
		ENEMYOUT2S++;
		//释放敌人
	} break;
	case 3: if (ENEMYOUT2STIME >= 0.6f) {
		ENEMYOUT2S++;
		//释放敌人
	} break;
	case 4: if (ENEMYOUT2STIME >= 0.8f) {
		ENEMYOUT2S++;
		//释放敌人
	} break;
	case 5: if (ENEMYOUT2STIME >= 1.0f) {
		ENEMYOUT2S++;
		//释放敌人
	} break;
	case 6: if (ENEMYOUT2STIME >= 1.2f) {
		ENEMYOUT2S++;
		//释放敌人
	} break;
	case 7: if (ENEMYOUT2STIME >= 1.4f) {
		ENEMYOUT2S++;
		//释放敌人
	} break;
	case 8: if (ENEMYOUT2STIME >= 1.6f) {
		ENEMYOUT2S++;
		//释放敌人
	} break;
	case 9: if (ENEMYOUT2STIME >= 1.8f) {
		ENEMYOUT2S = 0; TIMEFORPLAY++;
		//释放敌人
	} break;
	default:
		break;
	}
	//2s框架结束
	*/


	/*
	//普通层框架
	case 1:
		if (TOTALTIME > 3.0f) {
			TIMEFORPLAY++;
		}
		break;
	//普通层框架
	*/


	//素材管理器
	AssetManager& assetManager = AssetManager::getInstance();
	//音频管理器
	AudioManager& audioManager = AudioManager::getInstance();

	switch (TIMEFORPLAY)
	{
		// 一个case最多只能使用一个两秒框架，也就是超过2秒的处理要分到多个case里面去写，case的数值统合时再调整，不用特别在意，
		// 使用两秒模板时记得不要手动加TIMEFORPLAY++，模板里面已经包含了。
		/*
		* 敌人输入类型：(按顺序)
			1.敌人类型：（自己选择合适的）
				Enemy1 //单发垂直射击
				Enemy2 //单发自机狙射击
				Enemy3 //三发垂直射击
				Enemy4 //五发垂直射击
				Enemy5 //三发自机狙射击
				Enemy6 //五发自机狙射击
			2.贴图，按照要求使用
			3.出现位置，记得要生成在屏幕外面，按照要求位置生成
			4.移动方向，！！！一定要换算成单位向量！单位向量！单位向量！单位向量！单位向量！单位向量！单位向量！单位向量！单位向量！单位向量！
			5.血量，自己设计
			6.速度，自己设计
		*/


	case 0:
		if (TOTALTIME > 0.0f) {
			TIMEFORPLAY++;
			//播放BGM，游戏开始
			audioManager.playMusic("Stage1", false);

			//播放入场音效
			audioManager.playSound("Jumko_Begin");

			//测试区
			//EnemyFactory::createEnemy("Spider", assetManager.getTexture("Spider"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 160000, 100);
			
			//EnemyFactory::createEnemy("SilmeBoss", assetManager.getTexture("SlimeBoss"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 2400000, 100);
		
			//stateManager.changeState(stateManager.createState("StateVictory"));
			//audioManager.stopMusic();
		}
		break;

	case 1:
		if (TOTALTIME > 4.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("SlimePink"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(160, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 2:
		if (TOTALTIME > 6.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeGreen"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 2000, 100);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(480, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeGreen"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 2000, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 3:
		if (TOTALTIME > 8.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("SlimePink"), sf::Vector2f(160, -30), sf::Vector2f(0, 1), 3000, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeGreen"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 2000, 100);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(480, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 4:
		if (TOTALTIME > 10.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeGreen"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 2000, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(160, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 5:
		if (TOTALTIME > 12.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("SlimePink"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 3000, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0.105, 0.994), 600, 150);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeGreen"), sf::Vector2f(160, -30), sf::Vector2f(0.209, 0.978), 2000, 100);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0.105, 0.994), 600, 150);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 6:
		if (TOTALTIME > 14.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(-0.106, 0.994), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeGreen"), sf::Vector2f(480, -30), sf::Vector2f(-0.209, 0.978), 2000, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(-0.106, 0.994), 600, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 2000, 100);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0.106, 0.994), 600, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 7:
		if (TOTALTIME > 16.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("SlimePink"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 3000, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0.105, 0.994), 600, 150);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeGreen"), sf::Vector2f(160, -30), sf::Vector2f(0.209, 0.978), 2000, 100);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0.105, 0.994), 600, 150);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 8:
		if (TOTALTIME > 18.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("SlimePink"), sf::Vector2f(160, -30), sf::Vector2f(0, 1), 3500, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("SlimePink"), sf::Vector2f(480, -30), sf::Vector2f(0, 1), 3500, 100);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 9:
		if (TOTALTIME > 20.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("SlimePink"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 3500, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 10:
		if (TOTALTIME > 22.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeGreen"), sf::Vector2f(60, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(120, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);

				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeGreen"), sf::Vector2f(60, -80), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(120, -80), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(180, -80), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -80), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(460, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(520, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(580, -30), sf::Vector2f(0, 1), 600, 150);

				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -80), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(460, -80), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(520, -80), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(580, -80), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 11:
		if (TOTALTIME > 24.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 12:
		if (TOTALTIME > 26.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(230, -30), sf::Vector2f(0, 1), 1000, 150);
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineBlue"), sf::Vector2f(290, -30), sf::Vector2f(0, 1), 1000, 150);
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineBlue"), sf::Vector2f(350, -30), sf::Vector2f(0, 1), 1000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(410, -30), sf::Vector2f(0, 1), 1000, 150);

				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(230, -80), sf::Vector2f(0, 1), 1000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineOrange"), sf::Vector2f(290, -80), sf::Vector2f(0, 1), 1000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineOrange"), sf::Vector2f(350, -80), sf::Vector2f(0, 1), 1000, 150);
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(410, -80), sf::Vector2f(0, 1), 1000, 150);

			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 13:
		if (TOTALTIME > 28.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1500, 150);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1500, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(710, 280), sf::Vector2f(-0.849, 0.527), 1000, 150);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(710, 280), sf::Vector2f(-0.849, 0.527), 1000, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 14:
		if (TOTALTIME > 30.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(230, -30), sf::Vector2f(0, 1), 1000, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("GoblineBlue"), sf::Vector2f(290, -30), sf::Vector2f(0, 1), 1000, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("GoblineBlue"), sf::Vector2f(350, -30), sf::Vector2f(0, 1), 1000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(410, -30), sf::Vector2f(0, 1), 1000, 150);

				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("GoblineOrange"), sf::Vector2f(230, -80), sf::Vector2f(0, 1), 1000, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("GoblineOrange"), sf::Vector2f(290, -80), sf::Vector2f(0, 1), 1000, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("GoblineOrange"), sf::Vector2f(350, -80), sf::Vector2f(0, 1), 1000, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("GoblineOrange"), sf::Vector2f(410, -80), sf::Vector2f(0, 1), 1000, 150);

				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 15:
		if (TOTALTIME > 32.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(290, -80), sf::Vector2f(0, 1), 1500, 125);
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(350, -30), sf::Vector2f(0, 1), 1500, 125);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 16:
		if (TOTALTIME > 34.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 17:
		if (TOTALTIME > 36.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(290, -30), sf::Vector2f(0, 1), 1500, 125);
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(350, -30), sf::Vector2f(0, 1), 1500, 125);
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 18:
		if (TOTALTIME > 38.6f) {
			TIMEFORPLAY++;
		}
		break;

	case 19:
		if (TOTALTIME > 40.6f) {
			TIMEFORPLAY++;
		}
		break;

	case 20:
		if (TOTALTIME > 42.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 2500, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 2500, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 21:
		if (TOTALTIME > 44.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 2500, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 2500, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 22:
		if (TOTALTIME > 46.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 2500, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 2500, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 23:
		if (TOTALTIME > 48.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 2500, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 2500, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(-0.106, 0.994), 600, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(-0.106, 0.994), 600, 150);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(-0.106, 0.994), 600, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 24:
		if (TOTALTIME > 50.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 2500, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 2500, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeGreen"), sf::Vector2f(60, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(120, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);

				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeGreen"), sf::Vector2f(60, -80), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(120, -80), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(180, -80), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -80), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(460, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(520, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(580, -30), sf::Vector2f(0, 1), 600, 150);

				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -80), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(460, -80), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(520, -80), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(580, -80), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 25:
		if (TOTALTIME > 52.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineOrange"), sf::Vector2f(710, 280), sf::Vector2f(-0.849, 0.527), 1000, 100);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 1000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 1000, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 280), sf::Vector2f(0.813, 0.584), 1000, 100);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(290, -30), sf::Vector2f(0, 1), 1500, 100);
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineOrange"), sf::Vector2f(350, -30), sf::Vector2f(0, 1), 1500, 100);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 280), sf::Vector2f(0.813, 0.584), 1000, 100);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 26:
		if (TOTALTIME > 54.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineOrange"), sf::Vector2f(710, 280), sf::Vector2f(-0.849, 0.527), 1000, 100);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 2500, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 2500, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(230, -30), sf::Vector2f(0, 1), 600, 100);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("GoblineBlue"), sf::Vector2f(290, -30), sf::Vector2f(0, 1), 600, 100);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("GoblineBlue"), sf::Vector2f(350, -30), sf::Vector2f(0, 1), 600, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(410, -30), sf::Vector2f(0, 1), 600, 100);

				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("GoblineOrange"), sf::Vector2f(230, -80), sf::Vector2f(0, 1), 600, 100);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("GoblineOrange"), sf::Vector2f(290, -80), sf::Vector2f(0, 1), 600, 100);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("GoblineOrange"), sf::Vector2f(350, -80), sf::Vector2f(0, 1), 600, 100);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("GoblineOrange"), sf::Vector2f(410, -80), sf::Vector2f(0, 1), 600, 100);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 280), sf::Vector2f(0.813, 0.584), 1000, 100);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineOrange"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineOrange"), sf::Vector2f(710, 280), sf::Vector2f(-0.849, 0.527), 1000, 100);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 27:
		if (TOTALTIME > 56.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(-0.106, 0.994), 600, 150);
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 2500, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 2500, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(480, -30), sf::Vector2f(-0.106, 0.994), 600, 100);
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(-0.106, 0.994), 600, 100);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(320, -30), sf::Vector2f(-0.106, 0.994), 600, 100);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(-0.106, 0.994), 600, 100);
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 28:
		if (TOTALTIME > 58.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(160, -30), sf::Vector2f(-0.106, 0.994), 600, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(-0.106, 0.994), 600, 100);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(-0.106, 0.994), 600, 100);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 3000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(290, -30), sf::Vector2f(0, 1), 1500, 100);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeBlue"), sf::Vector2f(250, -30), sf::Vector2f(0, 1), 1500, 100);
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 29:
		if (TOTALTIME > 60.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 100);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(160, -30), sf::Vector2f(0, 1), 600, 100);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 3000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(460, -90), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 100);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 30:
		if (TOTALTIME > 62.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 600, 100);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(480, -30), sf::Vector2f(0, 1), 600, 100);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 100);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 3000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 600, 100);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 31:
		if (TOTALTIME > 64.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 100);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(60, -30), sf::Vector2f(0, 1), 600, 100);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeBlue"), sf::Vector2f(120, -30), sf::Vector2f(0, 1), 600, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 600, 100);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 100);

				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(60, -80), sf::Vector2f(0, 1), 600, 100);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeBlue"), sf::Vector2f(120, -80), sf::Vector2f(0, 1), 600, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(180, -80), sf::Vector2f(0, 1), 600, 100);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -80), sf::Vector2f(0, 1), 600, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人

				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 1000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(460, -30), sf::Vector2f(0, 1), 1000, 100);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeBlue"), sf::Vector2f(520, -30), sf::Vector2f(0, 1), 1000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(580, -30), sf::Vector2f(0, 1), 1000, 100);

				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(400, -80), sf::Vector2f(0, 1), 1000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(460, -80), sf::Vector2f(0, 1), 1000, 100);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeBlue"), sf::Vector2f(520, -80), sf::Vector2f(0, 1), 1000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(580, -80), sf::Vector2f(0, 1), 1000, 100);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 3000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(460, -90), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 32:
		if (TOTALTIME > 66.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(230, -30), sf::Vector2f(0, 1), 1000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(290, -30), sf::Vector2f(0, 1), 1000, 100);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeBlue"), sf::Vector2f(350, -30), sf::Vector2f(0, 1), 1000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(410, -30), sf::Vector2f(0, 1), 1000, 100);

				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(230, -80), sf::Vector2f(0, 1), 1000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(290, -80), sf::Vector2f(0, 1), 1000, 100);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeBlue"), sf::Vector2f(350, -80), sf::Vector2f(0, 1), 1000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(410, -80), sf::Vector2f(0, 1), 1000, 100);
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 3000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 33:
		if (TOTALTIME > 68.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 3000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(460, -90), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 34:
		if (TOTALTIME > 70.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(230, -30), sf::Vector2f(0, 1), 3000, 100);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(290, -30), sf::Vector2f(0, 1), 3000, 100);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(350, -30), sf::Vector2f(0, 1), 3000, 100);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(420, -30), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 35:
		if (TOTALTIME > 72.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 3000, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 3000, 150);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 3000, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(460, -90), sf::Vector2f(0, 1), 3000, 150);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 36:
		if (TOTALTIME > 74.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 3000, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 3000, 150);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 3000, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(460, -90), sf::Vector2f(0, 1), 3000, 150);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 37:
		if (TOTALTIME > 76.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 3000, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 3000, 150);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 3000, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(460, -90), sf::Vector2f(0, 1), 3000, 150);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 38:
		if (TOTALTIME > 78.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 3000, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 3000, 150);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(230, -30), sf::Vector2f(0, 1), 3000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(290, -30), sf::Vector2f(0, 1), 3000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(350, -30), sf::Vector2f(0, 1), 3000, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(410, -30), sf::Vector2f(0, 1), 3000, 150);

				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(230, -80), sf::Vector2f(0, 1), 3000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(290, -80), sf::Vector2f(0, 1), 3000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(350, -80), sf::Vector2f(0, 1), 3000, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(410, -80), sf::Vector2f(0, 1), 3000, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -90), sf::Vector2f(0, 1), 3000, 120);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(460, -30), sf::Vector2f(0, 1), 3000, 120);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 39:
		if (TOTALTIME > 80.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 3000, 120);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 3000, 120);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -90), sf::Vector2f(0, 1), 3000, 120);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(460, -30), sf::Vector2f(0, 1), 3000, 120);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 40:
		if (TOTALTIME > 82.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 3000, 120);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 3000, 120);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -90), sf::Vector2f(0, 1), 3000, 120);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(460, -30), sf::Vector2f(0, 1), 3000, 120);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 41:
		if (TOTALTIME > 84.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 3000, 120);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 3000, 120);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -90), sf::Vector2f(0, 1), 3000, 120);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(460, -30), sf::Vector2f(0, 1), 3000, 120);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 42:
		if (TOTALTIME > 86.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(180, -30), sf::Vector2f(0, 1), 3000, 120);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 3000, 120);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("SlimeYellow"), sf::Vector2f(230, -30), sf::Vector2f(0, 1), 3000, 100);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(290, -30), sf::Vector2f(0, 1), 3000, 100);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(350, -30), sf::Vector2f(0, 1), 3000, 100);
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("SlimeYellow"), sf::Vector2f(410, -30), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 43:
		if (TOTALTIME > 88.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				//精英怪大蜘蛛
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Spider", assetManager.getTexture("Spider"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 350000, 100);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 44:
		if (TOTALTIME > 90.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(560, -30), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;
	case 45:
		if (TOTALTIME > 92.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(80, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 46:
		if (TOTALTIME > 94.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 47:
		if (TOTALTIME > 96.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(560, -30), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 48:
		if (TOTALTIME > 98.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(80, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 49:
		if (TOTALTIME > 100.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -80), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;
	case 50:
		if (TOTALTIME > 102.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(560, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(560, -80), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -80), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;
	case 51:
		if (TOTALTIME > 104.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -80), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(80, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(80, -80), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;
	case 52:
		if (TOTALTIME > 106.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -80), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(80, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(80, -80), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;
	case 53:
		if (TOTALTIME > 108.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -80), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -80), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;
	case 54:
		if (TOTALTIME > 110.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(560, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(560, -80), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -80), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;
	case 55:
		if (TOTALTIME > 112.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;
	case 56:
		if (TOTALTIME > 114.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(560, -30), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy1", assetManager.getTexture("SlimeBlue"), sf::Vector2f(560, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 57:
		if (TOTALTIME > 116.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeBlue"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;
	case 58:
		if (TOTALTIME > 118.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(80, -30), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy1", assetManager.getTexture("SlimeBlue"), sf::Vector2f(80, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;
	case 59:
		if (TOTALTIME > 120.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -80), sf::Vector2f(0, 1), 600, 150);

				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(560, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy1", assetManager.getTexture("SlimeBlue"), sf::Vector2f(560, -80), sf::Vector2f(0, 1), 600, 150);

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;
	case 60:
		if (TOTALTIME > 122.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeBlue"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(400, -80), sf::Vector2f(0, 1), 600, 150);

				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(80, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy1", assetManager.getTexture("SlimeBlue"), sf::Vector2f(80, -80), sf::Vector2f(0, 1), 600, 150);

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;
	case 61:
		if (TOTALTIME > 124.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(400, -80), sf::Vector2f(0, 1), 600, 150);

				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeBlue"), sf::Vector2f(560, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy1", assetManager.getTexture("SlimeBlue"), sf::Vector2f(560, -80), sf::Vector2f(0, 1), 600, 150);

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;
	case 62:
		if (TOTALTIME > 126.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeBlue"), sf::Vector2f(240, -80), sf::Vector2f(0, 1), 600, 150);

				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeBlue"), sf::Vector2f(80, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy1", assetManager.getTexture("SlimeBlue"), sf::Vector2f(80, -80), sf::Vector2f(0, 1), 600, 150);

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;
	case 63:
		if (TOTALTIME > 128.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -90), sf::Vector2f(0, 1), 600, 150);

				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 64:
		if (TOTALTIME > 130.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy1", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 600, 150);

				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineBlue"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 65:
		if (TOTALTIME > 132.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -90), sf::Vector2f(0, 1), 600, 150);

				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 66:
		if (TOTALTIME > 134.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy1", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 600, 150);

				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineBlue"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 67:
		if (TOTALTIME > 136.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -90), sf::Vector2f(0, 1), 600, 150);

				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 68:
		if (TOTALTIME > 138.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy1", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 600, 150);

				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineBlue"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 69:
		if (TOTALTIME > 140.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -90), sf::Vector2f(0, 1), 600, 150);

				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("GoblineBlue"), sf::Vector2f(-30, 240), sf::Vector2f(0.813, 0.584), 1000, 150);

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 70:
		if (TOTALTIME > 142.6f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 600, 150);

				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("GoblineBlue"), sf::Vector2f(670, 240), sf::Vector2f(-0.813, 0.584), 1000, 150);

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;


	case 71:
		if (TOTALTIME > 146.f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 600, 150);

				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -90), sf::Vector2f(0, 1), 600, 150);

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 72:
		if (TOTALTIME > 148.f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -90), sf::Vector2f(0, 1), 600, 150);

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 73:
		if (TOTALTIME > 150.f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -90), sf::Vector2f(0, 1), 600, 150);

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 74:
		if (TOTALTIME > 152.f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -90), sf::Vector2f(0, 1), 600, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, -90), sf::Vector2f(0, 1), 600, 150);

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;





	case 75:
		if (TOTALTIME > 154.0f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(180, 0), sf::Vector2f(0, 1), 2000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -60), sf::Vector2f(0, 1), 3000, 150);
				break;
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, 0), sf::Vector2f(0, 1), 3500, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(460, -60), sf::Vector2f(0, 1), 3500, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 76:
		if (TOTALTIME > 156.0f) {
			//释放敌人
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(180, 0), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -60), sf::Vector2f(0, 1), 3500, 150);
			TIMEFORPLAY++;
		}
		break;

	case 77:
		if (TOTALTIME > 157.5f) {
			//释放敌人
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(230, 0), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(290, 0), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(350, 0), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(410, 0), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(230, -50), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(290, -50), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(350, -50), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(410, -50), sf::Vector2f(0, 1), 3500, 150);
			TIMEFORPLAY++;
		}
		break;

	case 78:
		if (TOTALTIME = 158.0f) {
			//释放敌人
			//精英怪大蜘蛛
			EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("Spider"), sf::Vector2f(0, 0), sf::Vector2f(0, 1), 5000, 200);
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(180, 0), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -60), sf::Vector2f(0, 1), 3500, 150);
			TIMEFORPLAY++;
		}
		break;

	case 79:
		if (TOTALTIME > 158.0f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, 0), sf::Vector2f(0, 1), 2000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(460, -60), sf::Vector2f(0, 1), 3000, 150);
				break;
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(180, 0), sf::Vector2f(0, 1), 3500, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -60), sf::Vector2f(0, 1), 3500, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 80:
		if (TOTALTIME > 160.0f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, 0), sf::Vector2f(0, 1), 2000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(460, -60), sf::Vector2f(0, 1), 3000, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(180, 0), sf::Vector2f(0, 1), 3500, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -60), sf::Vector2f(0, 1), 3500, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;


	case 81:
		if (TOTALTIME > 162.0f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
                                EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("Spider"), sf::Vector2f(640, 0), sf::Vector2f(0, 1), 5000, 200);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(400, 0), sf::Vector2f(0, 1), 2000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeYellow"), sf::Vector2f(460, -60), sf::Vector2f(0, 1), 3000, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(180, 0), sf::Vector2f(0, 1), 3500, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(240, -60), sf::Vector2f(0, 1), 3500, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 82:
		if (TOTALTIME > 164.0f) {
			//释放敌人
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(230, 0), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(290, 0), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(350, 0), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeYellow"), sf::Vector2f(410, 0), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("SlimeYellow"), sf::Vector2f(230, -50), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("SlimeYellow"), sf::Vector2f(290, -50), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("SlimeYellow"), sf::Vector2f(350, -50), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("SlimeYellow"), sf::Vector2f(410, -50), sf::Vector2f(0, 1), 3500, 150);
			TIMEFORPLAY++;
		}
		break;

	case 83:
		if (TOTALTIME > 165.0f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
                                EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("Spider"), sf::Vector2f(0, 0), sf::Vector2f(0, 1), 5000, 200);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(80, 0), sf::Vector2f(0, 1), 2000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(80, -50), sf::Vector2f(0, 1), 3000, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, 0), sf::Vector2f(0, 1), 3500, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -50), sf::Vector2f(0, 1), 3500, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 84:
		if (TOTALTIME > 167.0f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, 0), sf::Vector2f(0, 1), 2000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -50), sf::Vector2f(0, 1), 3000, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(560, 0), sf::Vector2f(0, 1), 3500, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(560, -50), sf::Vector2f(0, 1), 3500, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 85:
		if (TOTALTIME > 169.0f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
                                EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("Spider"), sf::Vector2f(640, 0), sf::Vector2f(0, 1), 5000, 200);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, 0), sf::Vector2f(0, 1), 2000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -50), sf::Vector2f(0, 1), 3000, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, 0), sf::Vector2f(0, 1), 3500, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -50), sf::Vector2f(0, 1), 3500, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 86:
		if (TOTALTIME > 171.0f) {
			//释放敌人
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(80, 0), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(80, -50), sf::Vector2f(0, 1), 3500, 150);
			TIMEFORPLAY++;
		}
		break;

	case 87:
		if (TOTALTIME > 172.5f) {
			//释放敌人
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(230, 0), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(290, 0), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(350, 0), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(410, 0), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("SlimeRed"), sf::Vector2f(230, -50), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("SlimeRed"), sf::Vector2f(290, -50), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("SlimeRed"), sf::Vector2f(350, -50), sf::Vector2f(0, 1), 3500, 150);
			EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("SlimeRed"), sf::Vector2f(410, -50), sf::Vector2f(0, 1), 3500, 150);
			TIMEFORPLAY++;
		}
		break;

	case 88:
		if (TOTALTIME > 172.0f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, 0), sf::Vector2f(0, 1), 2000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -50), sf::Vector2f(0, 1), 3000, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, 0), sf::Vector2f(0, 1), 3500, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -50), sf::Vector2f(0, 1), 3500, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 89:
		if (TOTALTIME > 174.0f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(560, 0), sf::Vector2f(0, 1), 2000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(560, -50), sf::Vector2f(0, 1), 3000, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, 0), sf::Vector2f(0, 1), 3500, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -50), sf::Vector2f(0, 1), 3500, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 90:
		if (TOTALTIME > 176.0f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, 0), sf::Vector2f(0, 1), 2000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -50), sf::Vector2f(0, 1), 3000, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(80, 0), sf::Vector2f(0, 1), 3500, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(80, -50), sf::Vector2f(0, 1), 3500, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 91:
		if (TOTALTIME > 178.0f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, 0), sf::Vector2f(0, 1), 2000, 150);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -50), sf::Vector2f(0, 1), 3000, 150);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, 0), sf::Vector2f(0, 1), 3500, 150);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -50), sf::Vector2f(0, 1), 3500, 150);
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(230, 0), sf::Vector2f(0, 1), 3500, 100);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(290, 0), sf::Vector2f(0, 1), 3500, 100);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(350, 0), sf::Vector2f(0, 1), 3500, 100);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(410, 0), sf::Vector2f(0, 1), 3500, 100);

				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("SlimeRed"), sf::Vector2f(230, -50), sf::Vector2f(0, 1), 3500, 100);
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("SlimeRed"), sf::Vector2f(290, -50), sf::Vector2f(0, 1), 3500, 100);
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("SlimeRed"), sf::Vector2f(350, -50), sf::Vector2f(0, 1), 3500, 100);
				EnemyFactory::createEnemy("Enemy5", assetManager.getTexture("SlimeRed"), sf::Vector2f(410, -50), sf::Vector2f(0, 1), 3500, 100);
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人	

			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 92:
		if (TOTALTIME > 180.0f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(60, 0), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(120, 0), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(180, 0), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, 0), sf::Vector2f(0, 1), 2000, 100);

				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(60, -50), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(120, -50), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(180, -50), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -50), sf::Vector2f(0, 1), 2000, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, 0), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(460, 0), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(520, 0), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(580, 0), sf::Vector2f(0, 1), 2000, 100);

				EnemyFactory::createEnemy("Enemy4", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -50), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(460, -50), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeRed"), sf::Vector2f(520, -50), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(580, -50), sf::Vector2f(0, 1), 2000, 100);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(80, 0), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(80, -50), sf::Vector2f(0, 1), 2000, 100);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 93:
		if (TOTALTIME > 182.0f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, 0), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -50), sf::Vector2f(0, 1), 2000, 100);
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, 0), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -50), sf::Vector2f(0, 1), 2000, 100);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;
	case 94:
		if (TOTALTIME > 184.0f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(560, 0), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(560, -50), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, 0), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(400, -50), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;
	case 95:
		if (TOTALTIME > 186.0f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, 0), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -50), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(80, 0), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(80, -50), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 96:
		if (TOTALTIME > 188.4f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, 0), sf::Vector2f(0, 1), 2000, 100);
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeRed"), sf::Vector2f(240, -50), sf::Vector2f(0, 1), 3000, 100);
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人

			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("SlimePink"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(160, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 97:
		if (TOTALTIME > 190.4f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("SlimeGreen"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(480, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 98:
		if (TOTALTIME > 192.4f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("SlimeGreen"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimePink"), sf::Vector2f(160, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 99:
		if (TOTALTIME > 194.4f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("SlimeGreen"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(480, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 100:
		if (TOTALTIME > 196.4f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("SlimeGreen"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(160, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;


	case 101:
		if (TOTALTIME > 198.4f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("SlimePink"), sf::Vector2f(160, -30), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 102:
		if (TOTALTIME > 200.4f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("SlimeGreen"), sf::Vector2f(480, -30), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(400, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy2", assetManager.getTexture("SlimeGreen"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;

	case 103:
		if (TOTALTIME > 202.4f) {
			//2s框架开始
			switch (ENEMYOUT2S)
			{
			case 0: ENEMYOUT2S++; ENEMYOUT2STIME = 0.f;
				//释放敌人
				break;
			case 1: if (ENEMYOUT2STIME >= 0.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 2: if (ENEMYOUT2STIME >= 0.4f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("SlimeGreen"), sf::Vector2f(160, -30), sf::Vector2f(0, 1), 3000, 100);
			} break;
			case 3: if (ENEMYOUT2STIME >= 0.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 4: if (ENEMYOUT2STIME >= 0.8f) {
				ENEMYOUT2S++;
				//释放敌人
				EnemyFactory::createEnemy("Enemy3", assetManager.getTexture("SlimeGreen"), sf::Vector2f(240, -30), sf::Vector2f(0, 1), 600, 150);
			} break;
			case 5: if (ENEMYOUT2STIME >= 1.0f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 6: if (ENEMYOUT2STIME >= 1.2f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 7: if (ENEMYOUT2STIME >= 1.4f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 8: if (ENEMYOUT2STIME >= 1.6f) {
				ENEMYOUT2S++;
				//释放敌人
			} break;
			case 9: if (ENEMYOUT2STIME >= 1.8f) {
				ENEMYOUT2S = 0; TIMEFORPLAY++;
				//释放敌人
			} break;
			default:
				break;
			}
			//2s框架结束
		}
		break;
	case 104:
		if (TOTALTIME > 205.0f) {
			//Boss战开始
			audioManager.playMusic("Boss1", false);
                        EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("Spider"), sf::Vector2f(80, 0), sf::Vector2f(0, 1), 2000, 200);
                        EnemyFactory::createEnemy("Enemy6", assetManager.getTexture("Spider"), sf::Vector2f(560, 0), sf::Vector2f(0, 1), 2000, 200);
			TIMEFORPLAY++;
			
		}
		break;
	case 105:
		if (TOTALTIME > 210.0f) {
			//Boss战开始
			TIMEFORPLAY++;
			EnemyFactory::createEnemy("SilmeBoss", assetManager.getTexture("SlimeBoss"), sf::Vector2f(320, -30), sf::Vector2f(0, 1), 1800000, 100);
		}
		break;
	case 900:
		if (TOTALTIME > 0.0f) {
			TIMEFORPLAY++;
		}
		break;

	case 901:
		if (TOTALTIME > 0.0f) {
			TIMEFORPLAY++;
		}
		break;

	case 902:
		if (TOTALTIME > 0.0f) {
			TIMEFORPLAY++;
		}
		break;

	case 903:
		if (TOTALTIME > 0.0f) {
			TIMEFORPLAY++;
		}
		break;

	case 904:
		if (TOTALTIME > 0.0f) {
			TIMEFORPLAY++;
		}
		break;

	case 905:
		if (TOTALTIME > 0.0f) {
			TIMEFORPLAY++;
		}
		break;

	case 906:
		if (TOTALTIME > 0.0f) {
			TIMEFORPLAY++;
		}
		break;

	default:
		break;
	}










}

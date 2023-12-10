#include "AssetManager.hpp"

AssetManager::AssetManager() {
	//构造方法。
	/*
	负责人: 波波沙

	功能:
		读取所有的素材

	参数: void

	返回值: void
	*/
	//----------------------实现------------------------//

	//读取字体"黑体"
	loadFont("simhei", "Asset/Font/simhei.ttf");
	//读取字体"幼圆"
	loadFont("SIMYOU", "Asset/Font/SIMYOU.TTF");

	//读取图片"酱可-主菜单"
	loadTexture("JumkoMenu", "Asset/Picture/JumkoMenu.png");
	//读取图片"文本-关于"
	loadTexture("TextAbout", "Asset/Picture/AboutText.png");
	//读取图片"文本-游戏玩法1"
	loadTexture("TextHowToPlay1", "Asset/Picture/HowToPlayText1.png");
	//读取图片"文本-游戏玩法2"
	loadTexture("TextHowToPlay2", "Asset/Picture/HowToPlayText2.png");
	//读取图片"主标题-酱可"
	loadTexture("Title1", "Asset/Picture/Title1.png");
	//读取图片"主标题-与"
	loadTexture("Title2", "Asset/Picture/Title2.png");
	//读取图片"主标题-危险之森"
	loadTexture("Title3", "Asset/Picture/Title3.png");
	//读取图片"开场-酱可"
	loadTexture("StartPic", "Asset/Picture/StartGame.png");
	//读取图片"鉴赏-锁定"
	loadTexture("Close", "Asset/Picture/Locked.png");

	//读取图片"立绘-正常-酱可"
	loadTexture("JumkoPic1", "Asset/Picture/JumkoPic1.png");
	//读取图片"立绘-大破(大嘘)-酱可"
	loadTexture("JumkoPic2", "Asset/Picture/JumkoPic2.png");
	//读取图片"技能图标"
	loadTexture("Skill", "Asset/Picture/Skill.png");
	//读取图片"战斗背景图片"
	loadTexture("BackGround1", "Asset/Picture/BackGround1.png");
	loadTexture("BackGround2", "Asset/Picture/BackGround2.png");

	//读取图片"CG1"
	loadTexture("WEIMEI1", "Asset/Picture/CG1.png");
	//读取图片"CG2"
	loadTexture("WEIMEI2", "Asset/Picture/CG2.png");
	//读取图片"CG3"
	loadTexture("WEIMEI3", "Asset/Picture/CG3.png");
	//读取图片"CG4"
	loadTexture("WEIMEI4", "Asset/Picture/CG4.png");
	//读取图片"CG5"
	loadTexture("WEIMEI5", "Asset/Picture/CG5.png");
	//读取图片"CG6"
	loadTexture("WEIMEI6", "Asset/Picture/CG6.png");
	//读取图片"CG7"
	loadTexture("WEIMEI7", "Asset/Picture/CG7.png");
	//读取图片"CG8"
	loadTexture("WEIMEI8", "Asset/Picture/CG8.png");
	//读取图片"CG9"
	loadTexture("WEIMEI9", "Asset/Picture/CG9.png");
	//读取图片"CG10"
	loadTexture("WEIMEI10", "Asset/Picture/CG10.png");
	//读取图片"CG11"
	loadTexture("WEIMEI11", "Asset/Picture/CG11.png");
	//读取图片"CG12"
	loadTexture("WEIMEI12", "Asset/Picture/CG12.png");

	//读取图片"玩家-酱可"
	loadTexture("Jumko", "Asset/Picture/Jumko.png");
	//读取图片"判定点"
	loadTexture("HitBox", "Asset/Picture/HitBox.png");

	//读取图片"敌人-双联装102mmSKC"
	loadTexture("Enemy1", "Asset/Picture/EnemyTest102mm.png");
	//读取图片"栩沐害怕的大大大大大大大蜘蛛"
	loadTexture("Spider", "Asset/Picture/Spider.png");
	//读取图片"史莱姆王"
	loadTexture("SlimeBoss", "Asset/Picture/Slime-Boss.png");
	//读取图片"绿色史莱姆"
	loadTexture("SlimeGreen", "Asset/Picture/Slime-Green.png");
	//读取图片"黄色史莱姆"
	loadTexture("SlimeYellow", "Asset/Picture/Slime-Yellow.png");
	//读取图片"蓝色史莱姆"
	loadTexture("SlimeBlue", "Asset/Picture/Slime-Blue.png");
	//读取图片"粉色史莱姆"
	loadTexture("SlimePink", "Asset/Picture/Slime-Pink.png");
	//读取图片"紫色史莱姆"
	loadTexture("SlimePurple", "Asset/Picture/Slime-Purple.png");
	//读取图片"红色史莱姆"
	loadTexture("SlimeRed", "Asset/Picture/Slime-Red.png");
	//读取图片"红色哥布林"
	loadTexture("GoblineRed", "Asset/Picture/Goblin-Red.png");
	//读取图片"橙色哥布林"
	loadTexture("GoblineOrange", "Asset/Picture/Goblin-Orange.png");
	//读取图片"黄色哥布林"
	loadTexture("GoblineYellow", "Asset/Picture/Goblin-Yellow.png");
	//读取图片"蓝色哥布林"
	loadTexture("GoblineBlue", "Asset/Picture/Goblin-Bule.png");

	//读取图片"Power点"
	loadTexture("PowerPoint", "Asset/Picture/PowerPoint2.png");
	//读取图片"Score点"
	loadTexture("ScorePoint", "Asset/Picture/ScorePoint2.png");
	//读取图片"子弹-技能"
	loadTexture("SkillButton", "Asset/Picture/BulletMagic.png");
	//读取图片"子弹-20mm圆黄弹"
	loadTexture("Bullet1", "Asset/Picture/Bullet.png");
	//读取图片"子弹-10mm椭圆灰弹"
	loadTexture("Bullet2", "Asset/Picture/Bullet2.png");
	//读取图片"子弹-15mm椭圆灰弹"
	loadTexture("Bullet3", "Asset/Picture/Bullet3.png");
	//读取图片"子弹-10mm圆白弹"
	loadTexture("Bullet4", "Asset/Picture/Bullet4.png");
	//读取图片"子弹-50mm蛛丝弹"
	loadTexture("Bullet5", "Asset/Picture/Bullet5.png");
	//读取图片"子弹-30mm圆红弹"
	loadTexture("Bullet6", "Asset/Picture/Bullet6.png");
	//读取图片"子弹-15mm紫椭圆弹"
	loadTexture("Bullet7", "Asset/Picture/Bullet7.png");
	//读取图片"子弹-20mm椭圆黄弹"
	loadTexture("Bullet8", "Asset/Picture/Bullet8.png");
	//读取图片"子弹-10mm椭圆红白弹"
	loadTexture("Bullet9", "Asset/Picture/Bullet9.png");
	//读取图片"子弹-15mm圆黄弹"
	loadTexture("Bullet10", "Asset/Picture/Bullet10.png");

}

void AssetManager::loadTexture(const std::string& name, const std::string& filename) {
	// 创建并加载纹理
	/*
	负责人: 波波沙

	功能:
		创建并且加载纹理

	参数:
		const std::string& name     //哈希表的键，用这个名称去搜索对应的纹理
		const std::string& filename //纹理的路径

	返回值: void
	*/
	//----------------------实现------------------------//

	sf::Texture texture;
	if (texture.loadFromFile(filename)) {
		textures[name] = texture;
	}
}

void AssetManager::loadFont(const std::string& name, const std::string& filename) {
	// 创建并加载字体
	/*
	负责人: 波波沙

	功能:
		创建并且加载字体

	参数:
		const std::string& name     //哈希表的键，用这个名称去搜索对应的字体
		const std::string& filename //字体的路径

	返回值: void
	*/
	//----------------------实现------------------------//

	sf::Font font;
	if (font.loadFromFile(filename)) {
		fonts[name] = font;
	}
}

sf::Texture& AssetManager::getTexture(const std::string& name) {
	// 读取纹理
	/*
	负责人: 波波沙

	功能:
		读取纹理

	参数:
		const std::string& name     //输入键也就是名字来返回对应的纹理

	返回值: sf::Texture&
	*/
	//----------------------实现------------------------//

	return textures[name];
}


sf::Font& AssetManager::getFont(const std::string& name) {
	// 读取字体
	/*
	负责人: 波波沙

	功能:
		读取字体

	参数:
		const std::string& name     //输入键也就是名字来返回对应的字体

	返回值: sf::Font&
	*/
	//----------------------实现------------------------//

	return fonts[name];
}

#ifndef SETTINGSMANAGER_HPP
#define SETTINGSMANAGER_HPP

#include <string>
#include <vector>

// -------------------- 类设计 --------------------
/*
    【文件管理类】
    负责人： 波波沙

    功能：单例模式，复制位于存档文件的读写
        1.读写全英文字符串秘钥
        2.读写01穿记录CG解锁
        3.读写两个音量值
        4.记录是否开启无敌模式
*/

class SettingsManager {
public:

    //单例唯一入口
    static SettingsManager& getInstance();
    // 禁用拷贝和赋值
    SettingsManager(const SettingsManager&) = delete;
    SettingsManager& operator=(const SettingsManager&) = delete;

    //读取文件
    void loadSettings(const std::string& filename);
    //保存文件
    void saveSettings(const std::string& filename);

    //测试
    void printSettings() const;

    //秘钥
    std::string englishString;
    //01CG串
    std::vector<bool> unlockedCGs;
    //音效音量
    int soundVolume;
    //音乐音量
    int musicVolume;
    //无敌模式
    bool isInvincible;
    //键位调整
    bool iswasd;

    //困难模式
    bool isHardCore;

    //一键进入BOSS战模式
    bool isBossCore = false;

private:
    
    SettingsManager() {} // 私有构造函数
};

#endif // SETTINGSMANAGER_HPP

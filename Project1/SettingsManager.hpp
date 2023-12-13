#ifndef SETTINGSMANAGER_HPP
#define SETTINGSMANAGER_HPP

#include <string>
#include <vector>

// -------------------- ����� --------------------
/*
    ���ļ������ࡿ
    �����ˣ� ����ɳ

    ���ܣ�����ģʽ������λ�ڴ浵�ļ��Ķ�д
        1.��дȫӢ���ַ�����Կ
        2.��д01����¼CG����
        3.��д��������ֵ
        4.��¼�Ƿ����޵�ģʽ
*/

class SettingsManager {
public:

    //����Ψһ���
    static SettingsManager& getInstance();
    // ���ÿ����͸�ֵ
    SettingsManager(const SettingsManager&) = delete;
    SettingsManager& operator=(const SettingsManager&) = delete;

    //��ȡ�ļ�
    void loadSettings(const std::string& filename);
    //�����ļ�
    void saveSettings(const std::string& filename);

    //����
    void printSettings() const;

    //��Կ
    std::string englishString;
    //01CG��
    std::vector<bool> unlockedCGs;
    //��Ч����
    int soundVolume;
    //��������
    int musicVolume;
    //�޵�ģʽ
    bool isInvincible;

    //����ģʽ
    bool isHardCore;
    //EXģʽ
    bool isEXHard;

    //一键进入BOSS战模式
    bool isBossCore = false;

private:
    
    SettingsManager() {} // ˽�й��캯��
};

#endif // SETTINGSMANAGER_HPP

#include "SettingsManager.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

SettingsManager& SettingsManager::getInstance() {
    //����Ψһ���
    /*
    ������: ����ɳ

    ����:
        ������Ψһ���

    ����: void

    ����ֵ: SettingsManager&
    */
    //----------------------ʵ��------------------------//

    static SettingsManager instance;
    return instance;
}

void SettingsManager::loadSettings(const std::string& filename) {
    //��ȡ�ļ�
    /*
    ������: ����ɳ

    ����:
        ���浵�ļ����������ݶ����ڴ�

    ����: 
        const std::string& filename //�浵�ļ�·��

    ����ֵ: void
    */
    //----------------------ʵ��------------------------//

    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        std::getline(file, englishString);

        std::getline(file, line);
        std::istringstream iss(line);
        int value;
        unlockedCGs.clear();
        while (iss >> value) {
            unlockedCGs.push_back(value != 0);
        }

        if (std::getline(file, line)) {
            std::istringstream iss(line);
            iss >> soundVolume >> musicVolume;
        }

        if (std::getline(file, line)) {
            isInvincible = (line == "1");
        }
    }
    else {
        std::cout << "Unable to open file for reading" << std::endl;
    }

    //���в���
    printSettings();
}

void SettingsManager::saveSettings(const std::string& filename) {
    //�����ļ�
    /*
    ������: ����ɳ

    ����:
        ���ڴ��е����ݴ浽�ļ��б���

    ����:
        const std::string& filename //�浵�ļ�·��

    ����ֵ: void
    */
    //----------------------ʵ��------------------------//

    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
        return;
    }

    file << englishString << "\n";
    if (!file.good()) {
        std::cerr << "Error writing englishString to file." << std::endl;
    }

    for (bool cg : unlockedCGs) {
        file << (cg ? 1 : 0) << " ";
    }
    file << "\n";
    if (!file.good()) {
        std::cerr << "Error writing unlockedCGs to file." << std::endl;
    }

    file << soundVolume << " " << musicVolume << "\n";
    if (!file.good()) {
        std::cerr << "Error writing volume settings to file." << std::endl;
    }

    file << (isInvincible ? 1 : 0) << "\n";
    if (!file.good()) {
        std::cerr << "Error writing isInvincible to file." << std::endl;
    }

    //����
    std::cout << "English String: " << englishString << std::endl;
    std::cout << "Unlocked CGs: ";
    for (bool cg : unlockedCGs) {
        std::cout << (cg ? "1" : "0");
    }
    std::cout << std::endl;
    std::cout << "Sound Volume: " << soundVolume << std::endl;
    std::cout << "Music Volume: " << musicVolume << std::endl;
    std::cout << "isInvincible: " << isInvincible << std::endl;
}

void SettingsManager::printSettings() const {
    // ���Է�������ӡ��ǰ����
    std::cout << "English String: " << englishString << std::endl;
    std::cout << "Unlocked CGs: ";
    for (bool cg : unlockedCGs) {
        std::cout << (cg ? "1" : "0");
    }
    std::cout << std::endl;
    std::cout << "Sound Volume: " << soundVolume << std::endl;
    std::cout << "Music Volume: " << musicVolume << std::endl;
}

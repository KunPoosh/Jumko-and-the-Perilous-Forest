#ifndef SETTINGSMANAGER_HPP
#define SETTINGSMANAGER_HPP

#include <string>
#include <vector>

// -------------------- ÀàÉè¼Æ --------------------
/*
    ¡¾ÎÄ¼ş¹ÜÀíÀà¡¿
    ¸ºÔğÈË£º ²¨²¨É³

    ¹¦ÄÜ£ºµ¥ÀıÄ£Ê½£¬¸´ÖÆÎ»ÓÚ´æµµÎÄ¼şµÄ¶ÁĞ´
        1.¶ÁĞ´È«Ó¢ÎÄ×Ö·û´®ÃØÔ¿
        2.¶ÁĞ´01´©¼ÇÂ¼CG½âËø
        3.¶ÁĞ´Á½¸öÒôÁ¿Öµ
        4.¼ÇÂ¼ÊÇ·ñ¿ªÆôÎŞµĞÄ£Ê½
*/

class SettingsManager {
public:

    //µ¥ÀıÎ¨Ò»Èë¿Ú
    static SettingsManager& getInstance();
    // ½ûÓÃ¿½±´ºÍ¸³Öµ
    SettingsManager(const SettingsManager&) = delete;
    SettingsManager& operator=(const SettingsManager&) = delete;

    //¶ÁÈ¡ÎÄ¼ş
    void loadSettings(const std::string& filename);
    //±£´æÎÄ¼ş
    void saveSettings(const std::string& filename);

    //²âÊÔ
    void printSettings() const;

    //ÃØÔ¿
    std::string englishString;
    //01CG´®
    std::vector<bool> unlockedCGs;
    //ÒôĞ§ÒôÁ¿
    int soundVolume;
    //ÒôÀÖÒôÁ¿
    int musicVolume;
    //ÎŞµĞÄ£Ê½
    bool isInvincible;

    //À§ÄÑÄ£Ê½
    bool isHardCore;
    //EXÄ£Ê½
    bool isEXHard;

    //ä¸€é”®è¿›å…¥BOSSæˆ˜æ¨¡å¼
    bool isBossCore = false;

private:
    
    SettingsManager() {} // Ë½ÓĞ¹¹Ôìº¯Êı
};

#endif // SETTINGSMANAGER_HPP

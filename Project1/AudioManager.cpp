#include "AudioManager.hpp"

AudioManager& AudioManager::getInstance() {
    //单例唯一入口。
    /*
    负责人: 波波沙

    功能:
        返回当前单例的引用

    参数: void

    返回值: AudioManager&
    */
    //----------------------实现------------------------//

    static AudioManager instance;
    return instance;
}

AudioManager::AudioManager() {
    //构造方法。
    /*
    负责人: 波波沙

    功能:
        读取所有的素材

    参数: void

    返回值: void
    */
    //----------------------实现------------------------//

    //默认音乐音效音量为1
    volumeMusic = 1;
    volumeSound = 1;

    //读入音乐
    //读入主菜单BGM
    loadMusic("MenuMusic1", "Asset/Music/MenuMusic1.mp3", 50);
    //读入第一关BGM
    loadMusic("Stage1", "Asset/Music/Kochab.mp3", 40);
    //读入第一关Boss战BGM
    loadMusic("Boss1", "Asset/Music/Boss1.mp3", 50);

    //读入音效
    //读入选择按钮音效
    loadSound("SelectButton", "Asset/Sound/Selectbutton.mp3", 100);
    //读入点击按钮时的音效
    loadSound("ClickButton", "Asset/Sound/Clickbutton.mp3", 100);

    //读入玩家攻击的音效
    loadSound("PlayerAttack1", "Asset/Sound/PlayerAttack1.mp3", 80);
    loadSound("PlayerAttack2", "Asset/Sound/PlayerAttack2.mp3", 100);
    loadSound("PlayerAttack3", "Asset/Sound/PlayerAttack3.mp3", 20);
    //读入敌人攻击的音效
    loadSound("EnemyAttack1", "Asset/Sound/enemyAttack1.mp3", 10);
    //读入玩家被击中的音效
    loadSound("HitPlayer", "Asset/Sound/hitPlayer.mp3", 100);
    //读入敌人被击中的音效
    loadSound("HitEnemy1", "Asset/Sound/hitEnemy1.mp3", 25);
    //读入敌人爆炸的音效
    loadSound("Explode1", "Asset/Sound/explode1.mp3", 100);
    loadSound("Explode2", "Asset/Sound/explode2.mp3", 100);
    loadSound("Explode3", "Asset/Sound/explode3.mp3", 100);
    loadSound("Explode4", "Asset/Sound/explode4.mp3", 100);
    //敌人死亡通用音效
    loadSound("EnemyDead1", "Asset/Sound/EnemyDead1.wav", 10);
    //玩家擦弹音效
    loadSound("Summary", "Asset/Sound/summary.mp3",15);
    //大破音效
    loadSound("Break", "Asset/Sound/break.mp3", 100);

    //角色语音区，都是音效
    //标题
    loadSound("Jumko_Title", "Asset/Sound/Jumko_Title.wav", 100);
    //受伤音效
    loadSound("Jumko_Hit1", "Asset/Sound/Jumko_Hit1.wav", 100);
    loadSound("Jumko_Hit2", "Asset/Sound/Jumko_Hit2.wav", 100);
    loadSound("Jumko_Hit3", "Asset/Sound/Jumko_Hit3.wav", 100);
    loadSound("Jumko_Hit4", "Asset/Sound/Jumko_Hit4.wav", 100);
    loadSound("Jumko_Hit5", "Asset/Sound/Jumko_Hit5.wav", 100);
    //大破音效
    loadSound("Jumko_Break", "Asset/Sound/Jumko_Break.wav", 100);
    //战败音效
    loadSound("Jumko_Fail", "Asset/Sound/Jumko_Fail.wav", 100);
    //战胜音效
    loadSound("Jumko_Victory", "Asset/Sound/Jumko_Success.wav", 100);
    //入场音效
    loadSound("Jumko_Begin", "Asset/Sound/Jumko_Begain.wav", 100);
    //鉴赏场景
    loadSound("Jumko_CG", "Asset/Sound/Jumko_CG.wav", 100);
    //设置场景
    loadSound("Jumko_Setting", "Asset/Sound/Jumko_Setting.wav", 100);
    //关于场景
    loadSound("Jumko_About", "Asset/Sound/Jumko_About.wav", 100);
    //玩法场景
    loadSound("Jumko_HowtoPlay", "Asset/Sound/Jumko_HowtoPlay.wav", 100);
    //退出
    loadSound("Jumko_Exit", "Asset/Sound/Jumko_Exit.wav", 100);
}

void AudioManager::loadSound(const std::string& name, const std::string& filename, float volume) {
    //读取音效,同时设置音效音量初始值
    /*
    负责人: 波波沙

    功能:
        将音效读入，设置音效的音量基值

    参数: 
        const std::string& name     //音效的名字，通过这个调用音效
        const std::string& filename //音效文件的路径
        float volume                //音效音量的基准值（0-100）

    返回值: void
    */
    //----------------------实现------------------------//

    sf::SoundBuffer buffer;
    if (buffer.loadFromFile(filename)) {
        soundBuffers[name] = buffer;
        initialSoundVolumes[name] = volume;
    }
}

void AudioManager::playSound(const std::string& name) {
    //播放音效
    /*
    负责人: 波波沙

    功能:
        播放音效

    参数:
        const std::string& name     //音效的名字，通过这个调用音效

    返回值: void
    */
    //----------------------实现------------------------//

    auto bufferIt = soundBuffers.find(name);
    if (bufferIt != soundBuffers.end()) {
        auto sound = std::make_unique<sf::Sound>();
        sound->setBuffer(bufferIt->second);
        sound->setVolume(initialSoundVolumes[name] * volumeSound);
        sound->play();
        playingSounds.push_back(std::move(sound));
    }
}

void AudioManager::loadMusic(const std::string& name, const std::string& filename, float volume) {
    //读取音乐，同时设置音乐音量初始值
    /*
    负责人: 波波沙

    功能:
        读取音乐，同时设置音乐音量初始值

    参数:
        const std::string& name         //音乐的名字，通过这个名字调用音乐
        const std::string& filename     //音乐文件的路径
        float volume                    //音乐的音量基值

    返回值: void
    */
    //----------------------实现------------------------//

    auto musicFile = std::make_unique<sf::Music>();
    if (musicFile->openFromFile(filename)) {
        music[name] = std::move(musicFile);
        initialMusicVolumes[name] = volume;
        music[name]->setVolume(volume);
    }
}

void AudioManager::playMusic(const std::string& name, bool loop) {
    //播放音乐，可选择是否循环播放，播放时如果有正在播放的则进行切换
    /*
    负责人: 波波沙

    功能:
        播放音乐，可选择是否循环播放，播放时如果有正在播放的则进行切换

    参数:
        const std::string& name         //音乐的名字，通过这个选择要播放的音乐
        bool loop                       //是否要循环播放BGM

    返回值: void
    */
    //----------------------实现------------------------//

    auto found = music.find(name);
    if (found != music.end() && found->second) {
        if (currentBGM) {
            currentBGM->stop();
        }
        currentBGM = found->second.get();
        currentBGM->setLoop(loop);
        currentBGM->play();
    }
}

void AudioManager::stopMusic() {
    //停止播放音乐
    /*
    负责人: 波波沙

    功能:
        停止播放音乐

    参数:void

    返回值: void
    */
    //----------------------实现------------------------//

    if (currentBGM) {
        currentBGM->stop();
        currentBGM = nullptr;
    }
}

void AudioManager::pauseMusic() {
    if (currentBGM != nullptr && currentBGM->getStatus() == sf::Music::Playing) {
        currentBGM->pause();
    }
}

void AudioManager::resumeMusic() {
    if (currentBGM != nullptr && currentBGM->getStatus() == sf::Music::Paused) {
        currentBGM->play();
    }
}

void AudioManager::setSoundVolume(float volume) {
    //设置音效的全局音量
    /*
    负责人: 波波沙

    功能:
        设置音效的全局音量

    参数:
        float volume    //一个介于0-1之间的数，用来设置音量大小

    返回值: void
    */
    //----------------------实现------------------------//

    volumeSound = volume;
}

void AudioManager::setMusicVolume(float volume) {
    //设置音乐的全局音量
    /*
    负责人: 波波沙

    功能:
        设置音乐的全局音量

    参数:
        float volume    //一个介于0-1之间的数，用来设置音量大小

    返回值: void
    */
    //----------------------实现------------------------//

    volumeMusic = volume;

    for (auto& musicItem : music) {
        float initialVolume = initialMusicVolumes[musicItem.first];
        if (musicItem.second) {
            musicItem.second->setVolume(initialVolume * volume);
        }
    }
}

void AudioManager::update() {
    //更新以销毁播放完毕的音效
    /*
    负责人: 波波沙

    功能:
        更新以销毁播放完毕的音效

    参数:void

    返回值: void
    */
    //----------------------实现------------------------//

    auto it = playingSounds.begin();
    while (it != playingSounds.end()) {
        if ((*it)->getStatus() == sf::Sound::Stopped) {
            it = playingSounds.erase(it);
        }
        else {
            ++it;
        }
    }
}

float AudioManager::getVolumeMusic()
{
    //获取音乐的音量
    /*
    负责人: 小柱

    功能:
        反馈音乐的音量

    参数:void

    返回值: float
    */
    //----------------------实现------------------------//
    return volumeMusic;
}
float AudioManager::getVolumeSound()
{
    //获取音效的音量
    /*
    负责人: 小柱

    功能:
        反馈音效的音量

    参数:void

    返回值: float
    */
    //----------------------实现------------------------//
    return volumeSound;
}

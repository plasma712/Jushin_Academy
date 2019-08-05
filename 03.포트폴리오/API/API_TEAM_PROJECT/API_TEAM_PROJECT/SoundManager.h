#pragma once



class CSoundManager
{
public:
	CSoundManager();
	~CSoundManager();

	void Initialize();

	static void PlayPlayerBulletSound();
	static void PlayMonsterDeadSound();
	static void PlayStageBGM();

private:
};


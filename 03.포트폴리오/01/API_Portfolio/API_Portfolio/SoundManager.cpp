#include "stdafx.h"
#include "SoundManager.h"
#include "mciapi.h"

CSoundManager::CSoundManager()
{
}

void CSoundManager::Initialize()
{
	
}

CSoundManager::~CSoundManager()
{
}

void CSoundManager::PlayPlayerBulletSound()
{
	TCHAR* SoundName = L"Missile.wav";
	//// 사운드 파일 이름,모드(시스템사운드 | 파일명 == null, 리소스 == 인스턴스핸들,재생속성(SND_ASYNC | SND_FILENAME)
	PlaySound(SoundName,NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
}

void CSoundManager::PlayMonsterDeadSound()
{
	mciSendString(L"open MonsterDead.mp3 type mpegvideo alias monDead", nullptr, 0, nullptr);
	mciSendString(L"seek monDead to start", nullptr, 0, nullptr);
	mciSendString(L"play monDead", nullptr, 0, nullptr);
}

void CSoundManager::PlayStageBGM()
{	
	mciSendString(L"play Stage1.mp3", NULL, 0, NULL);//배경음 재생 
}
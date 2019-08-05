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
	//// ���� ���� �̸�,���(�ý��ۻ��� | ���ϸ� == null, ���ҽ� == �ν��Ͻ��ڵ�,����Ӽ�(SND_ASYNC | SND_FILENAME)
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
	mciSendString(L"play Stage1.mp3", NULL, 0, NULL);//����� ��� 
}
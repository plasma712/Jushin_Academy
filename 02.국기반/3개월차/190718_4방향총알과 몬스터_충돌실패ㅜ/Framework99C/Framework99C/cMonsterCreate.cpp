#include "stdafx.h"
#include "cMonsterCreate.h"


cMonsterCreate::cMonsterCreate()
{
}


cMonsterCreate::~cMonsterCreate()
{
	Release();
}

void cMonsterCreate::Initialize()
{
}

int cMonsterCreate::Update()
{
	MonsterLstPush();

	return NO_EVENT;
}

void cMonsterCreate::Render(HDC hDC)
{
}

void cMonsterCreate::Release()
{
}

void cMonsterCreate::SetMonsterCreate(MONSTER_LST * pMonsterLst)
{
	m_pMonsterLst = pMonsterLst;
}

CGameObject * cMonsterCreate::CreateMonster()
{
	srand((unsigned int)time(NULL));

	CMonster* pMonster = new CMonster;
	pMonster->Initialize();
	//pMonster->SetPos(m_tInfo.fX, m_tInfo.fY);
	//pMonster->SetPos(400, 300);
	pMonster->SetPos(rand() % 700+(rand()%200+100), rand() % 500+(rand()%100+100));
	return pMonster;
}

void cMonsterCreate::MonsterLstPush()
{
	// if() 생성이 되었을때.
	m_pMonsterLst->push_back(CreateMonster());
}


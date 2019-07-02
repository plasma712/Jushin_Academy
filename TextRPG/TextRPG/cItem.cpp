#include "cItem.h"
#include "include.h"


cItem::cItem()
	:Player(nullptr)
{
}

cItem::cItem(int _InherentNumber, const char * _cName, int _iAtk, int _iDef, int _iHp, int _iMaxHp, int _iLv, int _iExp, int _iGold, const char*  _cItemClass, const char*  _cItemSlot)
	: cGameObject(_InherentNumber, _cName, _iAtk, _iDef, _iHp, _iMaxHp, _iLv, _iExp, _iGold)
{
	strcpy_s(cItemClass, _cItemClass);
	strcpy_s(cItemSlot, _cItemSlot);
}

cItem::~cItem()
{
}

void cItem::Init()
{
}

void cItem::Draw()
{
	//cout << "고유번호 : " << GetInherentNumber() << endl;
	cout << "이  름 : " << GetcName() << endl;
	cout << "부  위 : " << cItemSlot << endl;
	cout << "클래스 : " << cItemClass << endl;
	cout << "공격력 : " << GetiAtk() << endl;
	cout << "방어력 : " << GetiDef() << endl;
	cout << "금  액 : " << GetiGold() << endl;
}

void cItem::Update()
{
}

void cItem::Release()
{
}

cPlayer * cItem::ExtractPlayer()
{
	return Player;
}

void cItem::Receive(cPlayer * _Player)
{
	Player = _Player;
}

void cItem::Setting(int _InherentNumber, const char * _cName, int _iAtk, int _iDef, int _iHp, int _iMaxHp, int _iLv, int _iExp, int _iGold)
{
	cGameObject(_InherentNumber, _cName, _iAtk, _iDef, _iHp, _iMaxHp, _iLv, _iExp, _iGold);
}

void cItem::SaveItem(cItem* _cItem)
{
	FILE* fp = nullptr;

	errno_t err = fopen_s(&fp, "../Data/ItemData.txt", "ab");

	if (err == 0)
	{
		fwrite(&_cItem->Stats, sizeof(_cItem->Stats), 1, fp);
		fwrite(&_cItem->cItemClass, sizeof(_cItem->cItemClass), 1, fp);
		fwrite(&_cItem->cItemSlot, sizeof(_cItem->cItemSlot), 1, fp);
		fclose(fp);
	}
	else
	{
		cout << "파일 저장 실패" << endl;
	}
}

void cItem::LoadItem(int _iSelect)
{
	FILE* fp = nullptr;

	errno_t err = fopen_s(&fp, "../Data/ItemData.txt", "rb");
	if (err == 0)
	{
		fseek(fp, (sizeof(Stats) + sizeof(cItemClass) + sizeof(cItemSlot))*_iSelect/* *(_iSelect - 1)*/, SEEK_SET);
		fread(&Stats, sizeof(Stats), 1, fp);
		fread(&cItemClass, sizeof(cItemClass), 1, fp);
		fread(&cItemSlot, sizeof(cItemSlot), 1, fp);
		fclose(fp);
	}
	else
	{
		cout << "파일 호출 실패" << endl;
	}

}

void cItem::CreateItem() // 테스트용으로 만들기.
{
	int InherentNumber = 0;
	for (int k = 0; k < 100; k++)
	{
		cItem* Item = new cItem(
			InherentNumber,
			"아이템",
			InherentNumber,
			InherentNumber,
			InherentNumber,
			InherentNumber,
			InherentNumber,
			InherentNumber,
			InherentNumber,
			"노말",
			"무기"
		);
		Item->SaveItem(Item);
		InherentNumber++;
		delete Item;
	}
	cout << "<무기>아이템 생성 완료: " << InherentNumber << endl;
	system("pause");
	return;

}




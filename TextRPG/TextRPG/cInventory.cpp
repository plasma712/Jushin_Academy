#include "cInventory.h"
#include "cGameObject.h"
#include "include.h"

cInventory::cInventory()
{
}


cInventory::~cInventory()
{
}

void cInventory::Init()
{
}

void cInventory::Draw()
{
	dynamic_cast<cInventory*>(Item)->LoadItem(1);
	Item->Draw();
}

void cInventory::Update()
{
}

void cInventory::Release()
{
}

void cInventory::Receive(cGameObject * _Player)
{
	Player = _Player;
}

void cInventory::ItemCategory()
{
	while (true)
	{
		int Direction = 0;
		system("cls");
		
	}
}


char* cInventory::HavingItem(int _iSelectNumber)
{
	switch (_iSelectNumber)
	{
	case 1:
		strcpy_s(cItemCategory, "무기");
		break;
	case 2:
		strcpy_s(cItemCategory, "장비");
		break;
	case 3:
		strcpy_s(cItemCategory, "소비");
		break;
	case 4:
		strcpy_s(cItemCategory, "기타");
		break;

	default:
		break;
	}
	return cItemCategory;
}

void cInventory::SaveHavingItem(cItem* _Item)
{
	//Item = _Item;
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "../Data/HavingItem.txt", "ab");
	if (err == 0)
	{
		fwrite(_Item->StatsReturn(), sizeof(_Item->StatsReturn()), 1, fp);
		fwrite(&_Item->cItemClass, sizeof(_Item->cItemClass), 1, fp);
		fwrite(&_Item->cItemSlot, sizeof(_Item->cItemSlot), 1, fp);
		fclose(fp);
	}

}

void cInventory::LoadHavingItem(int _iSelect)
{
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "../Data/HavingItem.txt", "rb");
	//int InventoryItemListNumber = _iSelect;

	if (err == 0)
	{
		fseek(fp, (sizeof(Stats) + sizeof(cItemClass) + sizeof(cItemSlot))*_iSelect/* *(_iSelect - 1)*/, SEEK_SET);
		fread(&Stats, sizeof(Stats), 1, fp);
		fread(&cItemClass, sizeof(cItemClass), 1, fp);
		fread(&cItemSlot, sizeof(cItemSlot), 1, fp);
		fclose(fp);
		if (ItemCategoryChecking(cItemSlot, HavingItem(_iSelect)) == true)
		{
			return;
		}
		return;
	}

	



}

bool cInventory::ItemCategoryChecking(char * _InventroyItem, char * _HavingItem)
{
	if (!strcmp(_InventroyItem, _HavingItem))
		return true;

	return false;
}

#include "cInventory.h"
#include "include.h"
#include "cGameObject.h"

cInventory::cInventory()
{
}


cInventory::~cInventory()
{
}

void cInventory::SaveHavingItem(cInventory* _Item)
{
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "../Data/HavingItem", "ab");
	if (err == 0)
	{
		//fwrite(&dynamic_cast<cItem*>(_cItem), sizeof(_cItem->Stats), 1, fp);
		fwrite(stats)
		fwrite(&_cItem->cItemClass, sizeof(_cItem->cItemClass), 1, fp);
		fwrite(&_cItem->cItemSlot, sizeof(_cItem->cItemSlot), 1, fp);
	}

}

void cInventory::LoadHavingItem()
{
}

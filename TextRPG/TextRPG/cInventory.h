#pragma once
#include "cGameObject.h"
#include "cItem.h"
class cPlayer;


class cInventory :public cItem
{
public:
	cGameObject* Player;
	cItem* Item;
	char cItemCategory[32];

public:
	cInventory();
	~cInventory();
public:
	void Init();
	void Draw();
	void Update();
	void Release();

public:
	void Receive(cGameObject * _Player);
	void ItemCategory();

public:
	char* HavingItem(int _iSelectNumber);
	void SaveHavingItem(cItem* _Item);
	void LoadHavingItem(int _iSelect);
public:
	bool ItemCategoryChecking(char* _InventroyItem, char* _HavingItem);
};


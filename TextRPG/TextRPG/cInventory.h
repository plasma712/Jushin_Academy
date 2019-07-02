#pragma once
#include "cItem.h"
class cPlayer;


class cInventory :public cItem
{
public:
	cPlayer* Player;

public:
	cInventory();
	~cInventory();
public:
	void HavingItem();
	void SaveHavingItem(cInventory* _Item);
	void LoadHavingItem();
public:
};


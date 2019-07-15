#pragma once
#include "cItem.h"
#include "cInventory.h"

class cShop
{
public:
	cGameObject* Player;
	cItem*   Item;
	cInventory* Inventory;
public:
	cShop();
	~cShop();
public:
	void Init();
	void Draw();
	void Update();
	void Release();

public:
	cGameObject* ExtractPlayer();
	void Receive(cGameObject* _Player);

	cItem* ExtractItem();
	void Receive(cItem* _Item);
public:

	void Buy();
	void Sell();
	void ItemScroll();
};


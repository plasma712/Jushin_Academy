#pragma once

class cField;
class cShop;
class cGameObject;

class cMainGame
{
public:
	cGameObject* Player;
	cGameObject* Monster;
	cField* Field;
	cShop* Shop;
public:
	cMainGame();
	virtual ~cMainGame();

public:
	void NewGame();
	void Lobby();

	void Init();

	cGameObject* ExtractPlayer();			  // �÷��̾� �ּ� ����
	void Receive(cGameObject* _Player);	      // �÷��̾� �ּ� �ޱ�
public:
#pragma region �ؽ�Ʈ �ѷ��ִ� �Լ���.
	void TitleCout();
	void PlayerSelectCout();

#pragma endregion;





};


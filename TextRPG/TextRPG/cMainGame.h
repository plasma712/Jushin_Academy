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

	cGameObject* ExtractPlayer();			  // 플레이어 주소 추출
	void Receive(cGameObject* _Player);	      // 플레이어 주소 받기
public:
#pragma region 텍스트 뿌려주는 함수들.
	void TitleCout();
	void PlayerSelectCout();

#pragma endregion;





};


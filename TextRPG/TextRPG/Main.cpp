#include "include.h"
#include "cMainGame.h"

void main()
{
	cMainGame MainGame;

	MainGame.NewGame();

	system("pause");
	system("cls");
	MainGame.Lobby();
	//MainGame.Init();
	return;
}
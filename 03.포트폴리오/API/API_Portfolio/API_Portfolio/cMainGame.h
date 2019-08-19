#pragma once


class cGameObject;
class cMainGame
{
private:
	HDC m_hdc;

public:
	cMainGame();
	~cMainGame();

public:
	void Init();
	void Update();
	void Draw();
	void Release();
	///////////////////////////////////////////////

	int					m_iFPS;
	void				SetFPS(int FPS);

	HDC	hBackBuffer;
};


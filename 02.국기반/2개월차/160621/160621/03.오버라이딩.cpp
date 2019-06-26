#include <iostream>

using namespace std;


class cFigure
{
private:

public:
	void Draw()
	{
		cout << "그려라" << endl;
	}

};

class cTriangle : public cFigure
{
public:
	// 오버라이딩 
	// 클래스 문법으로 부모와 같은 함수를 재정의하는 행위.
	void Draw()
	{
		cout << "삼각형" << endl;
		cFigure::Draw();
	}
};

class cRectangle : public cFigure
{
public:
	void Draw() 
	{
		cout << "사각형" << endl;
		cFigure::Draw();
	}
};

/*
				오버로딩		vs		오버라이딩
	--------------------------------------------------------
	문법		함수					클래스
	함수이름	같아야한다.				같아야한다.
	인자		달라야한다.				같아야한다.
	반환		상관 X					같아야한다.
*/	


void main()
{
	// ##1. 다형성
	// 서로 다른 객체가 같은 메시지로 다른행위를 취한다.
	// 다형성을 하기 위한 전제조건은 상속 + 오버라이딩이다.
	cTriangle Tri;
	cRectangle Rect;

	Tri.Draw();
	Rect.Draw();
	return;
}
#include <iostream>
using namespace std;

class cFigure
{
public:
	virtual void Draw() = 0;	// 순수 가상 함수
};

class cTriangle : public cFigure
{
public :
	// 순수 가상 함수는 자식클래스에게 오버라이딩하도록 유도하는 문법이다.
	virtual void Draw() override
	{
		cout << "삼각형" << endl;
	}
};

class cRectangle : public cFigure
{
public:
	virtual void Draw() override
	{
		cout << "사각형" << endl;
	}
};

void main()

{	
	// 추상 클래스는 객체화 할 수 없다.
	// cFigure obj; // error;

	// ##1. 다형성

	// 추상클래스는 객체화 할 수 는 없지만 포인터나 래퍼런스 타입으로는 사용 가능하다.
	cFigure* pFigure = new cTriangle;
	pFigure->Draw();
	delete pFigure;

	pFigure = new cRectangle;
	pFigure->Draw();
	delete pFigure;


	return;
}
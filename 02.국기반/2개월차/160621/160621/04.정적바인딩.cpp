#include <iostream>

using namespace std;


// ##1. 객체 포인터

class cFigure
{
private:

public:
	//virtual void Draw()
	void Draw()
	{
		cout << "그려라" << endl;
	}

};

class cTriangle : public cFigure
{
public:
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


void main()
{

	cTriangle Tri;
	cRectangle Rect;

	// 객체 포인터 특징
	// 부모타입 포인터는 자식객체에의 주소를 담을 수 있다.

	cFigure* ptr1 = &Tri;
	cFigure* ptr2 = &Rect;

	// 정적 바인딩 때문에 Draw함수가 cFigure의 것으로 컴파일러는 해석하고 있다.
	ptr1->Draw();
	ptr2->Draw();

	return;
}
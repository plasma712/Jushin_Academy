#include <iostream>

using namespace std;


// ##1. ��ü ������

class cFigure
{
private:

public:
	//virtual void Draw()
	void Draw()
	{
		cout << "�׷���" << endl;
	}

};

class cTriangle : public cFigure
{
public:
	void Draw()
	{
		cout << "�ﰢ��" << endl;
		cFigure::Draw();
	}
};

class cRectangle : public cFigure
{
public:

	void Draw()
	{
		cout << "�簢��" << endl;
		cFigure::Draw();
	}
};


void main()
{

	cTriangle Tri;
	cRectangle Rect;

	// ��ü ������ Ư¡
	// �θ�Ÿ�� �����ʹ� �ڽİ�ü���� �ּҸ� ���� �� �ִ�.

	cFigure* ptr1 = &Tri;
	cFigure* ptr2 = &Rect;

	// ���� ���ε� ������ Draw�Լ��� cFigure�� ������ �����Ϸ��� �ؼ��ϰ� �ִ�.
	ptr1->Draw();
	ptr2->Draw();

	return;
}
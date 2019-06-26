#include <iostream>
using namespace std;

class cFigure
{
public:
	virtual void Draw() = 0;	// ���� ���� �Լ�
};

class cTriangle : public cFigure
{
public :
	// ���� ���� �Լ��� �ڽ�Ŭ�������� �������̵��ϵ��� �����ϴ� �����̴�.
	virtual void Draw() override
	{
		cout << "�ﰢ��" << endl;
	}
};

class cRectangle : public cFigure
{
public:
	virtual void Draw() override
	{
		cout << "�簢��" << endl;
	}
};

void main()

{	
	// �߻� Ŭ������ ��üȭ �� �� ����.
	// cFigure obj; // error;

	// ##1. ������

	// �߻�Ŭ������ ��üȭ �� �� �� ������ �����ͳ� ���۷��� Ÿ�����δ� ��� �����ϴ�.
	cFigure* pFigure = new cTriangle;
	pFigure->Draw();
	delete pFigure;

	pFigure = new cRectangle;
	pFigure->Draw();
	delete pFigure;


	return;
}
#include <iostream>

using namespace std;


class cFigure
{
private:

public:
	void Draw()
	{
		cout << "�׷���" << endl;
	}

};

class cTriangle : public cFigure
{
public:
	// �������̵� 
	// Ŭ���� �������� �θ�� ���� �Լ��� �������ϴ� ����.
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

/*
				�����ε�		vs		�������̵�
	--------------------------------------------------------
	����		�Լ�					Ŭ����
	�Լ��̸�	���ƾ��Ѵ�.				���ƾ��Ѵ�.
	����		�޶���Ѵ�.				���ƾ��Ѵ�.
	��ȯ		��� X					���ƾ��Ѵ�.
*/	


void main()
{
	// ##1. ������
	// ���� �ٸ� ��ü�� ���� �޽����� �ٸ������� ���Ѵ�.
	// �������� �ϱ� ���� ���������� ��� + �������̵��̴�.
	cTriangle Tri;
	cRectangle Rect;

	Tri.Draw();
	Rect.Draw();
	return;
}
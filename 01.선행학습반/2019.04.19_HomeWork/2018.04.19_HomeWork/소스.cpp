// �Ϲݻﰢ��, ������ �ﰢ��


#include <iostream>
using namespace std;

void NormalTri(int _iHeight)
{
	for (int i = _iHeight; i > 0; i--)
	{
		for (int k = i; k <= _iHeight; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
void ReverseTri(int _iHeight)
{
	for (int i = 0; i < _iHeight; i++)
	{
		for (int k = i; k < _iHeight; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void main()
{
	while (true)
	{
		system("cls");
		int iSelectNum = 0;
		cout << "���Ͻô� ���ڸ� �Է� ���ּ���.(�Ϲݻﰢ�� : 1 / ���ﰢ�� : 2 / ���� : 3) : ";
		cin >> iSelectNum;
		switch (iSelectNum)
		{
			int iHeight;
		case 1:
			cout << "�ﰢ���� ���̸� �Է����ּ���. : ";
			cin >> iHeight;
			cout << endl;
			NormalTri(iHeight);
			break;
		case 2:
			cout << "�ﰢ���� ���̸� �Է����ּ���. : ";
			cin >> iHeight;
			cout << endl;
			ReverseTri(iHeight);
			break;
		default:
			goto END;
			break;
		}
		cout << endl;
		system("pause");
	}
END:
	cout << "����" << endl;
	return;
}
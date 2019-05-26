/*
	// ���� 1.
	// 2���� �迭�� �̿��Ͽ� ������ ���� ȸ�����Ѷ�

	1 2 3						7 4 1
	4 5 6	�ð���� 90�� ->    8 5 2
	7 8 9						9 6 3

	// ���� 2.
	// ���Ǳ�, Ȧ¦, ������������ �Լ��� �����ؿͶ�.

*/

#include <iostream> 

using namespace std;

namespace homeWork1
{
	int iArray2D[3][3] = {};


	void BaseArray2D()
	{
		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < 3; i++)
			{
				iArray2D[k][i] = k * 3 + i + 1;
			}
		}
	}

	void CoutArray2D()
	{
		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < 3; i++)
			{
				cout << iArray2D[k][i] << "\t";
			}
			cout << endl;
		}
	}

	void Array2D_RotationLeft()
	{
		int iCopyArray2D[3][3] = {};

		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < 3; i++)
			{
				iCopyArray2D[k][i] = iArray2D[k][i];
			}
		}

		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (k == 0)
				{
					iArray2D[k][i] = iCopyArray2D[i][k + 2];
				}
				else if (k == 1)
				{
					iArray2D[k][i] = iCopyArray2D[i][k];
				}
				else
				{
					iArray2D[k][i] = iCopyArray2D[i][k - 2];
				}
			}
		}

	}

	void Array2D_RotationRight()
	{
		int iCopyArray2D[3][3] = {};

		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < 3; i++)
			{
				iCopyArray2D[k][i] = iArray2D[k][i];
			}
		}


		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (k == 0)
				{
					iArray2D[i][k] = iCopyArray2D[k + 2][i];
				}
				else if (k == 1)
				{
					iArray2D[i][k] = iCopyArray2D[k][i];
				}
				else
				{
					iArray2D[i][k] = iCopyArray2D[k - 2][i];
				}
			}
		}


	}

	void Array2D()
	{
		bool TF = true;
		BaseArray2D();
		CoutArray2D();

		
		while (TF)
		{
			system("cls");
			int iInputNumber = 0;
			CoutArray2D();
			cout << "[ȸ�� �ϱ�] 1. ����  2.������  0.����" << endl;
			cout << "��ȣ�� �Է��Ͻÿ� : ";
			cin >> iInputNumber;

			system("cls");

			if (iInputNumber == 0)
				break;

			switch (iInputNumber)
			{
			case 1:
				Array2D_RotationLeft();
				break;
			case 2:
				Array2D_RotationRight();
			default:
				break;
			}
			cout << "ȸ�� ��� " << endl;
			CoutArray2D();
			system("pause");
			system("cls");
		}
	}

}


void main()
{
	homeWork1::Array2D();
	return;
}
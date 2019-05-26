/*
	// 과제 1.
	// 2차원 배열을 이용하여 다음과 같이 회전시켜라

	1 2 3						7 4 1
	4 5 6	시계방향 90도 ->    8 5 2
	7 8 9						9 6 3

	// 과제 2.
	// 자판기, 홀짝, 가위바위보를 함수로 구현해와라.

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
			cout << "[회전 하기] 1. 왼쪽  2.오른쪽  0.종료" << endl;
			cout << "번호를 입력하시오 : ";
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
			cout << "회전 결과 " << endl;
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
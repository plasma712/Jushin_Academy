#include <iostream> 

using namespace std;

void main()
{
	// ##1. �ݺ���(while��, do~while��, for��)
	// �ߺ��� ������ �ݺ��ϰ����� ��, ���̴� ����.

	// ##2. while��

	//while (����)
	//{
	//	���� ������ ���� �� ���� �ݺ��Ǵ� ����.
	//}

	//int iCount = 0;
	//while (true)
	//{
	//	if (iCount>=3)
	//		break; // ���� ����� {} Ż��.
	//	cout << "Hello" << endl;
	//	iCount++;
	//}

	// int iInput = 0;
	// cin >> iInput;

	// while (true)
	// {
	// 	cout << "�Է� : ";
	// 	cin >> iInput;
	// 
	// 	if (0 > iInput)
	// 		break;
	// 
	// 	if (0 != iInput % 2)
	// 	{
	// 		continue;
	// 	}
	// 
	// 	cout << "¦��: " << iInput << endl;
	// }

	// ##3. do ~ while��

	//do
	//{
	//	// 1. do���� ����
	//	// 3. while�� ������ ���� �� do �ݺ�.
	//} while (2.���Ǻ�);

	int iInput = 0;

	// while (iInput)
	// {
	// 	cout << "�Է�: ";
	// 	cin >> iInput;
	// 
	// 	if (0 > iInput)
	// 	{
	// 		break;
	// 	}
	// }

	// do ~ while�� �ٲٸ�

	//do
	//{
	//	cout << "�Է� : ";
	//	cin >> iInput;
	//} while (0 <= iInput);

	// ���� 1. ������ �� 2���� while ���� �̿��Ͽ� ���.
	int iNum = 1;
	while (true)
	{
		if (iNum >= 10)
			break;
		cout << "2 x " << iNum << " = " << 2 * iNum << endl;
		iNum++;
	}

	// ���� 2. ������ 2�� ~ 9�ܱ��� while�� �̿��Ͽ� ���
	cout << endl;

	int iNum1 = 2, iNum2 = 1;
	while (true)
	{
		while (true)
		{
			if (iNum1 >= 10)
			{
				iNum1 = 2;
				break;
			}
			cout << iNum1 << " X " << iNum2 << " = " << iNum1 * iNum2 << "\t";
			iNum1++;
		}
		iNum2++;
		cout << endl;
		if (iNum2 >= 10)
			break;
	}

	// ���� 3. A�� B�� �Է¹����� 2�� B������ A�� B������ ���

	int iA = 0, iB = 0;
	int iNum3 = 2, iNum4 = 1;

	cout << endl;
	cout << "A , B �Է� : ";
	cin >> iA >> iB;
	while (true)
	{
		while (true)
		{
			if (iNum4 > iB)
				break;
			cout << iNum3 << " X " << iNum4 << " = " << iNum3 * iNum4 << endl;
			iNum4++;
		}
		cout << "--------------------" << endl;
		iNum3++;
		iNum4 = 1;
		if (iNum3 > iA)
			break;
	}

	return;
}
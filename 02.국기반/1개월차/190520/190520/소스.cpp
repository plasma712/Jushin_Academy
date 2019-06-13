#include <iostream> 

using namespace std;

void main()
{
	// ##1. 반복문(while문, do~while문, for문)
	// 중복된 행위를 반복하고자할 때, 쓰이는 문법.

	// ##2. while문

	//while (조건)
	//{
	//	위의 조건이 참일 때 마다 반복되는 구간.
	//}

	//int iCount = 0;
	//while (true)
	//{
	//	if (iCount>=3)
	//		break; // 가장 가까운 {} 탈출.
	//	cout << "Hello" << endl;
	//	iCount++;
	//}

	// int iInput = 0;
	// cin >> iInput;

	// while (true)
	// {
	// 	cout << "입력 : ";
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
	// 	cout << "짝수: " << iInput << endl;
	// }

	// ##3. do ~ while문

	//do
	//{
	//	// 1. do먼저 실행
	//	// 3. while의 조건이 참일 때 do 반복.
	//} while (2.조건비교);

	int iInput = 0;

	// while (iInput)
	// {
	// 	cout << "입력: ";
	// 	cin >> iInput;
	// 
	// 	if (0 > iInput)
	// 	{
	// 		break;
	// 	}
	// }

	// do ~ while로 바꾸면

	//do
	//{
	//	cout << "입력 : ";
	//	cin >> iInput;
	//} while (0 <= iInput);

	// 문제 1. 구구단 중 2단을 while 문을 이용하여 출력.
	int iNum = 1;
	while (true)
	{
		if (iNum >= 10)
			break;
		cout << "2 x " << iNum << " = " << 2 * iNum << endl;
		iNum++;
	}

	// 문제 2. 구구단 2단 ~ 9단까지 while문 이용하여 출력
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

	// 문제 3. A와 B를 입력받으면 2단 B곱부터 A단 B곱까지 출력

	int iA = 0, iB = 0;
	int iNum3 = 2, iNum4 = 1;

	cout << endl;
	cout << "A , B 입력 : ";
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
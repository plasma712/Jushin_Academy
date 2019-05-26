#include <iostream>
using namespace std;

void main()
{
	//int iA = 0;
	//int i = 0;
	////While , for문의 차이는 반복횟수가 정해졌는가 아닌가에 따라 차이를 둘 수 있다.
	//for (; ;)
	//{
	//	cout << "d " << endl;
	//	if (i > 10)
	//		break;
	//	iA += i;
	//}
	//cout << iA << endl;

	for (int i = 1; i < 10;  i++)
	{
		for (int k = 2; k < 10; k++)
		{
			cout << k << " x " << i << " = " << k * i << "\t";
		}
		cout << endl;
	}	
}
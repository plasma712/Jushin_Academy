#include <iostream>
using namespace std;

void main()
{
	//int iA = 0;
	//int i = 0;
	////While , for���� ���̴� �ݺ�Ƚ���� �������°� �ƴѰ��� ���� ���̸� �� �� �ִ�.
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
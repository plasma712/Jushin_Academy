#include <iostream>

using namespace std;

// ##1. ���Ǻ�_ ������
// #if ~ #endif
// #ifdef ~ #endif
// #ifndef ~ #endif

#define WIN		1
#define MAC		2
#define	LINUX	3
#define CUR_OS	WIN


void main()
{
	// ##2. #if ~ #endif
	// #if ���� ���� ���̸� ������ ���, �����̸� ������ ��󿡼� ����.

#if 1
	cout << "Hello World" << endl;
#endif

	//////////////////////////////


#if (CUR_OR == WIN)
	cout << "WINDOW ����" << endl;
#elif(CUR_OR == MAC)
	cout << "MAC ����" << endl;
#end
	cout << "LINUX ����" << endl;
#endif

	system("pause");
	return;
}
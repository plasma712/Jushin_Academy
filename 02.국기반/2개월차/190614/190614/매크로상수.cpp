#include <iostream> 
using namespace std;

// ##1. ��ũ�� : #define
// ��ó������ �������� �ܼ�ġȯ�� �ǹ��Ѵ�.

// ##2. ��ũ�λ��
#define PI 3.14f
//#define PI 3.14f; �ϰ�� ; �� ���簡 �Ǿ� �ٷ� ����.


void main()
{
	// ##2. ��ũ�λ��
	cout << PI << endl;	 // cout << 3.14f << endl;�� ���� �ǹ�
	cout << EOF << endl; // cout << -1 << endl; �� ���� �ǹ�.

	cout << sizeof(PI) << endl;  // sizeof(3.14f);
	cout << sizeof(EOF) << endl; // sizeof(-1);
	system("pause");
	return;
}
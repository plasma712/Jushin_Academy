#include <iostream>

using namespace std;

// ##1. ����� ���� �ڷ���
// typedef : ������ �ڷ����� ����ڰ� ���ο� �̸����� �����ϴ� �ڷ���.

typedef int MY_INTEGER; // �������� ���鿡�� ���� ����.(int -> short double �� ���� Ÿ���� �����ϱ� ����.)

typedef struct tagGrade
{

}Grade, *Grade;


void main()
{
	MY_INTEGER a = 100;
	MY_INTEGER b = 200;

	cout << a << endl;
	return;
}
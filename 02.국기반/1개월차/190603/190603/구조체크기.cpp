#include <iostream>
using namespace std;

struct tagTest1
{
	short a; 
	int b;
	char c;
	double d;
};

struct tagTest2
{
	short a;
	char b;
	int c;
	double d;
};

struct tagTest3
{
	int a;
	char b;
	int c;
	tagTest2 d;
};

struct tagTest4
{
	int a;
	char b;
	int c;
	//tagTest4 d;
	tagTest4* d;	// �ڱ��ڽ��� ����� ���� ������ ũ�Ⱑ �������ִ� �����͸� �̿��ؾ��Ѵ�.
};

void main()
{
	// ##1. ����ü�� ũ��.
	// ���(�⺻�ڷ���) �� ���� ū �޸𸮸� �������� ��Ƴ�����.
	// 32��Ʈ ȯ�濡���� 4����Ʈ�� ��� ó��, 64��Ʈ ȯ�濡���� 8����Ʈ�� ��� ó��
	cout << sizeof(tagTest1) << endl;
	cout << sizeof(tagTest2) << endl;
	cout << sizeof(tagTest3) << endl;

	return;
}
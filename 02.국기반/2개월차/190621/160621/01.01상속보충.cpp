#include<iostream>

using namespace std;

class cBase
{
private:
public:
	cBase()
	{
		cout << "�θ� ������" << endl;
	}
	~cBase()
	{
		cout << "�θ� �Ҹ���" << endl;
	}
};

class cChild
{
private:
public:
	cChild()
	{
		cout << "�ڽ� ������" << endl;
	}
	~cChild()
	{
		cout << "�ڽ� �Ҹ���" << endl;
	}
};

void main()
{
	//*****
	// 

	cChild obj;
	return;
}
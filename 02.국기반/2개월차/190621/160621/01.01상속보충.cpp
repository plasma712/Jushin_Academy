#include<iostream>

using namespace std;

class cBase
{
private:
public:
	cBase()
	{
		cout << "부모 생성자" << endl;
	}
	~cBase()
	{
		cout << "부모 소멸자" << endl;
	}
};

class cChild
{
private:
public:
	cChild()
	{
		cout << "자식 생성자" << endl;
	}
	~cChild()
	{
		cout << "자식 소멸자" << endl;
	}
};

void main()
{
	//*****
	// 

	cChild obj;
	return;
}
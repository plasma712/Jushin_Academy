#include <iostream>

using namespace std;

// 객체지향 프로그래밍(OOP , Object Oriented Programming)

// ##1. 얕은복사(Shallow copy)와 깊은복사(Deep copy)

class cObj
{
private:
	char* m_phone;

public:
	cObj(const char* pName)
	{
		int iLength = strlen(pName);
		m_phone = new char[iLength + 1];

		strcpy_s(m_phone, iLength + 1, pName);
	}

	// cObj(const cObj& _obj)
	// {
	// 	// 얕은복사
	// 	// 실제 복사해야될 대상은 "NeoPeople"이지만
	// 	// 단순 주소 번지만 복사하고 있다.
	// 	// 따라서, 원본과 사본이 같은 메모리 공간을 바라보고 있기 때문에
	// 	// 추후 댕글링 포인터 문제가 발생한다.
	// 	m_phone = _obj.m_phone;
	// }

	// 깊은복사

	cObj(const cObj& _obj)
	{
		int iLength = strlen(_obj.m_phone);

		m_phone = new char[iLength + 1];
		// 깊은복사는 실제 값을 복사한다.
		strcpy_s(m_phone, iLength + 1, _obj.m_phone);
	}

	~cObj()
	{
		delete[] m_phone;
	}
public:
	void WhatIsYourName()
	{
		cout << m_phone << endl;
	}
};

void main()
{

	cObj objA("NeoPeople");
	objA.WhatIsYourName();

	cObj objB = objA;
	objB.WhatIsYourName();
	return;
}
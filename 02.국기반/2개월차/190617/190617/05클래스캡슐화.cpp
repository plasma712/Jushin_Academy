#include <iostream>

using namespace std;

// ##1. 캡슐화 (encapsulation)
// 클랫의 데이터(멤버변수)와 기능(멤버함수)을 하나로 묶어 
// 구성요소(객체의 동작 방식)를 외부로부터 숨긴다.

class c콧물약
{
public:
	void 복용()
	{
		cout << "콧물이 맞습니다." << endl;
	}

};

class c재채기약
{
public:
	void 복용()
	{
		cout << "재채기가 맞습니다." << endl;
	}
};

class c코막힘약
{
public:
	void 복용()
	{
		cout << "코막힘이 맞습니다." << endl;
	}
};

class cContac600
{
public :
	void 복용()
	{
		cap1.복용();
		cap2.복용();
		cap3.복용();

	}
private:
	c콧물약 cap1;
	c재채기약 cap2;
	c코막힘약 cap3;
};


void main()
{
	// c콧물약 cap1;
	// c재채기약 cap2;
	// c코막힘약 cap3;
	// 
	// cap1.복용();
	// cap2.복용();
	// cap3.복용();

	cContac600 cap;
	cap.복용();
	

	system("pause");
	return;
}
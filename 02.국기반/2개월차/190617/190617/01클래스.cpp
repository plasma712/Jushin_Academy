#include <iostream> 

using namespace std;

// ##1. 클래스
// 객체를 표현한 사용자정의 자료형. C++ 부터 등장한 개념.
// 객체의 추상화다.

class cCustomer
{
public:
	// 멤버 함수
	void OrderProduct()
	{
		cout << "물건을 주문합니다." << endl;
	}

	void TakeProduct()
	{
		cout << "물건을 건네 받습니다." << endl;
	}

private:
	int m_iMoney;	// 멤버 변수
};


void main()
{
	// ##2. 객체(Object)
	// 클래스의 구체화. 실제 메모리에 등록됨. (=instance)

	cCustomer object;

	object.OrderProduct();
	object.TakeProduct();


	system("pause");
	return;
}
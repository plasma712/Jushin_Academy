#include <iostream>

using namespace std;

// ##1. 구조체를 통해서 여러 데이터를 한번에 주고 받을 수 있다.

struct tagMyVector
{
	float fx;
	float fy;
	float fz;
};

void Func(tagMyVector vec)
{
	cout << "X : " << vec.fx << endl;
	cout << "Y : " << vec.fy << endl;
	cout << "Z : " << vec.fz << endl;

}

void main()
{
	// tagMyVector tVector = { 1.f,2.f,3.f };

	// tVector가 갖고 있는 모든 멤버의 값이 vec의 멤버로 모두 복사된다.
	// Func(tVector);

	// ##1. 구조체는 연속된 메모리를 갖는다.

	// cout << &(tVector.fx) << endl;
	// cout << &(tVector.fy) << endl;
	// cout << &(tVector.fz) << endl;

	// ##2. 구조체 포인터_1

	// tagMyVector tVector = {};

	// tVector는 엄연한 tagMyVector타입이지 tagMyVector*가 아니다.
	// 구조체 이름은 포인터가 아니다.
	// cout << tVector << endl; // error
	
	// 단, 구조체 변수의 주소는 곧 첫 멤버의 주소와 같다.
	// 구조체 포인터는 현재 구조체의 시작 주소이다.
	// cout << &tVector << endl;
	// cout << &(tVector.fx) << endl;

	// ##3. 구조체 포인터_2

	tagMyVector tVector = {};

	// 현재 ptr은 tVector의 시작주소를 갖고있다.
	// 이 시작주소를 통해서 모든 멤버에 접근 및 제어할 수 있다.

	tagMyVector* ptr = &tVector;

	// 구조체 포인터의 간접참조.
	// (*ptr).fx = 100.f;
	// (*ptr).fy = 200.f;
	// (*ptr).fz = 300.f;

	// 구조체 포인터의 간접참조.(정석)
	// ->화살표 연산자를 사용한다.
	ptr->fx = 100.f;
	ptr->fy = 200.f;
	ptr->fz = 300.f;

	cout << tVector.fx << " , " << tVector.fy << " , " << tVector.fz;


	return;
}
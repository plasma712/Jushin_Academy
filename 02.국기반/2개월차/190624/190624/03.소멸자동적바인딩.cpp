#include <iostream>

using namespace std;

class cGameObject
{
public:
	virtual ~cGameObject()
	{
		cout << "부모 소멸자" << endl;
	}
};

class cPlayer : public cGameObject
{
public:
	virtual ~cPlayer() // 오버라이딩이라고 부를 수는 없음.( 부모 소멸자랑 자식 소멸자의 이름이 다름.)
	{
		cout << "자식 소멸자" << endl;
	}
};

class cMonster : public cGameObject
{

};

void main()
{
	cGameObject* pPlayer = new cPlayer;
	
	// 소멸자 호출도 동적바인딩이 필요하다. -> 가상 소멸자
	delete pPlayer;

}
#pragma once
class cBoy
{
private:
	int m_iWeight = 80;
	int m_iHeight = 183;

	// friend 키워드
	// 자신의 private 멤버에 대해서 
	// 접근권한을 부여하는 키워드
	friend class cGirl;
	
	// 특정 대상(함수)에게만 friend 선언
	// friend void cGirl::MyBoyFriendInfo(cBoy* pBoy);
public:
	cBoy();
	~cBoy();
};


#pragma once
class cBoy
{
private:
	int m_iWeight = 80;
	int m_iHeight = 183;

	// friend Ű����
	// �ڽ��� private ����� ���ؼ� 
	// ���ٱ����� �ο��ϴ� Ű����
	friend class cGirl;
	
	// Ư�� ���(�Լ�)���Ը� friend ����
	// friend void cGirl::MyBoyFriendInfo(cBoy* pBoy);
public:
	cBoy();
	~cBoy();
};


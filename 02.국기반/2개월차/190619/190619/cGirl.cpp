#include "cGirl.h"
#include "cBoy.h"


void cGirl::MyBoyFriendInfo(cBoy * pBoy)
{
	cout << "His Weight : " << pBoy->m_iWeight << endl;
	cout << "His Height : " << pBoy->m_iHeight << endl;
}

void cGirl::Func(cBoy * pBoy)
{
	cout << "His Weight : " << pBoy->m_iWeight << endl;
	cout << "His Height : " << pBoy->m_iHeight << endl;
}

cGirl::cGirl()
{
}


cGirl::~cGirl()
{
}

#include <iostream>

using namespace std;

// ##1. *** Ŭ������ 4�� �Ӽ�
// 1. ����ȭ (hidding Information)
// 2. ĸ��ȭ (encapsulation)
// 3. ��Ӽ� (inheritance)
//	  �ڽ�Ŭ�������� ����� ��ҵ��� �θ� Ŭ������ �����ش�. �ڵ� ���� �ش�ȭ.
//	  �θ�Ŭ������ �ڽ�Ŭ�������� �߻����� ���簡 �ȴ�.

// 4. ������ (polymorphism)
//	  ���� ��ü�� �ϳ��� �޽����� ���� ���� �ٸ� ���¸� ���ϴ� ��.
//    ���α׷��� ������ �ش�ȭ

// ##2. ����ȭ (hidding Information)
// ��� ��� private���� �ܺο��� ������ ���´�. ������ ��ȣ.

class cPlayer
{
public :
	int GetAttack()	// Get�Լ�. (���е� ������ �б� ����)
	{
		return m_iAtt;
	}

public:
	void SetDamaged(int _iAtt)	//Set�Լ�. (���е� ������ �������)
	{
		m_iHp -= _iAtt;
	}

private:
	int m_iAtt;
	int m_iHp;
	int m_iMaxHp;

};

void main()
{

	system("pause");
	return;
}
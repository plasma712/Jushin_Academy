#include <iostream>

using namespace std;

// ##1. ����ü (structure)
// �ڷ��� ������ ������ �ڷ��� (����� ���� �ڷ���)

// ����ü ����
/*(�±״� ����ü ������ �� ��κ� ����. ������ ���)*/

// �ڷ��� ���� X ��� -> �ڵ忡 ����.
struct tagGrade
{
	char szName[32];
	int iKorean;
	int iEnglish;
	int iMath;
	int iTotal;
	float fAverage;
};

struct tagPoint
{
	int ix;
	int iy;
};

void main()
{
	// ##2. ����ü ���� ����
	// tagGrade tGrade1; // ��� ��� �����Ⱚ���� �ʱ�ȭ.
	// tagGrade tGrade2 = {"ȫ�浿",90,80,70,240,80.f}; // ��� ������ ������ ������ �ʱ�ȭ.
	// tagGrade tGrade3 = { "ȫ�浿",90,80 }; //������ ��� 0 �ʱ�ȭ
	// tagGrade tGrade4 = {}; // ��� ��� 0 �ʱ�ȭ.

	// ##3. ����ü ��� ����
	tagGrade tGrade = { "ȫ�浿",90,80,70,240,80.f };

	// .(dot)�����ڸ� ����Ѵ�.
	// �ڷ����̱� ������ ���ÿ� �з�

	// cout << "�̸� : " << tGrade.szName << endl;
	// cout << "���� ���� : " << tGrade.iKorean << endl;
	// cout << "���� ���� : " << tGrade.iEnglish << endl;
	// cout << "���� ���� : " << tGrade.iMath << endl;
	// cout << "���� : " << tGrade.iTotal << endl;
	// cout << "��� : " << tGrade.fAverage << endl;

	return;
}
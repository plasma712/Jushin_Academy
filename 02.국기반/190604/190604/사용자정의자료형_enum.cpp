#include <iostream> 

using namespace std;

// ##1. ����ü (enumeration)
// ���� ǥ���� ���̴� ����� ���ؼ� �ڷ���ȭ ��Ű�� ����� ���� �ڷ���

// ����ü ����
enum MONSTER_STATE
{
	ATTACK,DEFENCE,MOVE,JUMP
};

enum DRINK_ID
{
	COKE,CIDER,FANTA,HOTSIX,DRINK_MAX
};

void main()
{
	// MONSTER_STATE eState = ATTACK; // ����ü ������ ������ {} �� ������ ���� ���� �� �ִ�.
	// MONSTER_STATE eState =2; //error
	
	// switch (eState)	// ����ü ������ ������ �ν��Ѵ�.
	// {
	// case ATTACK:
	// 	cout << "���� ����" << endl;
	// 	break;
	// case DEFENCE:
	// 	cout << "��� ����" << endl;
	// 	break;
	// case MOVE:
	// 	cout << "�̵� ����" << endl;
	// 	break;
	// default:
	// 	break;
	// }

	// ##3. ����ü ����
	// int iDrinkArr[DRINK_MAX] = { 100,200,300,400 };
	// 
	// cout << "�ݶ� : " << iDrinkArr[COKE] << endl;
	// cout << "���̴� : " << iDrinkArr[CIDER] << endl;
	// cout << "ȯŸ : " << iDrinkArr[FANTA] << endl;
	// cout << "�ֽĽ� : " << iDrinkArr[HOTSIX] << endl;


	// ##4. ���� C�������� ����ü�� int�� ���������� C++�� ���ο� �ڷ������� �ν�
	// int a = ATTACK; // ATTACK�� ���������� ����̹Ƿ� INT ������ ���� ����
	// MONSTER_STATE eState = 2; // error, 2�� int Ÿ���̹Ƿ� �Ұ���; (C�������� ����)

	// ������ �ν��Ͽ� 4����Ʈ
	cout << sizeof(MONSTER_STATE) << endl;
	return;
}
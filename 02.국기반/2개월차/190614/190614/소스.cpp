#pragma once	// ����ũ�μ���Ʈ�翡�� �����ϴ� ����ߺ� ����

#ifndef __VendingMachine_H__	 // �ߺ����������. ȣȯ���� ���ؼ� �̿�.
#include <iostream>

using namespace std;

#define CLIENT

void main()
{
	// ##1. ifdef ~ #endif
	// �ش� ��ũ�ΰ� ���ǵǾ� �ִٸ� ������ ����, �ƴ϶�� ������ ����
	// #elif�� ����� �� ����. ������ �� �ƴϸ� ��

	// #ifdef CLIENT
	// 	cout << "Ŭ���̾�Ʈ ����" << endl;
	// #else
	// 	cout << "���� ����" << endl;
	// #endif

	// ##2. #ifdef ~ #endif
	// �ش� ��ũ�ΰ� ���ǵǾ� ���� ������ ������ ����. ���ǵǾ� ������ ������ ����.

#ifndef CLIENT
	cout << "���� �̿�" << endl;
#else
	cout << "Ŭ���̾�Ʈ ����" << endl;
#endif


	system("pause");
	return;
}
#define __VendingMachine_H__
#endif // !__VendingMachine_H__
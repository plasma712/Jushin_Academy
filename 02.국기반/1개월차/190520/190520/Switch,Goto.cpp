#include <iostream>

using namespace std;

void main()
{
	// ##1. switch��

	// int iSwitch = 0;
	// 
	// cout << "1��(������) 2��(�����) 3��(�ʷϺ�) " << endl;
	// 
	// cout << "�� �� ����ġ?" << endl;
	// 
	// cin >> iSwitch;
	// 
	// switch (iSwitch) // iSwitch => �����θ� ���� (�Ǽ�Ÿ�� �Ұ���)
	// {
	// case 1: // case ��� :
	// 	cout << "������" << endl;
	// 	break;
	// case 2: // �ߺ��� ��� �Ұ���
	// 	cout << "�����" << endl;
	// 	break; // ���� ����� �Լ�{}�� Ż���ϴ� Ű����
	// case 3:
	// 	cout << "�ʷϺ�" << endl;
	// 	break;
	// 
	// default:
	// 	cout << "1, 2, 3�� �߿� �������ּ���." << endl;
	// 	break;
	// }

	// ##2. goto��

	// ���� ���� ���к��ϰ� �ڵ��� �帧�� �ٲ� �� �ִ� ����.
	// �����ϰ� �Ǹ� ���İ�Ƽ �ڵ尡 �ȴ�. �������� �� ��!
	//
	//cout << "A����" << endl;
	//
	//goto C;
	//cout << "B����" << endl;
	//
	//C:
	//cout << "C����" << endl;
	//

	// ����
	float fAverage = 0.f;

	cin >> fAverage;

	switch (((int)fAverage / 10 == 10) ? (9) : ((int)fAverage / 10))
	{
	case 9:
		cout << "A����" << endl;
		break;
	case 8:
		cout << "B����" << endl;
		break;
	case 7:
		cout << "C����" << endl;
		break;

	default:

		break;
	}


	return;
}
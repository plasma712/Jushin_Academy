#include <iostream>
using namespace std;
/* ���Ǳ�
void main()
{
	// ���Ǳ�
	int iSider = 200, iCoke = 300, iSol = 900;
	int iCash = 0;
	int iSelect = 0;
	while (true)
	{
		cout << "�ݾ��� �Է� �Ͻÿ� ! : " << endl;
		cin >> iCash;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(64, '\n');

			cout << "���" << endl;
		}
		if (0 >= iCash)
			continue;

		break;
	}
	while (true)
	{
		//system �Լ�
		system("cls");
		cout << "1.�ݶ� (300��), 2.���̴�(200��), 3.���Ǵ�(900��), 4.����" << endl;

		cin >> iSelect;

		if (4 == iSelect)
			break;

		switch (iSelect)
		{
		case 1:
			if (iCoke > iCash)
			{
				cout << "��������" << endl;
				break;
			}
			iCash -= iCoke;
			cout << "�����մϴ�. ���� �ܾ��� :  " << iCash << " �Դϴ�." << endl;
			break;
		case 2:
			if (iSider > iCash)
			{
				cout << "��������" << endl;
				break;
			}
			iCash -= iSider;
			cout << "�����մϴ�. ���� �ܾ��� :  " << iCash << " �Դϴ�." << endl;

			break;
		case 3:
			if (iSol > iCash)
			{
				cout << "��������" << endl;
				break;
			}
			iCash -= iSol;
			cout << "�����մϴ�. ���� �ܾ��� :  " << iCash << " �Դϴ�." << endl;

			break;
		default:
			break;
		}
		system("pause");
	}
	cout << "�Ž������� : " << iCash << "�Դϴ�. " << endl;

}
*/

void main()
{
	int iPlayerHp = 100, iPlayerAtt = 5;
	int iMonsterHp = 30, iMonsterAtt = 5;
	int iSelect = 0;

UP:
	cout << "PlayerHp: " << iPlayerHp << endl;
	cout << "iMonsterHp: " << iMonsterHp << endl;
	cout << "1.����, 2.����" << endl;

	cin >> iSelect;

	switch (iSelect)
	{
	case 1:
		iPlayerHp -= iMonsterAtt;
		iMonsterHp -= iPlayerAtt;
		break;
	case 2:
		break;
	default:
		cout << "�߸�����" << endl;
		break;
	}
	if (0 >= iPlayerHp)
	{
		cout << "���..." << endl;
	}
	if (0 >= iMonsterHp)
	{
		cout << "��� ����." << endl;
		goto DOWN;
	}
	goto UP;
DOWN:
}
#include <iostream>

using namespace std;

void main()
{
	// ##1. switch문

	// int iSwitch = 0;
	// 
	// cout << "1번(빨간불) 2번(노란불) 3번(초록불) " << endl;
	// 
	// cout << "몇 번 스위치?" << endl;
	// 
	// cin >> iSwitch;
	// 
	// switch (iSwitch) // iSwitch => 정수로만 가능 (실수타입 불가능)
	// {
	// case 1: // case 상수 :
	// 	cout << "빨간불" << endl;
	// 	break;
	// case 2: // 중복된 상수 불가능
	// 	cout << "노란불" << endl;
	// 	break; // 가장 가까운 함수{}를 탈출하는 키워드
	// case 3:
	// 	cout << "초록불" << endl;
	// 	break;
	// 
	// default:
	// 	cout << "1, 2, 3번 중에 선택해주세요." << endl;
	// 	break;
	// }

	// ##2. goto문

	// 조건 없이 무분별하게 코드의 흐름을 바꿀 수 있는 문법.
	// 남발하게 되면 스파게티 코드가 된다. 남발하지 말 것!
	//
	//cout << "A영역" << endl;
	//
	//goto C;
	//cout << "B영역" << endl;
	//
	//C:
	//cout << "C영역" << endl;
	//

	// 문제
	float fAverage = 0.f;

	cin >> fAverage;

	switch (((int)fAverage / 10 == 10) ? (9) : ((int)fAverage / 10))
	{
	case 9:
		cout << "A학점" << endl;
		break;
	case 8:
		cout << "B학점" << endl;
		break;
	case 7:
		cout << "C학점" << endl;
		break;

	default:

		break;
	}


	return;
}
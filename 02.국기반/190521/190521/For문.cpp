#include <iostream> 

using namespace std;

void main()
{
	// ##1. for문
	// while문 : 얼마나 반복될지 모르는 상황에 적절.
	// for 문 : 반복 횟수가 정해진 상황에 적절.

	// for (1.초기화식 ; 2.조건식 ; 4.증감식)
	// {
	// 	3.조건식 참일 때 반복
	// }


	// for (int i = 0; i < 5; i++)
	// {
	// 	cout << "Hello" << endl;
	// }

	// int i = 0;
	// 
	// while (i<5)
	// {
	// 	cout << "Hello" << endl;
	// 	i++;
	// 
	// }

	int i = 0;

	// 초기화식을 비울 수 있으나 세미콜론 ; 은 반드시 존재해야한다.
	// for (; i < 5; i++)
	// {
	// 	cout << "Hello" << endl;
	// }

	// for문의 모든 식이 모두 비워져있으면 무한루프다.
	// 모두 비워도 세미콜론은 생략되선 안된다.
	// 반복할 코드가 한줄일 경우 {} 생략가능.
	// for (;;)
	// 	cout << "Hello" << endl;

	// ##2. break와 continue

	// if (true) 
	// {
	// 
	// 	continue; // error! 반복문이 존재 할 때 사용가능.
	// 	break;	  // error! switch문이나 반복문이 존재 할 때 사용가능.
	// }

	// 문제 1. 구구단 중 2단을 for문으로 해결

	// for (int i = 1; i < 10; i++)
	// {
	// 	cout << "2 X " << i << " = " << 2 * i << endl;
	// }
	// cout << endl;
	// 
	// // 문제 2. 구구단을 for문으로 해결
	// 
	// for (int k = 1; k < 10; k++)
	// {
	// 	for (int i = 2; i < 10; i++)
	// 	{
	// 		cout << i << " X " << k << " = " << i * k << "\t";
	// 	}
	// 	cout << endl;
	// }


	// ##3. N중 루프
	// 반복문 안에 반복문이 N만큼 중첩된 반복문.
	// N이 증가함에 따라 시스템 부하는 증가한다.
	// 웬만해선 3중 이상 넘어서지 않는게 좋다.

	// for (int i = 0; i < 2; i++)		// 1중
	// {
	// 	cout << "Out Line" << endl;
	// 	for (int j = 0; j < 3; j++) // 2중
	// 	{
	// 		cout << "In Line" << endl;
	// 
	// 		for (int k = 0; k < 4; k++)
	// 		{
	// 			cout << "Core Line" << endl;
	// 		}
	// 	}
	// 
	// 	cout << "---------------------------" << endl;
	// }

	return;
}
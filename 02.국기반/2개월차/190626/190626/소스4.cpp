#include <iostream>
#include <string>

using namespace std;


void main()
{
	// ##1. string 클래스

	string str1 = "Hello";	// 인자있는 생성자 호출
	string str2 = str1;		// 복사 생성자 호출
	string str3;			// 디폴트 생성자 호출
	string str4 = "World";
	str3 = str2;			// 대입 연산자 호출
	str4 = "World!!!";		// 대입 연산자 호출

	// 
	// // string 객체 간 덧셈 및 축약 연산 가능.
	// str1 = str1 + str4;
	// str1 += str4;
	// cout << str1 << endl;
	// 
	// 
	// // string 객체와 문자열 간 덧셈 및 축약 연산 가능.
	// // str1 = str1 +"!!!!";
	// str1 += "!!!!";
	// cout << str1 << endl;

	// 문자열 비교 가능
	// if (str1 == str4)
	// 	cout << "str1과 str4는 같습니다" << endl;
	// else
	// 	cout << "str1과 str4는 다릅니다" << endl;
	// 
	// if(str1=="Hello")
	// 	cout << "str1과 Hello는 같습니다" << endl;
	// else
	// 	cout << "str1과 Hello는 다릅니다" << endl;


	string str = "Hello";
	//char* ptr = str;// error , str객체는 char* 타입이 아니다.

	// c_str 멤버함수 : string 클래스가 관리하고 있는 char* 배열의 주소를 반환.
	// const char* 타입으로 반환한다. 외부에서 값 변경 막기 위함.
	const char* ptr = str.c_str(); // ok

	return;
}
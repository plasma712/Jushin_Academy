#include <iostream>
#include <string>

using namespace std;


void main()
{
	// ##1. string Ŭ����

	string str1 = "Hello";	// �����ִ� ������ ȣ��
	string str2 = str1;		// ���� ������ ȣ��
	string str3;			// ����Ʈ ������ ȣ��
	string str4 = "World";
	str3 = str2;			// ���� ������ ȣ��
	str4 = "World!!!";		// ���� ������ ȣ��

	// 
	// // string ��ü �� ���� �� ��� ���� ����.
	// str1 = str1 + str4;
	// str1 += str4;
	// cout << str1 << endl;
	// 
	// 
	// // string ��ü�� ���ڿ� �� ���� �� ��� ���� ����.
	// // str1 = str1 +"!!!!";
	// str1 += "!!!!";
	// cout << str1 << endl;

	// ���ڿ� �� ����
	// if (str1 == str4)
	// 	cout << "str1�� str4�� �����ϴ�" << endl;
	// else
	// 	cout << "str1�� str4�� �ٸ��ϴ�" << endl;
	// 
	// if(str1=="Hello")
	// 	cout << "str1�� Hello�� �����ϴ�" << endl;
	// else
	// 	cout << "str1�� Hello�� �ٸ��ϴ�" << endl;


	string str = "Hello";
	//char* ptr = str;// error , str��ü�� char* Ÿ���� �ƴϴ�.

	// c_str ����Լ� : string Ŭ������ �����ϰ� �ִ� char* �迭�� �ּҸ� ��ȯ.
	// const char* Ÿ������ ��ȯ�Ѵ�. �ܺο��� �� ���� ���� ����.
	const char* ptr = str.c_str(); // ok

	return;
}
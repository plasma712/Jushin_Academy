#include<iostream>
#include"cImitateString.h"
using namespace std;

//ostream& operator << (ostream& _cout, cImitateString& _cText)
//{
//	_cout << _cText.GetText();
//	return _cout;
//}



void main()
{
	cImitateString Str1 = "Hello";
	cout << "Str1 = Hello" << endl;
	cout << "Str1 : "; Str1.GetText();
	cout << "-------------------------------------" << endl;
	cImitateString Str2 = Str1;
	cout << "Str2 = Str1" << endl;
	cout << "Str2 : "; Str2.GetText();
	cout << "-------------------------------------" << endl;
	cImitateString Str3;
	cout << "Str3" << endl;
	cout << "Str3 : "; Str3.GetText(); cout << endl;
	cout << "-------------------------------------" << endl;
	cImitateString Str4 = "World";
	cout << "Str4 = World" << endl;
	cout << "Str4 : "; Str4.GetText();
	cout << "-------------------------------------" << endl;
	cout << "Str4 = World!!!;" << endl;
	Str4 = "World!!!";
	cout << "Str4 : "; Str4.GetText();
	cout << "-------------------------------------" << endl;
	cout << "Str1 = Str1 + a" << endl;
	Str1 = Str1 + "a";	
	cout << "Str1 : "; Str1.GetText();
	cout << "-------------------------------------" << endl;
	cout << "Str1 = Str1 + Str4" << endl;
	Str1 = Str1 + Str4;
	cout << "Str1 : "; Str1.GetText();
	cout << "-------------------------------------" << endl;
	cout << "Str1+= Str4" << endl;
	Str1+= Str4;
	cout << "Str1 : "; Str1.GetText();
	cout << "-------------------------------------" << endl;
	cout << "Str1 : "; Str1.GetText();
	cout << "Str4 : "; Str4.GetText();
	cout << "Str1 == Str4 "; 
	Str1 == Str4;
	cout << "-------------------------------------" << endl;
	cImitateString Str5 = "World!!!";
	cout << "Str4 : "; Str4.GetText();
	cout << "Str5 = World!!! " << endl;
	cout << "Str4 == Str5 ";
	Str4 == Str5;
	cout << "-------------------------------------" << endl;
	cout << "Str4 : "; Str4.GetText();
	cout << "Str4 == World!!! ";
	Str4 == "World!!!";
	cout << "-------------------------------------" << endl;
	cout << "Str4 == H ";
	Str4 == "H";
	cout << "-------------------------------------" << endl;



	return;
}
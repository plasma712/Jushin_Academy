#pragma once
#include <iostream>
class cImitateString
{
private:
	char* m_cText;
public:
	cImitateString();
	~cImitateString();
	cImitateString(const cImitateString& _Text);
	cImitateString(const char* _Text);
public:// 추가부분
	void Release();
public:

	cImitateString operator + (const char* _PlusText);
	cImitateString operator + (cImitateString _PlusText);
	cImitateString operator += (cImitateString _PlusText);


	cImitateString operator == (const char* _PlusText);
	cImitateString operator == (cImitateString _PlusText);
	//ostream operator << (cImitateString _PluseText);
public:
	void GetText();

};

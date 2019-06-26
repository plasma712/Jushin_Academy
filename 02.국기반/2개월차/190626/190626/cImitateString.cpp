#include "cImitateString.h"
#include <iostream>
using namespace std;



cImitateString::cImitateString()
{
}


cImitateString::~cImitateString()
{
}

cImitateString::cImitateString(const char * _Text)
{
	m_cText = new char[strlen(_Text)+1];
	strcpy_s(m_cText, strlen(_Text) + 1, _Text);
}

cImitateString cImitateString::operator+(const char * _PlusText)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	int cTextLen = strlen(this->m_cText);
	char* Temp = new char[cTextLen + 1];
	strcpy_s(Temp, cTextLen + 1, m_cText);

	m_cText = new char[strlen(_PlusText) + cTextLen + 1];
	strcpy_s(m_cText, strlen(_PlusText) + cTextLen + 1, Temp);

	strcat_s(m_cText, strlen(_PlusText) + cTextLen + 1, _PlusText);

	return m_cText;
}

cImitateString cImitateString::operator+(cImitateString _PlusText)
{
	int cTextLen = strlen(this->m_cText);
	char* Temp = new char[cTextLen + 1];
	strcpy_s(Temp, cTextLen + 1, m_cText);

	m_cText = new char[strlen(_PlusText.m_cText) + cTextLen + 1];
	strcpy_s(m_cText, strlen(_PlusText.m_cText) + cTextLen + 1, Temp);

	strcat_s(m_cText, strlen(_PlusText.m_cText) + cTextLen + 1, _PlusText.m_cText);

	return m_cText;

	//return cImitateString();
}

cImitateString cImitateString::operator+=(cImitateString _PlusText)
{
	int cTextLen = strlen(this->m_cText);
	char* Temp = new char[cTextLen + 1];
	strcpy_s(Temp, cTextLen + 1, m_cText);

	m_cText = new char[strlen(_PlusText.m_cText) + cTextLen + 1];
	strcpy_s(m_cText, strlen(_PlusText.m_cText) + cTextLen + 1, Temp);

	strcat_s(m_cText, strlen(_PlusText.m_cText) + cTextLen + 1, _PlusText.m_cText);

	return m_cText;
	//return cImitateString();
}

cImitateString cImitateString::operator==(const char * _PlusText)
{
	if (strcmp(this->m_cText, _PlusText) == false)
	{
		cout << endl;
		cout << "같다" << endl;
	}
	else
	{
		cout << endl;
		cout << "같지 않다." << endl;
	}

	return cImitateString();
}


cImitateString cImitateString::operator==(cImitateString _PlusText)
{

	if (strcmp(this->m_cText, _PlusText.m_cText)==false)
	{
		cout << endl;
		cout << "같다"<<endl;
	}
	else
	{
		cout << endl;
		cout << "같지 않다." << endl;
	}

	return cImitateString();
}



void cImitateString::GetText()
{
	if (this->m_cText == nullptr)
		return;
	cout << m_cText << endl;
}


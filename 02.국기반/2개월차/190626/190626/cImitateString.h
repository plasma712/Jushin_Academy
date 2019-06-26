#pragma once
class cImitateString
{
private:
	char* m_cText;
public:
	cImitateString();
	~cImitateString();
	
	cImitateString(const char* _Text);

public:

	cImitateString operator + (const char* _PlusText);
	cImitateString operator + (cImitateString _PlusText);
	cImitateString operator += (cImitateString _PlusText);

	cImitateString operator == (const char* _PlusText);
	cImitateString operator == (cImitateString _PlusText);


public:
	void GetText();

};


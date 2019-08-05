#pragma once
class cMyBmp
{
public:
	cMyBmp();
	~cMyBmp();

public:

	void LoadBmp(const wstring& wstrFilePath, const wstring & wstrObjectKey);

	HDC GetMemDC() const;
};


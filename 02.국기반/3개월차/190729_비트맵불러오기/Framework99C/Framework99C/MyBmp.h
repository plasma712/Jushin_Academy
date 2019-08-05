#pragma once
class CMyBmp
{
public:
	CMyBmp();
	~CMyBmp();

public:
	HDC GetMemDC() const;
	
public:
	void LoadBitmap(const wstring& wstrFilePath);

private:
	void Release();

private:
	// 불러온 비트맵의 정보를 가지고 있는 핸들.
	HBITMAP	m_hBitmap;
	HBITMAP m_hOldbmp;

	// 불로온 비트맵을 미리 그려넣을 메모리DC
	HDC		m_hMemDC;
};


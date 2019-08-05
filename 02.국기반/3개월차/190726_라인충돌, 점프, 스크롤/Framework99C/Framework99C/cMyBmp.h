#pragma once
class cMyBmp
{
private:
	// 불러온 비트맵의 정보를 가지고 있는 핸들
	HBITMAP m_hBitmap;

	HBITMAP m_hOldbmp;
	// 불러온 비트맵을 미리 그려넣을 메모리 DC
	HDC		m_hMemDC;

public:
	cMyBmp();
	~cMyBmp();

private:
	void Release();
	
private:
	// 불러온 비트맵의 정보를 가지고 있는 핸들.
	
	void LoadBitmap(const wstring & wstrFilePath);
};


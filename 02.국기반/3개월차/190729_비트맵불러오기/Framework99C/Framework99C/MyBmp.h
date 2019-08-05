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
	// �ҷ��� ��Ʈ���� ������ ������ �ִ� �ڵ�.
	HBITMAP	m_hBitmap;
	HBITMAP m_hOldbmp;

	// �ҷο� ��Ʈ���� �̸� �׷����� �޸�DC
	HDC		m_hMemDC;
};


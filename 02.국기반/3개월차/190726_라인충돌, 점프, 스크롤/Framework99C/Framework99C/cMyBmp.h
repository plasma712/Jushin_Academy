#pragma once
class cMyBmp
{
private:
	// �ҷ��� ��Ʈ���� ������ ������ �ִ� �ڵ�
	HBITMAP m_hBitmap;

	HBITMAP m_hOldbmp;
	// �ҷ��� ��Ʈ���� �̸� �׷����� �޸� DC
	HDC		m_hMemDC;

public:
	cMyBmp();
	~cMyBmp();

private:
	void Release();
	
private:
	// �ҷ��� ��Ʈ���� ������ ������ �ִ� �ڵ�.
	
	void LoadBitmap(const wstring & wstrFilePath);
};


#include <iostream>

using namespace std;

void main()
{
	// SBCS (Single Byte Character Set)
	// ���� ���ڸ� ����� �� 1 ����Ʈ�� ����Ѵ�.
	// char , �ƽ�Ű�ڵ�

	// MBCS (Multi Bytes Character Set)
	// char�� ��������� ���� ���� 1����Ʈ Ȥ�� 2����Ʈ ����Ѵ�.


	// char szBuf1[] = "Hello";
	// char szBuf2[] = "�ѱ�";
	   
	// cout << sizeof(szBuf1) << endl;
	// cout << sizeof(szBuf2) << endl;
	   
	// cout << strlen(szBuf2) << endl; // �츮���� 2����, ��ǻ�Ϳ��� 4����


	// WBCS (Wide Bytes Character Set)
	// ���� ���ڸ� ����� �� 2����Ʈ�� ����Ѵ�.
	// wchar_t �����ڵ�
	cout << sizeof(wchar_t) << endl;


	// �����ڵ� �迭�� ���ڿ��� �ٷ� �� �տ� �ݵ�� L��ȣ�� �پ��־�� �Ѵ�.
	wchar_t szBuf1[] = L"Hello";
	wchar_t szBuf2[] = L"�ѱ�";

	// �����ڵ� �迭 ���ڿ������Լ�

	//wcslen()




}
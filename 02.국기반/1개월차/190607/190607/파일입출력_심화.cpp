#include <iostream>

using namespace std;

void main()
{
	// // ##1. ���� ����� (������ �ҷ�����, ����)
	// // �ܼ� ����½� ǥ�� ����� ��Ʈ���� �ü���� �˾Ƽ� �Ҵ� �� �Ҹ� �������.
	// // ���� ����� �� ����� ��Ʈ���� �ü������ �Ҵ� �� �Ҹ��� ��û.
	// 
	// // ##2. ���� ��� (������ ����)
	// 
	// // ��Ʈ�� ���� ��û (���� ����)
	// FILE* fp = nullptr;
	// 
	// // ���� ���濡 �����ϸ� 0��ȯ. �����ϸ� 0�� �ƴ� �� ��ȯ.
	// // fopen_s(��Ʈ���� ������, ���ϰ��, ���(w) or �Է�(r))
	// //errno_t err = fopen_s(&fp, "C:/Users/Plasma/Desktop/��Ű��Ӿ�ī����/02.�����/190607/Data/test.txt","w");
	// 
	// errno_t err = fopen_s(&fp,/*�����*/"../Data/test.txt", "w");
	// 
	// if (err == 0)
	// {
	// 	fputs("Hello world", fp);
	// 	cout << "���� ���� ����" << endl;
	// 	
	// 
	// 	// ��Ʈ�� �Ҹ� ��û.
	// 	fclose(fp);
	// }
	// else
	// 	cout << "���� ���� ����" << endl;

	// ##3. ���� �Է� (������ �ҷ�����)

	// FILE* fp = nullptr;
	// errno_t err = fopen_s(&fp, "../Data/test.txt", "r");
	// 
	// if (err == 0)
	// {
	// 	char szInput[32] = "";
	// 
	// 	fgets(szInput, 32, fp);
	// 
	// 	cout << szInput << endl;
	// 	cout << "�ҷ����� ����" << endl;
	// 
	// 	fclose(fp);
	// }
	// else
	// 	cout << "���� ���� ����" << endl;

	// ##4. ������
	// w(write) : ���(�����) ���� ������ ���ٸ� ���� ����
	// a(apped) : ���(�̾��) ���� ������ ���ٸ� ���� ����
	// r(read) : �Է�, ���� ������ ���ٸ� ����.

	// t(text mode) : ����� �ĺ��� �� �ִ� �ؽ�Ʈ �������� ���� �����.
	// b(binary mode) : �ؽ�Ʈ�� ǥ���� �� ���� (������, ����, �̹��� ��) ������ ���� �����

	// ##5. ������ ���� EOF�� �˻��ؾ��Ѵ�.

	// FILE* fp = nullptr;
	// errno_t err = fopen_s(&fp, "../Data/test.txt", "rt");
	
	// if (err == 0)
	// {
	// 	int ch = 0;
	// 	while (true)
	// 	{
	// 		ch = fgetc(fp);
	// 
	// 		// null���ڴ� ���Ͽ� ����Ǿ����� �ʴ�.
	// 		//if (ch == '\0')
	// 		//	break;
	// 
	// 		// ������ ������ EOF(-1)�� ��ϵǾ� ����.
	// 
	// 		if (ch == EOF)
	// 			break;
	// 
	// 		putchar(ch);
	// 	}
	// }
	// else
	// 	cout << "���� ���� ����" << endl;


		
	return;
}
#include <iostream>

using namespace std;

void main()
{
	// ##1. ���� ������.
	// FILE ����ü ���ο��� ���� �����ڰ� �����Ѵ�.
	// ���� �������� ������ ������ ������ �аų� ����� �� ��𼭺��� ������ ������
	// ���� ��ġ�� ����Ű�� �ִ�
	// ���� ����� �� ������ ���� �������� ��ġ�� ���� �������� �����̸� ����.
	// FILE* fp = nullptr;
	// errno_t err = fopen_s(&fp, "../Data/test2.txt", "rt");

	// test2.txt���� "123456789"�� ��ϵǾ��ִ� ����.
	// ó�� ���� �����ڴ� '1'�� ��ġ�� ����Ű�� ����.
	// int ch = fgetc(fp); // 


	// ##2. fseek �Լ�.
	// ���� �������� ��ġ�� �����ϴ� �Լ�.

	//FILE* fp = nullptr;
	//errno_t err = fopen_s(&fp, "../Data/test2.txt", "rt");
	//
	//if (err == 0)
	//{
	//	// SEEK_SET : ó����ġ����
	//	// 3: 1����Ʈ�� ��ĭ �̵�
	//	fseek(fp, 3, SEEK_SET);
	//
	//	int ch = fgetc(fp);
	//	putchar(ch);
	//	putchar('\n');
	//	cout << "------------------------------" << endl;
	//
	//	// SEEK_CUR: ���� �������� ��ġ
	//	fseek(fp, 0, SEEK_CUR);
	//	ch = fgetc(fp);
	//	putchar(ch);
	//	putchar('\n');
	//	cout << "------------------------------" << endl;
	//
	//	fseek(fp, -3, SEEK_END);
	//	ch = fgetc(fp);
	//	putchar(ch);
	//	putchar('\n');
	//	cout << "------------------------------" << endl;
	//
	//	fseek(fp, 0, SEEK_CUR);
	//	ch = fgetc(fp);
	//	putchar(ch);
	//	putchar('\n');
	//	cout << "------------------------------" << endl;
	//
	//
	//	fclose(fp);
	//}


	// ##3. ftell �Լ�.
	// ���� ���� �������� ��ġ�� �˷��ִ� �Լ�.
	// FILE* fp = nullptr;
	// errno_t err = fopen_s(&fp, "../Data/test2.txt", "rt");
	// 
	// if (err == 0)
	// {
	// 	long index = ftell(fp);
	// 	cout << "���� �������� ��ġ" << endl;
	// 	cout << "---------------------------" << endl;
	// 
	// 	int ch = fgetc(fp);
	// 	putchar(ch);
	// 	putchar('\n');
	// 
	// 	index = ftell(fp);
	// 	cout << "���� �������� ��ġ" << endl;
	// 	cout << "---------------------------" << endl;
	// }


	// ##4. feof�Լ�
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "../Data/test2.txt", "rt");

	if (err == 0)
	{
		int ch = 0;
		while (true)
		{
			ch = fgetc(fp);

			// ���� ���� �����ڰ� EOF�� �����ߴ��� �˻��ϴ� �Լ�.
			// ���� �ߴٸ� true

			if (feof(fp))
				break;

			putchar(ch);
		}
		fclose(fp);
	}


	return;
}
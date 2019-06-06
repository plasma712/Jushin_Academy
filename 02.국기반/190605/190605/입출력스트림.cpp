#include <iostream> 

using namespace std;

void main()
{
	// ##1. ����� ��Ʈ�� 
	// ��Ƽ�� : ������ ��ſ� �ʿ��� ������ �������. �ܹ��� �帧�� ���´�.

	// ǥ�� �Է� ��Ʈ�� : stdin
	// ǥ�� ��� ��Ʈ�� : stdout
	// ����� ��Ʈ���� os�� �˾Ƽ� �Ҵ� �� �Ҹ� �����ش�.

	// ##2. ����� ����
	// ������ �ۼ����� ȿ���� ������ �ʿ��� �ӽ� ����.

	// ##3. ���� ���� ��� �Լ�
	// putchar, fputc

	// putchar('A'); // stdout(ǥ�� ��� ��Ʈ��)�� ���� ����ͷ� ���� ���.
	// putchar�� �޸� ��Ʈ���� ������ �� �ִ�. ��� ����� ����Ͱ� �ƴ� �� �� �ִ�.
	// fputc('A',stdout); 

	// ##4. ���Ϲ��� �Է� �Լ�
	// �Է¹��ۿ��� ���ڸ� �ϳ��� �������� �Լ�. (FIFO) /���Լ���
	// getchar, fgetc
	// �Լ� ȣ�⿡ �����ϰų� ���̻� �о�� ���ڰ� ���ٸ� EOF(-1)�� ��ȯ.
	// EOF (End Of File)

	// int ch = getchar(); // stdin(ǥ�� �Է� ��Ʈ��)�� ���� Ű����κ��� ���� �Է�
	// putchar(ch);
	// 
	// ch = getchar();
	// putchar(ch);
	// 
	// ch = getchar();
	// putchar(ch);
	// 
	// ch = getchar();
	// putchar(ch);

	// int ch = fgetc(stdin); // ��Ʈ�� ���� ����. �Է� ����� Ű���尡 �ƴ� ���� �ִ�.
	// fputc(ch, stdout);

	// ##5. ���ڿ� ��� �Լ�
	// puts, fputs
	// puts("Hello"); // stdout�� ���� ����ͷ� ���ڿ� ���. �ڵ� ����(O)
	// fputs("Hello", stdout); // ��Ƽ�� ���� ����. �ڵ� ����(X)

	// ##6. ���ڿ� �Է� �Լ�
	// �Է¹��۷κ��� ���ڿ��� ���� ����(\n)�� �о���� �Լ�.
	// gets_s, fgets

	char szName[32] = "";
	
	// gets_s(char�迭 �ּ�, �迭 ũ��)
	// \n�� �Է¹��ۿ� �����ϳ� �о������ �ʰ� ����.
	// ���ڿ� �Է��� �� �迭ũ�� �Ѿ�� �ʵ��� ����.
	cout << "�Է� : "; gets_s(szName, 32); // stdin�� ���� ���ڿ� �Է�.
	cout << "��� : "; puts(szName);

	// fgets(char�迭 �ּ�, �о�� �ִ� ����, stream)
	// gets_s�� �޸� \n�� �о�´�.
	cout << "�Է� : "; fgets(szName, 7, stdin);
	cout << "��� : "; fputs(szName, stdout);

	return;
}
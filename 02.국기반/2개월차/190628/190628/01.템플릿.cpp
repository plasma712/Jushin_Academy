#include <iostream>

using namespace std;
// ##1. ���ø� (Template)
// ������ ������ ���� ���� �ڷ����� ȣȯ�� �� �ְ� ���α׷��� �ۼ��ϵ��� �����ִ� C++ ����.
// ���α׷��� �ۼ��ϵ��� �����ִ� C++����


// ##2. �Լ� ���ø�
// �Ʒ��� ���� ����� �Լ��� ���ڴٴ� ���ø�(Ʋ)�̴�.
// ��ü���� ȣ�� �ڵ尡 ������ �Լ� �ڵ�� �������� �ʴ´�.

template <typename T>
T Add(T a, T b)
{
	return a + b;
}

// ���ø��� Ư��ȭ
// ���ø��� ���� �ڷ����� ȣȯ������
// Ư�� �ڷ����� ���ؼ� ������ �ٸ� ������ �ʿ��� ��
template<>
const char* Add(const char*a,const char*b)
{
	int iTotalLen = strlen(a) + strlen(b);
	char* cTemp = new char;

	//cTemp= strcat();
	return a;
}



void main()
{
	// ##3. ���ø� �Լ�
	
	// �� �� int Ÿ���� ���� �Լ��ڵ尡 ����ȴ�. (�����Ͻ���)
	int iResult = Add<int>(10, 20); 
	iResult = Add<int>(100, 200); // ������ �̹� ������ int �ڵ带 ����.

	// �� �� float Ÿ���� ���� �Լ��ڵ尡 �����ȴ�. (�����Ͻ���)
	// float fResult = Add(3.14f, 3.f); // �ڷ����� ������� �ʾƵ� �����Ϸ��� �Ű������� �������ش�.
	float fResult = Add<float>(3.14f, 3.f);

	// ���� ���ܻ����� �ʿ��ϴ�.
	char* pTotal = Add<char*>("Hello", "World");
	cout << pTotal << endl;

	delete[] pTotal;


	return;
}
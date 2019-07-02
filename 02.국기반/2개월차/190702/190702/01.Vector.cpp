#include <iostream>
#include <vector>

using namespace std;

// STL vector

// 1. �����迭 ��� -> ���ӵ� �޸𸮸� ���´�.
// 2. �ε��� ���� (��������) ���� -> Ž���� �����ϴ�.
// 3. ��ȭ���¿��� �߰� ���� �� ���Ҵ�, ���� �߻� -> ����� �߰� ���� �Ҹ�

void main()
{
	// ##1. ���� ����
	// vector<int>   vec1;
	// vector<float> vec2;
	// vector<Ŭ������> vec3;
	// vector<����ü��> vec4;
	// vector<����ü��> vec5;

	// ##2. ������ ����

	// vector<int> vec;

	// size : ���Ͱ� �����ϰ� �ִ� ���� �ڷ��� ����
	// capacity : ���� ���Ͱ� ������ �� �ִ� �ִ� �ڷ� ����.
	//cout << "    Size : " << vec.size() << endl;
	//cout << "capacity : " << vec.capacity() << endl;
	//cout << "-------------------------------------------" << endl;

	//vec.push_back(10);
	//vec.push_back(20);

	//cout << "    Size : " << vec.size() << endl;
	//cout << "capacity : " << vec.capacity() << endl;
	//cout << "-------------------------------------------" << endl;

	//vec.push_back(30);
	//vec.push_back(40);

	//cout << "    Size : " << vec.size() << endl;
	//cout << "capacity : " << vec.capacity() << endl;
	//cout << "-------------------------------------------" << endl;

	//vec.push_back(50);

	// capacity�� 1.5�辿 ����. -> vector�� capacity ��å (���к��� ���Ҵ��� ���ϱ� ���Ͽ� �̸� ����� Ű��.)
	//cout << "    Size : " << vec.size() << endl;
	//cout << "capacity : " << vec.capacity() << endl;
	//cout << "-------------------------------------------" << endl;


	//// vector�� �ε��� �����ڰ� �����ε��Ǿ� �־ �������� ����.
	//cout << "3�� �ε����� �� : " << vec[3] << endl;

	////for (int i = 0; i < vec.size(); i++)
	////	cout << vec[i] << endl;

	//// ���� ��� for���� �̿��� ���� ��ȸ ����

	//for(int element)

	// ##3. ������ ���� (pop_back)

	//vector<int> vec;

	//vec.push_back(10);
	//vec.push_back(20);
	//vec.push_back(30);

	//cout << "size : " << vec.size() << endl;
	//cout << "capacity : " << vec.capacity() << endl;
	//cout << "-------------------------------------------" << endl;

	//// ���� ������ ���Ұ� ���ŵ�.
	// ���Ұ� ������ �Ǵ��� capacity�� ������ �ʴ´�.
	//vec.pop_back();

	//cout << "size : " << vec.size() << endl;
	//cout << "capacity : " << vec.capacity() << endl;
	//cout << "-------------------------------------------" << endl;


	//for (size_t i = 0; i < vec.size(); i++)
	//	cout << vec[i] << endl;

	// ##4. empty�Լ�
	//vector<int> vec;
	//
	//// �ƹ��� ���Ұ� ���ٸ� true ��ȯ
	//if (vec.empty())
	//	cout << "�������" << endl;

	// ##5. clear�Լ�
	//vector <int> vec;

	//vec.push_back(10);
	//vec.push_back(20);
	//vec.push_back(30);
	//vec.push_back(40); 
	//vec.push_back(50);
	//vec.push_back(60);
	//vec.push_back(70);
	//vec.push_back(80);
	//vec.push_back(90);
	//vec.push_back(100);

	//cout << "size : " << vec.size() << endl;
	//cout << "capacity : " << vec.capacity() << endl;
	//cout << "-------------------------------------------" << endl;

	//// ��� ���Ҹ� ����
	//vec.clear();

	//cout << "size : " << vec.size() << endl;
	//cout << "capacity : " << vec.capacity() << endl;
	//cout << "-------------------------------------------" << endl;

	//// shink_to_fit�Լ� (C++ 11���� ����)
	//// capacity�� ���� size�� ���ߴ� �Լ�
	//vec.shrink_to_fit();

	//cout << "size : " << vec.size() << endl;
	//cout << "capacity : " << vec.capacity() << endl;
	//cout << "-------------------------------------------" << endl;

	// ##6. swap�Լ�
	// �� �����̳ʰ� ���� �͵��� ��ȯ�ϴ� �Լ�.
	//vector<int> vec1;

	//vec1.push_back(10);
	//vec1.push_back(20);
	//
	//for (size_t i = 0; i < vec1.size(); i++)
	//	cout << vec1[i] << endl;

	//cout << "size : " << vec1.size() << endl;
	//cout << "capacity : " << vec1.capacity() << endl;
	//cout << "-------------------------------------------" << endl;


	//vector<int> vec2;
	//vec2.push_back(30);
	//vec2.push_back(40);
	//vec2.push_back(50);

	//for (size_t i = 0; i < vec2.size(); i++)
	//	cout << vec2[i] << endl;

	//cout << "size : " << vec2.size() << endl;
	//cout << "capacity : " << vec2.capacity() << endl;
	//cout << "-------------------------------------------" << endl;


	//cout << "After vec1. swap(vec2)"; swap(vec1, vec2);
	//cout << endl;

	//for (size_t i = 0; i < vec1.size(); i++)
	//	cout << vec1[i] << endl;

	//cout << "size : " << vec1.size() << endl;
	//cout << "capacity : " << vec1.capacity() << endl;
	//cout << "-------------------------------------------" << endl;


	//for (size_t i = 0; i < vec2.size(); i++)
	//	cout << vec2[i] << endl;

	//cout << "size : " << vec2.size() << endl;
	//cout << "capacity : " << vec2.capacity() << endl;
	//cout << "-------------------------------------------" << endl;

	// ##7.front�� back �Լ�

	vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);


	// front : ���� �� ���� ù��° ���� ��ȯ
	// back  : ���� �� ���� ������ ���� ��ȯ

	cout << "front : " << vec.front() << endl;
	cout << "back : " << vec.back() << endl;

	// front�� back�� ����(���۷���)�� ��ȯ�Ѵ�.
	vec.front() = 100;
	vec.back() = 500;

	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i] += 5;			// �ε��� ������ ���� ���� ���ٵ� ������ ����.
		cout << vec[i] << endl;
	}
	return;
}
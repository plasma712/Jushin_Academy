#include <iostream>
#include <vector>

using namespace std;

// STL vector

// 1. 동적배열 기반 -> 연속된 메모리를 갖는다.
// 2. 인덱스 접근 (임의접근) 가능 -> 탐색에 유리하다.
// 3. 포화상태에서 추가 삽입 시 재할당, 복사 발생 -> 빈번한 추가 삽입 불리

void main()
{
	// ##1. 벡터 선언
	// vector<int>   vec1;
	// vector<float> vec2;
	// vector<클래스명> vec3;
	// vector<구조체명> vec4;
	// vector<열거체명> vec5;

	// ##2. 데이터 삽입

	// vector<int> vec;

	// size : 벡터가 저장하고 있는 현재 자료의 개수
	// capacity : 현재 벡터가 저장할 수 있는 최대 자료 개수.
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

	// capacity는 1.5배씩 증가. -> vector의 capacity 정책 (무분별한 재할당을 안하기 위하여 미리 사이즈를 키움.)
	//cout << "    Size : " << vec.size() << endl;
	//cout << "capacity : " << vec.capacity() << endl;
	//cout << "-------------------------------------------" << endl;


	//// vector는 인덱스 연산자가 오버로딩되어 있어서 임의접근 가능.
	//cout << "3번 인덱스의 값 : " << vec[3] << endl;

	////for (int i = 0; i < vec.size(); i++)
	////	cout << vec[i] << endl;

	//// 범위 기반 for문을 이용한 원소 순회 가능

	//for(int element)

	// ##3. 데이터 제거 (pop_back)

	//vector<int> vec;

	//vec.push_back(10);
	//vec.push_back(20);
	//vec.push_back(30);

	//cout << "size : " << vec.size() << endl;
	//cout << "capacity : " << vec.capacity() << endl;
	//cout << "-------------------------------------------" << endl;

	//// 가장 마지막 원소가 제거됨.
	// 원소가 삭제가 되더라도 capacity는 변하지 않는다.
	//vec.pop_back();

	//cout << "size : " << vec.size() << endl;
	//cout << "capacity : " << vec.capacity() << endl;
	//cout << "-------------------------------------------" << endl;


	//for (size_t i = 0; i < vec.size(); i++)
	//	cout << vec[i] << endl;

	// ##4. empty함수
	//vector<int> vec;
	//
	//// 아무런 원소가 없다면 true 반환
	//if (vec.empty())
	//	cout << "비어있음" << endl;

	// ##5. clear함수
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

	//// 모든 원소를 제거
	//vec.clear();

	//cout << "size : " << vec.size() << endl;
	//cout << "capacity : " << vec.capacity() << endl;
	//cout << "-------------------------------------------" << endl;

	//// shink_to_fit함수 (C++ 11부터 지원)
	//// capacity를 현재 size에 맞추는 함수
	//vec.shrink_to_fit();

	//cout << "size : " << vec.size() << endl;
	//cout << "capacity : " << vec.capacity() << endl;
	//cout << "-------------------------------------------" << endl;

	// ##6. swap함수
	// 두 컨테이너가 가진 것들을 교환하는 함수.
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

	// ##7.front와 back 함수

	vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);


	// front : 원소 중 가장 첫번째 원소 반환
	// back  : 원소 중 가장 마지막 원소 반환

	cout << "front : " << vec.front() << endl;
	cout << "back : " << vec.back() << endl;

	// front와 back은 원본(래퍼런스)을 반환한다.
	vec.front() = 100;
	vec.back() = 500;

	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i] += 5;			// 인덱스 연산을 통한 원소 접근도 원본에 접근.
		cout << vec[i] << endl;
	}
	return;
}
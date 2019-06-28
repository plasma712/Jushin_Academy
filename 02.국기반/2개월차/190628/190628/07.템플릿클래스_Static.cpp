#include <iostream>

using namespace std;

template <typename T>
class cBase
{
public:
	static T m_Static;
public:
	void Func(T n)
	{
		m_Static += n;
	}
};

template<typename T>

T cBase<T>::m_Static = 0;

void main()
{
	cBase<int> obj1;
	cBase<int> obj2;
	cBase<int> obj3;

	obj1.Func(10);
	obj2.Func(10);
	obj3.Func(10);

	cout << cBase<int>::m_Static << endl;

	cout << "-------------------------------------" << endl;

	cBase<float> obj4;
	cBase<float> obj5;
	cBase<float> obj6;

	obj4.Func(10.f);
	obj5.Func(10.f);
	obj6.Func(10.f);

	cout << cBase<float>::m_Static << endl;


	return;
}
#include <iostream>

using namespace std;

template <typename T>
struct tagVector
{
	tagVector(T _x, T _y, T _z)
		:x(_x), y(_y), z(_z)
	{

	}

	T x, y, z;
};

template<typename T>
class cMyVector : public tagVector<T>
{
public:
	cMyVector(T x, T y, T z)
		:tagVector<T>(x, y, z)
public:
	cMyVector<T> operator+(const cMyVector<T>& vec)
	{
		T x = this->x + vec.x;
		T y = this->y + vec.y;
		T z = this->z + vec.z;

		return cMyVector<T>(x, y, z);
	}
};

void main()
{
	cMyVector<float> vPos1(1, 2, 3);
	cMyVector<float> vPos2(1, 2, 3);
	cMyVector<float> vPos3(1, 2, 3);

	cout << vPos1.x << endl;



	return;
}
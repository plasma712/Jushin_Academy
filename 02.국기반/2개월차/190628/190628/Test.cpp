#include "Test.h"

using namespace std;

template<typename T>
T cTest<T>::operator()(T a, T b)
{
	return a + b;
}

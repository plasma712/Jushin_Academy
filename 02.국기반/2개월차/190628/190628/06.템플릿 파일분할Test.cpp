#include <iostream>

// 템플릿을 파일분할 했을 때 cpp까지 include 해주어야 정상 빌드가 된다.
// 따라서 템플릿은 통상적으로 헤더에 모두 작성한다.
#include "Test.h"
#include "Test.cpp"
using namespace std;

void main()
{
	cTest<int> functor;
	cout << functor(10, 20) << endl;
}

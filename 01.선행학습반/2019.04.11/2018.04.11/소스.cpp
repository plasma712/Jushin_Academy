#include <iostream> 
using namespace std;

namespace A
{
	void Render()
	{
		cout << "박태호1가 만든 보여주는 기능을 가진 함수" << endl;
	}
}

namespace B
{
	void Render()
	{
		cout << "박태호2가 만든 보여주는 기능을 가진 함수" << endl;
	}
}

void main()
{
	cout << "Hello World !!!" << endl;
	//A::Render();
	//B::Render();

	int i = 0;
	cout << i << endl;
}
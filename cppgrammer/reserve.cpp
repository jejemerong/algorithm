#include <iostream>
using namespace std;

// reserve 는 용량 확보만 하고 할당한 용량만큼의 크기 차지
void reserveMethod()
{
	vector<int> v { 10, 20 };
	cout << v.size() << endl; // 2
	cout << v.capacity() << endl; // 2

	v.reserve(100);
	cout << v.size() << endl; // 2
	cout << v.capacity() << endl; // 100
}

// resize 는 용량 확보 후 두번째 인자 값 또는 0 으로 초기화
void resizeMethod()
{
	vector<int> v { 10, 20 };
	cout << v.size() << endl; // 2
	cout << v.capacity() << endl; // 2

	v.resize(100);
	cout << v.size() << endl; // 100
	cout << v.capacity() << endl; // 100
}

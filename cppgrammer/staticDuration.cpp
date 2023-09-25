#include <iostream>

using namespace std;

void incrementAndPrint()
{
	static int s_value = 1; // 기본적으로 static duration 로 이 줄은 한번만 실행됨. 
	++s_value;
	cout << s_value << endl;
} // s_value 가 여기서 소멸되지는 않지만, 접근할 수 없음.

int main()
{
	incrementAndPrint(); // 2
	incrementAndPrint(); // 3
	incrementAndPrint(); // 4
}
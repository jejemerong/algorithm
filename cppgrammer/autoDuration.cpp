#include <iostream>

using namespace std;

void incrementAndPrint()
{
	int value = 1; // 기본적으로 auto duration
	++value;
	cout << value << endl;
} // value 는 여기서 소멸됨.

int main()
{
	incrementAndPrint(); // 2
	incrementAndPrint(); // 2
	incrementAndPrint(); // 2
}
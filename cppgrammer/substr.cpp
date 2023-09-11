#include <iostream>
#include <string>

using namespace std;
// 문자열 자르기

int main()
{
    // 1. substr()
    string str = "ABCDE";
    
    string newStr1 = str.substr(0, 3);
    char newStr2 = *"A";
    int b = newStr2;
    cout << newStr1 << endl;
    cout << b << endl;

    return 0;
}
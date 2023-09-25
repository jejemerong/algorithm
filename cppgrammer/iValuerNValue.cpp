#include <iostream>

using namespace std;

int main()
{
    int num = 10;

    ++num = 30; // 값을 먼저 증가시키고, 그 결과를 num 객체로 반환하여 아래와 같은 표현식으로 실행됨.
    // num = 30

    // num++ = 30; // I-value 가 아니기 때문에 10과 30을 비교하는 컴파일 에러가 발생함.
    // 10 = 30

}
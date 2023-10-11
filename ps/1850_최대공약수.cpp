#include <iostream>

using namespace std;
int gcd(long a, long b);

int main()
{
    long a, b;
    scanf("%ld %ld", &a, &b);
    long result = gcd(a, b);
    while(result > 0){
        cout << 1;
        result--;
    }
    cout << "\n";
}

int gcd(long a, long b)
{
    if(b == 0){
        return a;
    }
    else {
        return gcd(b, a % b); // TODO: 꼬리 재귀 여부 확인
    }
}
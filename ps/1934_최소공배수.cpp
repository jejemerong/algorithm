#include <iostream>

using namespace std;

int gcd(int a, int b) 
{   
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        int result = a * b / gcd(a, b);
        cout << result << "\n";
    }
}


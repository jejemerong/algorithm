#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    ll N;
    scanf("%lld", &N);
    ll result;
    for(ll i = 2; i <= N; i++){
        if(N/i == 0){
            result -= result / i;
            while(N % i == 0) N /= i;
        }
    }
    if(N > 1){
        result -= result / N;
    }
    cout << result;
}
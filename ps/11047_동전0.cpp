#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, A;
    scanf("%d %d", &N, &A);
    vector <int> Coin(N);

    for(int i = 0; i < N; i++){
        scanf("%d", &Coin[i]);
    }

    int count = 0;

    for(int i = N - 1; i >= 0; i--){
        if(Coin[i] <= A) {
            count += (A / Coin[i]);
            A = A % Coin[i];
        }
    }
    printf("%d", count);

}
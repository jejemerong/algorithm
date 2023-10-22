#include <iostream>

using namespace std;

int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    int Arr[N + 1][N + 1];
    for(int i = 0; i <= N; i++){
        Arr[i][0] = 1;
        Arr[i][i] = 1;
        Arr[i][1] = i;
    }

    for(int i = 2; i <= N; i++){
        for(int j = 1; j < i; j++){
            Arr[i][j] = Arr[i - 1][j] + Arr[i - 1][j - 1];
            Arr[i][j] %= 10007;
        }
    }

    cout << Arr[N][K];
}
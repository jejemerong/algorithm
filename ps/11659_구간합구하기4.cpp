#include <iostream>

using namespace std;

int N, M;

int main()
{
    scanf("%d %d", &N, &M);
    int S[100001] = {};

    for(int i = 1; i <= N; i++){
        int temp;
        scanf("%d", &temp);
        S[i] = S[i - 1] + temp;
    }

    for(int i = 0; i < M; i++){
        int start, end;
        scanf("%d %d", &start, &end);
        cout << S[end] - S[start - 1] << "\n";
    }
}
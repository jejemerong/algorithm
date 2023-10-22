#include <iostream>

using namespace std;

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    int Arr[N + 1][N + 1];

    // DP 배열 초기화
    for(int i = 0; i <= N; i++){
        // 순서 상관 ㄴㄴㄴㄴ
        // TODO: 근데 왜 i 가 0 일 때는 왜 1이지? `Arr[i][1] = i;` 때문에 0 이 되어야 하는 거 아닌가?
        Arr[i][0] = 1;
        Arr[i][i] = 1;
        Arr[i][1] = i;
    }

    for(int i = 2; i <= N; i++){
        for(int j = 1; j < i; j++){ // 조건 j < i 주의
            Arr[i][j] = Arr[i - 1][j] + Arr[i - 1][j - 1];
        }
    }
    cout << Arr[N][K];
}
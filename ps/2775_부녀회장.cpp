#include <iostream>

using namespace std;

static int Wohnung[15][15];

int main()
{
    int T, K, N;
    // 바로 테스트케이스 입력 받는게 아니라 배열 초기화부터
    for(int i = 0; i < 15; i++){
        Wohnung[i][1] = 1;
        Wohnung[0][i] = i;
    }
    for(int i =1; i < 15; i++){
        for(int j = 2; j < 15; j++){
            Wohnung[i][j] = Wohnung[i-1][j] + Wohnung[i][j-1];
        }
    }

    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d\n%d", &K, &N);
        printf("%d\n", Wohnung[K][N]);
    }
}
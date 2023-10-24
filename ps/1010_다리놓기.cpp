#include <iostream>

using namespace std;

int main()
{
    // 미리 만들어놓고 하기
    int Bridge[31][31];
    for(int i = 0; i <= 30; i++){
        Bridge[i][i] = 1;
        Bridge[i][0] = 1;
        Bridge[i][1] = i;
    }
    for(int i = 2; i <= 30; i++){
        for(int j = 1; j < i; j++){
            Bridge[i][j] = Bridge[i - 1][j] + Bridge[i - 1][j - 1];
        }
    }
    int T, N, M;
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%d %d", &N, &M);
        cout << Bridge[M][N] << "\n";
    }
}

// 입력 받을 때 같이 만들기
// {
//     int T, N, M;
//     scanf("%d", &T);

//     for(int i = 0; i < T; i++){
//         scanf("%d %d", &N, &M);

//         int Bridge[M+1][M+1];
//         for(int a = 0; a <= M; a++){
//             Bridge[a][a] = 1;
//             Bridge[a][0] = 1;
//             Bridge[a][1] = a;
//         }
//         for(int j = 2; j <= M; j++){
//             for(int k = 1; k < j; k++){
//                 Bridge[j][k] = Bridge[j - 1][k - 1] + Bridge[j - 1][k];
//             }
//         }
//         cout << Bridge[M][N]<< "\n";
//     }
// }
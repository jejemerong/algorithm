#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    vector<vector <int > > num(N + 1, vector<int >(N + 1, 0));
    vector<vector <int > > sum(N + 1, vector<int >(N + 1, 0));

    for(int i = 1; i <= N; i++){
        for(int j =1; j <= N; j++){
            int temp;
            scanf("%d", &temp);
            num[i][j] = temp;
            // 구간 합 배열 구하기
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + num[i][j];
        }
    }

    for(int k = 0; k < M; k++){
        int i1, i2, j1, j2;
        scanf("%d %d %d %d", &i1, &j1, &i2, &j2);
        // 해당 범위 구간 합 구하기
        int result = sum[i2][j2] - sum[i1-1][j2] - sum[i2][j1-1] + sum[i1-1][j1-1];
        cout << result << "\n";
    }
}
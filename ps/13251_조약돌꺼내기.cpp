#include <iostream>

using namespace std;


int main()
{
    int M, K, sum = 0;
    double result = 0;
    scanf("%d", &M);
    int eachColor[51];
    for(int i = 0; i < M; i++){
        scanf("%d", &eachColor[i]);
        sum += eachColor[i];
    }
    // 확률: Sum(stones[i]Ck) / sumCk
    int stones[sum][K];
    for(int i = 0; i <= sum; i++){
        for(int j = 0; j <= K; j++){
            stones[i][i] = 1;
            stones[i][0] = 1;
            stones[i][1] = i;
        }
    }
    for(int i = 2; i <= sum; i++){
        for(int j = 1; j <= K; j++){
            stones[i][j] = stones[i-1][j] + stones[i-1][j-1];
        }
    }
}
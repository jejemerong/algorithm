#include <iostream>

using namespace std;

int main()
{
    int M, K, sum = 0;
    double result = 0;
    scanf("%d", &M);
    int colors[M];
    for(int i = 0; i < M; i++){
        scanf("%d", &colors[i]);
        sum += colors[i];
    }
    scanf("%d", &K);
    for(int i = 0; i < M; i++){
        // 조건문에 따라 probability 의 값 할당이 달라짐!
        double probability = 0.0;
        if(colors[i] >= K){
            probability = 1.0;
            for(int j = 0; j < K; j++){
                probability *= (double)(colors[i] - j) / (sum - j);
            }
        }
        // double probability = 1.0;
        // if(colors[i] < K) continue;
        // for(int j = 0; j < K; j++){
        //     probability *= (double)(colors[i] - j) / (sum - j);
        // }
        result += probability;
    }
    cout << fixed;
    cout.precision(9);
    cout << result;

    return 0;
}
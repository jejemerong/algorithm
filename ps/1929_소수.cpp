#include <iostream>

using namespace std;

int main()
{
    // Init
    int M, N;
    scanf("%d %d", &M, &N);

    vector<int> Arr(N+1); // 인덱스 1부터 N 까지 넣을거라 길이가 N + 1 인 벡터 필요

    for(int i = 2; i <= N; i++){
        Arr[i] = i;
    }

    // Iter
    for(int i = 2; i <= sqrt(N); i++){ // N 의 약수는 N 제곱근 보다 클 수 없음을 이용
        if(Arr[i] == 0) continue;
        for(int j = i + i; j <= N; j = j + i){
            Arr[j] = 0;
        }
    }

    // Print
    for(int i = M; i <= N; i++){
        if(Arr[i] != 0){
            cout << Arr[i] << "\n";
        }
    }
}
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    int M, N;
    scanf("%d\n%d", &M, &N);
    int arr[10001] = {0};
    int result = 0;
    queue <int> acc;

    for(int i = M; i <= N; i++){
        arr[i] = i;
    }

    for(int i = 2; i <= sqrt(N); i++){
        for(int j = i + i; j <= N; j = j + i){
            if(arr[j] == 0){
                continue;
            }
            arr[j] = 0;
        }
    }

    for(int i = M; i <= N; i++){
        if(arr[i] != 0){
            acc.push(i);
            result += i;
        }
    }

    if(result > 0){
        cout << result << "\n" << acc.front();
    } else {
        cout << -1;
    }
    return 0;
}
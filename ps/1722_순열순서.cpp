#include <iostream>

using namespace std;

static long F[21], S[21];
static bool visited[21] = {false};

int main()
{
    int N, Q;
    scanf("%d\n%d", &N, &Q);
    F[0] = 1;

    for(int i = 1; i <= N; i++){
        F[i] = F[i-1] * i;
    }
    if(Q == 1){
        long K;
        scanf("%ld", &K);
        for(int i = 1; i <= N; i++){
            for(int j = 1, cnt =1; j <= N; j++){
                if(visited[j]) continue;
                if(K <= cnt * F[N - i]){
                    K -= ((cnt - 1) * F[N - i]);
                    S[i] = j;
                    visited[j] = true;
                    break;
                }
                cnt++;
            }
        }
        for(int i = 1; i <= N; i++){
            printf("%ld ", S[i]);
        }
    }
    else {
        long K = 1;
        for(int i = 1; i <= N; i++){
            scanf("%ld", &S[i]);
            long cnt = 0;

            for(int j = 1; j < S[i]; j++){
                if(visited[j] == false){
                    cnt++;
                }
            }
            K += cnt * F[N - i];
            visited[S[i]] = true;
        }
        printf("%ld\n", K);
    }
}
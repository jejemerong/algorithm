#include <iostream>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    int n, num;
    scanf("%d\n%d", &n, &num);
    int N = n*n;
    // printf("%d", N);

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int Arr[n][n];

    int count = 0;
    int index = 0;
    int x = 0;
    int y = 0;
    int u, v;

    while(count < N){
        if(count % n){
            count += 1;
            index += 1;
        }
        count = count + 1;
        Arr[x][y] = N - count + 1;
        x += dx[index % 4];
        y += dy[index % 4];

        if((N - count + 1) == num){
            // printf("x: %d, y: %d", x, y);
            u = x + 1;
            v = y + 1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", Arr[i][j]);
        }
        cout << "\n";
    }
    printf("%d %d", u, v);
}
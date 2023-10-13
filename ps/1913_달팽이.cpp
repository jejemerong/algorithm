#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    int n, num; // 입력값
    scanf("%d\n%d", &n, &num);
    int Arr[n][n]; // 달팽이 배열

    // 방향 배열
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int value = n*n; // 배열 요소 값
    int index = 0; // 방향 기준 값
    int iter = n; // 모서리를 이룰 만큼의 반복 횟수
    int count = 0; // 모서리 반복 기준 값
    int x = -1; // x 좌표
    int y = 0; // y 좌표
    int u, v; // 찾아야 하는 값 좌표

    while(value > 0){
        for(int i = 0; i < iter; i++){
            x += dx[index % 4];
            y += dy[index % 4];
            Arr[x][y] = value;

            if(value == num){
                u = x + 1;
                v = y + 1;
            }

            value--;
        }

        if(count % 2 == 0){
            count = 1;
            iter--;
        } else {
            count++;
        }

        index++;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << Arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << u << " " << v;
}
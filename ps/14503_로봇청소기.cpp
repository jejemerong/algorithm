#include <iostream>
#include <vector>

using namespace std;

#define MAX 50
int roomMap[MAX][MAX];
int isVisited[MAX][MAX];

static int N, M;
static int r, c, d;
static int visitedCount;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void DFS(int r, int c, int d)
{
    for(int i = 0; i < 4; i++){
        int next_d = (d+3-i) % 4; // 처음 방향에 대해서 1 2 3 4로 가르기
        int next_r = r + dx[next_d];
        int next_c = c + dy[next_d];

        if(next_r < 0 || next_r >= N || next_c < 0 || next_c >= M || roomMap[next_r][next_c] == 1){
            continue;
        }

        if(roomMap[next_r][next_c] == 0 && isVisited[next_r][next_c] == 0){
            isVisited[next_r][next_c] = 1;
            r = next_r;
            c = next_c;
            d = next_d;
            visitedCount++;
            DFS(r, c, d);
        }
    }

    int back_idx = d > 1 ? d - 2 : d + 2;
    int back_r = r + dx[back_idx];
    int back_c = c + dy[back_idx];
    if (back_r >= 0 && back_r <= N || back_c >= 0 || back_c <= M)
    {
        if (roomMap[back_r][back_c] == 0)
        {
            r = back_r;
            c = back_c;
            DFS(r, c, d);
        }
        else
        {
            cout << visitedCount << endl;
            exit(0);
        }
    }
}

int main()
{
    // Init
    scanf("%d %d", &N, &M); // 1 1 0
    scanf("%d %d %d", &r, &c, &d); // 7 4 0
    // vector 말고 int 배열로?
    // vector<int> roomState(M, 0);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &roomMap[i][j]);
        }
    }

    isVisited[r][c] = 1;
    visitedCount++;

    // DFS
    DFS(r, c, d);
    return 0;
}
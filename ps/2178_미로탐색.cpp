#include <iostream>
#include <string>
#include <queue>

using namespace std;

static int N, M;
static int Miroh[100][100];
static int dist[100][100];
static int isVisited[100][100] = {0};
void BFS(int x, int y);

int main()
{
    // Init
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        string row;
        cin >> row; 
        // cin 으로 안하면 SEGFAULT 런타임 에러 뜸.
        // string row;
        // scanf("%s", const_cast<char*>(row.c_str()));
        for(int j = 0; j < M; j++){
            Miroh[i][j] = row[j] - '0'; // 숫자로 변환
        }
    }

    // Search
    BFS(0, 0);
    return 0;
}

void BFS(int startX, int startY)
{
    int dirX[4] = {1, 0, -1, 0};
    int dirY[4] = {0, 1, 0, -1};
    // int count = 1; // 얘는 BFS 호출 단계에서 또 다른 초기화가 필요하지 않기 때문에
    dist[startX][startY]++;

    queue<pair<int, int> > myqueue;
    isVisited[startX][startY] = 1;
    myqueue.push(make_pair(startX, startY));
    // myqueue.push(make_pair(x+1, y));
    // myqueue.push(make_pair(x, y+1)); 너무 앞서갔다

    while(!myqueue.empty()){

        
        int curX = myqueue.front().first;
        int curY = myqueue.front().second;

        myqueue.pop();

        // 해당 좌표의 인접 행렬 조사
        for(int i = 0; i < 4; i++){
            // printf("왜 안들어오나");
            int x = curX + dirX[i];
            int y = curY + dirY[i];
            // 1. 범위 내 존재 여부, 2. 이동 가능 여부, 3. 방문 여부
            if((0 <= x && x < N) && (0 <= y && y < M) && (Miroh[x][y] == 1) && (!isVisited[x][y])){
                isVisited[x][y] = 1; // TODO: 근데 Miroh[x][y] == 0 이라도 조사는 다시 안하게 표시할 수 있잖아
                myqueue.push(make_pair(x, y));
                dist[x][y] = dist[curX][curY] + 1;
                // count++;
            }
        }
    }

    cout << dist[N-1][M-1];
}
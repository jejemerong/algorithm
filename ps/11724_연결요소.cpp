#include <iostream>
#include <vector>

using namespace std;

// Type Def
static vector<vector <int > > Graph;
static vector<bool> isVisited;

// TODO: DFS static 먼저 선언해서 밑에 작성해도 되게끔
void DFS(int v, int count)
{
    if(isVisited[v]) return; // 만약 방문한 노드면 나가세용
    isVisited[v] = true;

    for(int i = 0; i < Graph[v].size(); i++){
        int y = Graph[v][i]; // 이 노드의 연결된 노드 차례로 방문
        if(isVisited[y] == false) {
            count++;
            DFS(y, count);
        }
    }
}

int main() 
{
    // Init
    int N, M;
    scanf("%d %d", &N, &M);
    Graph.resize(N + 1);
    isVisited = vector<bool> (N+1, false);

    // vector Init
    for(int i = 0; i < M; i++){ //연결된 엣지 개수만큼
        int u, v;
        scanf("%d %d", &u, &v);
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    int count = 0;

    for(int i = 1; i < isVisited.size(); i++) { // 첫번째 노드부터 조사
        if(!isVisited[i]){
            count++;
            DFS(i, count);
        }
    }

    printf("%d", count);
    return 0;
}
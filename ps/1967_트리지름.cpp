#include <iostream>
#include <vector>

using namespace std;

typedef pair <int, int> edge;
static vector<vector<edge> > graph;
static vector<bool> isVisited;
static int point, diameter; // 가장 먼 거리의 노드와 그 거리

void DFS(int index, int dist);

int main ()
{
    int N;
    scanf("%d", &N);

    graph.resize(N+1);
    isVisited.resize(N+1, false);

    for(int i = 1; i < N; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    DFS(1, 0); // 처음은 거리 0 으로 시작
    // 방문 배열 및 먼 거리 초기화
    diameter = 0;
    fill(isVisited.begin(), isVisited.end(), false); // 초기화
    DFS(point, 0);
    cout << diameter <<"\n";
    return 0;
}

void DFS(int node, int dist)
{
    isVisited[node] = true;

    if(dist > diameter){ // 마지막 먼 노드보다 먼 거리가 나타났다 하면 바꿔줌.
        point = node;
        diameter = dist;
    }
    // point 설정해주기 
    // -> 설정하는 기준은 이때까지 거리와 비교해서 가장 거리가 먼 노드 point 와 거리 diameter 를 담아줘야 함.
    for(int i = 0; i < graph[node].size(); i++){
        int cur_node = graph[node][i].first;
        int cur_dist = graph[node][i].second + dist; // 누적된 distance 인자값 받아오기

        if(!isVisited[cur_node]){
            isVisited[cur_node] = true;
            DFS(cur_node, cur_dist);
        }
    }
}

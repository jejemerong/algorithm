#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<int> > Graph;
static int N, M, start;
static vector<bool> isVisited;

void DFS(int node);
void BFS(int node);

int main() {
    scanf("%d %d %d", &N, &M, &start);
    Graph.resize(N + 1);
    for(int i = 0; i < M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    for(int i = 1;i <= N; i++){
        sort(Graph[i].begin(), Graph[i].end());
    }

    isVisited = vector<bool> (N+1, false);

    DFS(start);
    printf("\n");

    fill(isVisited.begin(), isVisited.end(), false);

    BFS(start);
    printf("\n");

    return 0;
}

void DFS(int node)
{
    printf("%d ", node);
    isVisited[node] = true;
    for(int i = 0; i < Graph[node].size(); i++){
        int y = Graph[node][i];
        if(!isVisited[y]){
            DFS(y);
        }
    }
}

void BFS(int node)
{
    queue<int> myqueue;
    myqueue.push(node);
    isVisited[node] = true;
    
    while(!myqueue.empty()){
        int curNode = myqueue.front();
        myqueue.pop();
        printf("%d ", curNode);
        for(int i = 0; i < Graph[curNode].size(); i++){
            int y = Graph[curNode][i];
            if(!isVisited[y]){
                isVisited[y] = true;
                myqueue.push(y);
            }
        }
    }
}
#include <iostream>
#include <vector>

using namespace std;

// Type Def
static vector<vector<int > > Graph;
static vector <bool> isVisited;

void DFS(int v, int count) {
    if(isVisited[v]) return;
    isVisited[v] = true;

    for(int i = 0; i < Graph[v].size();i++){
        int y = Graph[v][i];
        if(isVisited[y] == false) {
            DFS(y, count);
        }
    }
}

int main()
{
    // Init
    int N, M;
    scanf("%d %d", &N, &M);
    int count = 0;
    Graph.resize(N + 1);
    isVisited = vector<bool>(N+1, false);

    // vector Init
    int u, v;
    for(int i = 0; i < M; i++){
        scanf("%d %d", &u, &v);
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    // Iter
    for(int i = 1; i < N + 1; i++){
        if(!isVisited[i]) {
            count++;
            DFS(i, count);
        }
    }

    // Print
    cout << count;
}
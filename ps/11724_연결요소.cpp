#include <iostream>
#include <vector>

using namespace std;

// Type Def
static vector<vector<int > > Node;
static vector <bool> isVisited;

void DFS(int v);

int main()
{
    // Init
    int N, M;
    scanf("%d %d", &N, &M);
    int count = 0;
    Node.resize(N + 1);
    isVisited = vector<bool>(N+1, false);

    // vector Init
    int u, v;
    for(int i = 0; i < M; i++){
        scanf("%d %d", &u, &v);
        Node[u].push_back(v);
        Node[v].push_back(u);
    }

    // Iter
    for(int i = 1; i < N + 1; i++){
        if(!isVisited[i]) {
            count++;
            DFS(i);
        }
    }

    // Print
    cout << count;
}

void DFS(int v) {
    if(isVisited[v]){
        return;
    }

    isVisited[v] = true;

    for(int i : Node[v]){
        if(isVisited[i] == false){
            DFS(i);
        }
    }
}   
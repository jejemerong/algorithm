#include <vector>
#include <iostream>
using namespace std;

int nodes, edges, virus;
bool visited[101];
vector<vector<int> > graph;

void dfs (int x) {
    visited[x] = true;
    // cout << "x ===> " << x  << endl;
    for (int i = 0; i < graph[x].size(); i++){
        int y = graph[x][i];
        // cout << "y ===>" << y << endl;
        if(!visited[y]){
            virus++;
            dfs(y);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &nodes);
    scanf("%d", &edges);
    graph.resize(nodes + 1); // 노드 갯수만큼 크기 설정!!

    int n, m;
    for (int i = 0; i < edges; i++){
        scanf("%d %d", &n, &m);
        graph[n].push_back(m);
        graph[m].push_back(n);
    }
    dfs(1);
    printf("%d\n", virus);
    return 0;
}
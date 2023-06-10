#include <iostream>
using namespace std;
 
int main(){
    // n: vertices 개수
    // m: edges 개수
    int n, m;
    cin >> n >> m;
    
    int adjMat[n + 1][n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
        // for a directed graph with an edge pointing from u
        // to v,we just assign adjMat[u][v] as 1
    }

    return 0;
}
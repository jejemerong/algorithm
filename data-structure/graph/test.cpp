#include <iostream>
using namespace std;
 
int main()
{
    // n is the number of vertices
    // m is the number of edges
    int n, m;
    cin >> n >> m;
    int adjMat[n + 1][n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // 연결되어있는 edge 는 해당 행렬의 값은 1
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }

    for(int j = 0; j < n; j++) {
        for(int k = 0; k < m; k++) {
            cout << "n is "<< n << " || m is " << m << endl;
            cout << adjMat[j][k];
        }   
    }
    return 0;
}
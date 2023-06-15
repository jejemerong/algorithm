#include <iostream>
 
using namespace std;
 
int node, edge;
int adj[10][10];
 
int main(){
    cin >> node >> edge;
 
    for(int i = 0; i < edge; i++)
    {
        int a, b; cin >> a >> b;
 
        // 무향 그래프이기 때문에 간선과 연결되어 있는 노드를 모두 true 처리
        adj[a][b] = 1;
        adj[b][a] = 1;
        
    }
    
}

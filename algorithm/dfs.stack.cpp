#include <iostream>
#include <stack>
using namespace std;

vector<int> graph[9];
stack<int> unvisited;
vector<bool> visited(9, false);

void dfs(int x) {
    int current = x;
    unvisited.push(current);
    visited[current] = true;

    while(!unvisited.empty()) {
        current = unvisited.top();
        cout << current << endl;
        visited[current] = true;
        unvisited.pop();
        for(int i: graph[current]){
            if(!visited[i]) {
                unvisited.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    // 노드 1에 연결된 노드 정보 저장 
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);
    
    // 노드 2에 연결된 노드 정보 저장 
    graph[2].push_back(1);
    graph[2].push_back(7);
    
    // 노드 3에 연결된 노드 정보 저장 
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);
    
    // 노드 4에 연결된 노드 정보 저장 
    graph[4].push_back(3);
    graph[4].push_back(5);
    
    // 노드 5에 연결된 노드 정보 저장 
    graph[5].push_back(3);
    graph[5].push_back(4);
    
    // 노드 6에 연결된 노드 정보 저장 
    graph[6].push_back(7);
    
    // 노드 7에 연결된 노드 정보 저장 
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);
    
    // 노드 8에 연결된 노드 정보 저장 
    graph[8].push_back(1);
    graph[8].push_back(7);
    
    
    dfs(1);
}
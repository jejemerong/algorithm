#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * 1. 인접 리스트: (인접 노드, 방향, 가중치) 저장
 * 2. 시작 노드에서 i 번째 노드까지 인접 노드에 대한 조합 값 조사 (방향, 가중치)
 * 3. 해당 배열 정렬하여 최단 경로 출력
*/

int vertices, edges, start;
int x, y, z;
vector<vector<vector<int> > > graph; // 가중치 포함
// TODO: vector 말고 queue 로 풀어보기
vector<int> minArr;

#define INF

void dijkstra (int start, int vertices, vector<vector<vector<int>>>&graph) {
    minArr[0] = 0;
    minArr.resize(vertices);
    for(int i = 0; i < vertices; i++){
        if(graph[start][i].size() > 0) {
            minArr[i] = graph[start][i].at(0); // v.[i] (operator []) 써도 
            cout << minArr[i] << "\n";
        }else {
            cout << INF"\n";
        }
    }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
//   freopen("input.txt", "r", stdin);

  scanf("%d %d", vertices, edges);
  scanf("%d", start);
  graph.resize(vertices+1);
  for(int i = 0; i < edges; i++){
    scanf("%d %d %d", x, y, z);
    graph[x][y].push_back(z);
  }

  dijkstra(start, vertices, graph);
  return 0;
}
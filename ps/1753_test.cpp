#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int vertices, edges, start;
int x, y, z;
vector<vector<pair<int, int> > > graph; // 가중치 포함 => pair 이용!!!
int minArr[20010];

#define INF 987654321

void dijkstra (int start, int vertices, vector<vector<pair<int, int> > >&graph) {
  priority_queue<pair<int, int> > isVisited;
  for(int i =1 ; i <= vertices; i++){
    minArr[i] = INF;
  }
  minArr[start] = 0;
  isVisited.push(make_pair(0, start));
  while(isVisited.empty() == 0){
    int current = isVisited.top().second;
    int cost = -isVisited.top().first;
    isVisited.pop();
    
    for(int i = 0; i < graph[current].size(); i++){
      int next = graph[current][i].first;
      int nextDistance = graph[current][i].second;
      if(nextDistance+cost < minArr[next]){
        minArr[next] = nextDistance+cost;
        isVisited.push(make_pair(-minArr[next], next));
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);
  scanf("%d %d", &vertices, &edges);
  scanf("%d", &start);

  graph.resize(vertices+1);
  for(int i = 0; i < edges; i++){
    scanf("%d %d %d", &x, &y, &z);
    graph[x].push_back(make_pair(y, z));
  }

  dijkstra(start, vertices, graph);
  for(int i = 1; i <= vertices; i++) {
    if(minArr[i] == INF) {
      printf("INF\n");
    }else {
      printf("%d\n", minArr[i]);
    }
  }
  return 0;
}
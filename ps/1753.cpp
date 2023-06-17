#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 99999999

int v, e, start;
int x, y, z;
vector<vector<pair <int, int > > > graph;
int minArr[20010]; // TODO: minArr 의 MAX 길이 기준

void dijkstra(){
  priority_queue<pair<int, int> > disNode;

// TODO: 초기값 다 INF 말고 인접 노드 대로 넣을 순 없나?
  for(int i = 1; i <= v; i++){
    minArr[i] = INF;
  }

  minArr[start] = 0;
  disNode.push(make_pair(0, start)); // 거리가 우선으로 정렬되기 위해 0이 앞에 옴.

  while(!disNode.empty()){
    // 현재 방문 노드와 현재의 최단 경로
    int current = disNode.top().second; // 인접 노드 정보
    int distance = -disNode.top().first; // 최소 힙으로 저장된(-) 해당 노드의 최단 거리를 양수로
    disNode.pop(); // 큐에서 제거
    for(int i = 0; i < graph[current].size(); i++){
      int next = graph[current][i].first; // 인접 노드 정보
      int nextDistance = graph[current][i].second; // 가중치
      if(minArr[next] > nextDistance + distance) { // 현재 저장된 최단 거리와 인접 노드 가중치를 계산한 값 비교
        minArr[next] = nextDistance + distance; // 맞다면 대체
        disNode.push(make_pair(-minArr[next], next)); // 최소 힙으로 큐에 추가
      }
    }
  }
}

int main(){
  // freopen("input.txt", "r", stdin);
  scanf("%d %d", &v, &e);
  scanf("%d", &start);

  graph.resize(v + 1);
  for(int i = 0 ; i < e; i++){
    scanf("%d %d %d", &x, &y, &z);
    graph[x].push_back(make_pair(y, z));
  }

  dijkstra();
  for(int i = 1; i <= v; i++){
    if(minArr[i] == INF) {
      printf("INF\n");
    }else {
      printf("%d\n", minArr[i]);
    }
  }
  return 0;
}
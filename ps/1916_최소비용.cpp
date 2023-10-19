#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000000

static int N, M, start_index, end_index;
typedef pair<int, int> edge;
static vector<vector<edge> > path;
static vector<bool> visited;
static vector<int> dist;

int dijkstra(int start_node, int end_node);

int main() 
{
    // 노드 개수, 간선 개수 입력 받기
    scanf("%d\n%d", &N, &M);
    dist.resize(N + 1);
    fill(dist.begin(), dist.end(), INF);
    visited.resize(N + 1);
    fill(visited.begin(), visited.end(), false);
    path.resize(N + 1);

    // 간선 정보 입력 받기
    for(int i = 0; i < M; i++){
        int start, end, weight;
        scanf("%d %d %d", &start, &end, &weight);
        path[start].push_back(make_pair(end, weight));
    }

    scanf("%d %d", &start_index, &end_index);

    int result = dijkstra(start_index, end_index);
    cout << result;

    return 0;
}

int dijkstra(int start_node, int end_node)
{
    // TODO: 우선순위 큐 오름차순 설정 방법 및 기본 값
    // priority_queue <edge> myqueue;
    priority_queue<edge, vector<edge>, greater<edge> > myqueue;
    // 출발 노드는 곧 자기 자신이므로 거리가 0인 것을 이용하여 초기값 설정
    myqueue.push(make_pair(0, start_node));
    dist[start_node] = 0;

    while(!myqueue.empty())
    {
        edge cur_data = myqueue.top(); // 거리가 가장 작은 노드 번호
        myqueue.pop();
        int cur_node = cur_data.second;

        if(!visited[cur_node]){ // 가장 작은 거리의 노드에 방문 안했다면
            visited[cur_node] = true;
            for(int i = 0; i < path[cur_node].size(); i++){ // 그와 연결된 노드들을 탐색하라
                edge n = path[cur_node][i];
                if(!visited[n.first] && dist[n.first] > dist[cur_node] + n.second){
                    dist[n.first] = dist[cur_node] + n.second;
                    myqueue.push(make_pair(dist[n.first], n.first));
                }
            }
        }
    }
    
    return dist[end_node];
}

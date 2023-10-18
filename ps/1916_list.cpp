#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000
#define INF 1000000000
typedef pair<int, int> edge;
static vector<vector<edge> > path; // 각 경로에 대한 비용 배열
static vector<int> dist;
static vector<bool> visited;
static int N, M, start_node, end_node;
int dijkstra(int start, int end);

int main()
{
    scanf("%d\n%d", &N, &M);
    dist.resize(N + 1);
    fill(dist.begin(), dist.end(), INF);
    visited.resize(N + 1);
    fill(visited.begin(), visited.end(), false);
    path.resize(N + 1);

    for(int i = 0; i < M; i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        path[x].push_back(make_pair(y, z));
    }
    scanf("%d %d", &start_node, &end_node);
    int result = dijkstra(start_node, end_node);
    cout << result;
}

int dijkstra(int start, int end)
{
    priority_queue<edge, vector<edge>, greater<edge> > myqueue;
    myqueue.push(make_pair(0, start)); // 비용이 우선순위 큐에서 계산되어야 하므로 앞에 놓는다.
    dist[start] = 0;
    while(!myqueue.empty()){
        edge cur_node = myqueue.top();
        myqueue.pop();
        int now = cur_node.second; // 비용이 가장 적은 노드부터 조사
        if(!visited[now]){
            visited[now] = true;
            for(int i = 0; i < path[now].size(); i++){
                edge n = path[now][i];
                if(!visited[n.first] && dist[n.first] > dist[now] + n.second){
                    dist[n.first] = dist[now] + n.second;
                    myqueue.push(make_pair(dist[n.first], n.first));
                }
            }
        }
    }
    return dist[end];
}

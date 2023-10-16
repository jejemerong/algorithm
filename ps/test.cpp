#include <iostream>
#include <vector>

using namespace std;
typedef pair <int, int> edge;
static int N;
static vector<vector<edge > > Graph;
static vector<bool> isVisited;
static int node; // 임의의 노드, 가장 거리가 먼 노드
static int ans; // 최대 거리

void DFS(int index, int dist);

int main()
{
    // Init
    // freopen("input.txt", "r", stdin);
    scanf("%d", &N); // 노드 개수
    Graph.resize(N+1);
    isVisited.resize(N+1, false);
    
    for(int i = 1; i < N; i++){ // 루트 노드 번호는 항상 1이며, N - 1 로 간선의 개수가 정해져서 들어옴.
        int p, c, v;
        scanf("%d %d %d", &p, &c, &v); // 부모, 자식, 가중치
        Graph[p].push_back(make_pair(c, v));
        Graph[c].push_back(make_pair(p, v));
    }


    // Search 
    DFS(1, 0); // 임의의 노드 1
    ans = 0;
    // for(int i = 0; i < isVisited.size(); i++){
    //     isVisited[i] = false;
    // }
    fill(isVisited.begin(), isVisited.end(), false); // 방문 배열 초기화
    DFS(node, 0);
    cout << ans << "\n";
    return 0;
}

// 1. 임의의 노드에서 가장 먼 거리 측정
// 2. 가장 먼 노드에서 다시 출발
// 3. 그 노드에 대해 가장 먼 노드의 거리 출력 => 트리 지름
// TODO: DFS 로 하는 이유가? -> 다시 호출해야 해서 그런건가?
void DFS(int index, int dist) // index: 출발 노드, dist: 최근 거리
{
    // 노드 들어오면 방문 처리 
    isVisited[index] = true;

    if(dist > ans){ // 가장 먼 거리의 노드인지 조사
        node = index;
        ans = dist; 
    }

    for(int i = 0; i < Graph[index].size(); i++){
        int cur_node = Graph[index][i].first; // 인접 노드 조사
        int cur_dist = Graph[index][i].second + dist;

        if(!isVisited[cur_node]){ // 해당 노드가 방문 안했으면 거리 업데이트하고 
            isVisited[cur_node] = true;
            DFS(cur_node, cur_dist); // 현재 노드에 대한 인접 노드를 조사하기 위해, 거리 정보는 현재 노드에 대한 가중치를 더한 값으로
            
            isVisited[cur_node] = false; 
            // TODO: false 로 처리하는 이유 DFS 처리하고 난 다음 때문인가? -> 재귀 처리 후에 어떻게 되는지 잘 모르겠다.
            // for 문으로 나가기 전에 초기화하는건가
        }
    }
}
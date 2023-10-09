#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> edge;
static vector<vector <edge> > Graph;
static vector<bool> isVisited;
static vector<int> distance;
void BFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 노드 개수
    cin >> N;
    // scanf("%d", &N);
    Graph.resize(N+1);
    
    for(int i = 0; i < N; i++){
        int P; // parent
        // scanf("%d", &P);
        cin >> P;
        while(true){ 
            int C, V; // children, value
            // scanf("%d", &C); //  일단 들여보내고 판단
            cin >> C;
            if(C == -1){ // 끝이 -1 일 때, 멈추도록
                break;
            }
            // scanf("%d", &V);
            cin >> V;
            Graph[P].push_back(edge(C, V));
        }
    }

    ::distance = vector<int> (N+1, 0);
    isVisited = vector<bool> (N+1, false);
    BFS(1); // 임의의 노드에서 출발
    int Max = 1; // 일단 1부터 시작~!

    for(int i = 2; i <= N; i++){ // TODO: 인덱스 범위
        if(::distance[Max] < ::distance[i]){
            Max = i;
        }
    }
    
    fill(::distance.begin(), ::distance.end(), 0);
    fill(isVisited.begin(), isVisited.end(), false);

    BFS(Max); // 가장 거리가 긴 노드부터 다시 실행

    sort(::distance.begin(), ::distance.end());
    cout << ::distance[N] << "\n"; // 가장 큰 값이 맨 뒤로 가므로 해당 값은 N 으로 찾음.
    
    return 0;
}

void BFS(int index)
{
    queue<int> myqueue;
    myqueue.push(index);
    isVisited[index] = true;

    while(!myqueue.empty()){
        int curNode = myqueue.front();
        myqueue.pop();
        for(int j = 0; j < Graph[curNode].size(); j++){
            edge i = Graph[curNode][j];
            if(!isVisited[i.first]){
                isVisited[i.first] = true;
                myqueue.push(i.first);
                ::distance[i.first] = ::distance[curNode] + i.second;
            }
        }
    }
}
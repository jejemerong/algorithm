#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 트리의 지름: 두 노드 간의 가장 긴 거리 (가중치 포함)

typedef pair<int, int> edge;
static vector<vector <edge > > Graph;
static vector<bool> isVisited;
static vector<int> distance;
void BFS(int node);

int main()
{
    int N;
    scanf("%d", &N);
    Graph.resize(N + 1);

    for(int i = 0; i < N; i++){
        int S;
        scanf("%d", &S);
        while(true){
            int E, V;
            scanf("%d", &E);
            if(E == -1) {
                break;
            }
            scanf("%d", &V);
            Graph[S].push_back(edge(E, V));
        }
    }
    distance = vector<int> (N + 1, 0);
    isVisited = vector<bool> (N + 1, false);
    BFS(1);
    int Max = 1;

    for(int i = 2; i <= N; i++){
        if(distance[Max] < distance[i]){
            Max = i;
        }
    }
    fill(distance.begin(), distance.end(), 0);
    fill(isVisited.begin(), isVisited.end(), false);
    DFS(Max);
    sort(distance.begin(), distance.end());
    cout << distance[N] << "\n";
}

void BFS(int index)
{
    queue<int> myqueue;
    myqueue.push(index);
    isVisited[index] = true;

    while(!myqueue.empty()){
        int curNode = myqueue.front();
        myqueue.pop();
        for(edge i : Graph[curNode]){
            if(!isVisited[i.first]){
                isVisited[i.first] = true;
                myqueue.push(i.first);
                distance[i.first] = distance[curNode] + i.second;
            }
        }
    }
}
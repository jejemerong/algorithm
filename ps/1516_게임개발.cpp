#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 999999

int main()
{
    int N;
    scanf("%d", &N);
    vector<vector<int> > buildings;
    typedef pair<int, int> edge;
    vector<vector<edge> > costs;
    vector<int> result;
    // TODO: 한꺼번에 resize 하는 방법 없나
    buildings.resize(N + 1);
    costs.resize(N + 1);
    result.resize(N + 1);

    queue<int> myqueue;

    for(int i = 1; i <= N; i++){
        int num = INF;
        while(num != -1){
            if(num == INF){
                scanf("%d ", &num);
                costs[i].push_back(make_pair(0, num));
            } else {
                scanf("%d ", &num);
                if(num != -1) {
                    buildings[num].push_back(i);
                    costs[i][0].first++;
                }
            }
        }
        if(costs[i][0].first == 0) {
            myqueue.push(i);
        }
    }

    while(!myqueue.empty())
    {
        int index = myqueue.front(); // 1, 10
        myqueue.pop();
        for(int i = 0; i < buildings[index].size(); i++){
            int next_build = buildings[index][i]; // 인접 노드 번호
            // result[next_build] += costs[index][0].second;
            result[next_build] = max(result[next_build], result[index] + costs[index][0].second);
            costs[next_build][0].first--;
            if(costs[next_build][0].first == 0){
                myqueue.push(next_build);
            }
        }
        result[index] += costs[index][0].second; // 자기꺼는 맨 마지막에 넣는다
    }

    for(int i = 1; i <= N; i++){
        printf("%d\n", result[i]);
    }

    return 0;
}
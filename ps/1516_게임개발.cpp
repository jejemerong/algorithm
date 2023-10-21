#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    vector<vector<int> > buildings;
    vector<int> indegree;
    vector<int> costs;
    vector<int> result;
    // TODO: 한꺼번에 resize 하는 방법 없나
    buildings.resize(N + 1);
    indegree.resize(N + 1, 0);
    costs.resize(N + 1);
    result.resize(N + 1, 0);

    queue<int> myqueue;

    for(int i = 1; i <= N; i++){
        int num = 999999;
        scanf("%d ", &costs[i]);
        while(num > 0){
            scanf("%d ", &num);
            if(num == -1) break;
            buildings[num].push_back(i);
            indegree[i]++;
        }
        if(indegree[i] == 0) myqueue.push(i);
    }

    while(!myqueue.empty())
    {
        int current = myqueue.front();
        myqueue.pop();
        for(int i = 0; i < buildings[current].size(); i++){
            int next = buildings[current][i];
            indegree[next]--;
            result[next] = max(result[next], result[current] + costs[current]);
            if(indegree[next] == 0){
                myqueue.push(next);
            }
        }
        result[current] += costs[current];
    }

    for(int i = 1; i <= N; i++){
        printf("%d\n", result[i]);
    }

    return 0;
}
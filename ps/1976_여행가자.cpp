#include <iostream>
#include <vector>

using namespace std;

static vector<int> parents;
void unionFunc(int a, int b);
int find(int a);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int stadt [201][201];

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> stadt[i][j];
        }
    }

    int route[1001];

    for(int i =1; i <= M; i++){
        cin >> route[i];
    }
    parents.resize(N + 1);

    for(int i = 1; i <= N; i++){
        parents[i] = i;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(stadt[i][j] == 1){
                unionFunc(i, j);
            }
        }
    }

    int index = find(route[1]);
    bool isConnected = true;

    for(int i = 2; i <= M; i++){
        if(index != find(route[i])){
            cout << "NO" << "\n";
            isConnected = false;
            break;
        }
    }

    if(isConnected){
        cout << "YES" << "\n";
    }
}

void unionFunc(int a, int b)
{
    a = find(a);
    b = find(b);

    if(a != b) {
        parents[b] = a;
    }
}

int find(int a)
{
    if(a == parents[a]){
        return a;
    }
    else {
        return parents[a] = find(parents[a]);
    }
}
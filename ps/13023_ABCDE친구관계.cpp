#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int > > Friends;
static vector<bool> isVisited;
static bool isCompleted = false;

void DFS(int person, int friendCount);

int main()
{
    // Init
    int N, M;
    scanf("%d %d", &N, &M);

    // 범위 N-1 까지
    Friends.resize(N);
    isVisited = vector <bool> (N, false);

    for(int i = 0; i < M; i++){ // 사람 번호가 0번부터 시작하므로 인덱스 0 포함
        int a, b;
        scanf("%d %d", &a, &b);
        Friends[a].push_back(b);
        Friends[b].push_back(a); // 서로 친구! 한쪽만 친구는...ㄷㄹㄹ
    }

    // Iter
    for(int i = 0; i < Friends.size(); i++){
        DFS(i, 1);
        if(isCompleted){
            break;
        } 
    }

    // Print
    if(isCompleted) {
        printf("1");
    } else {
        printf("0");
    }
    return 0;
}

void DFS(int person, int friendCount)
{
    if(friendCount == 5){
        isCompleted = true;
        return;
    } 
    isVisited[person] = true; 

    for(int i = 0; i < Friends[person].size(); i++){
        int y = Friends[person][i];
        if(!isVisited[y]){
            DFS(y, friendCount + 1); // 여기서 true 처리 굳이 안해도 되는 이유는 y 가 person 으로 넘어가서 true 찍기 때문
        }
    }
    isVisited[person] = false; // main 함수에서 다시 DFS 호출할 경우 때문에 isVisited 다시 초기화해줘야 함!!!
}
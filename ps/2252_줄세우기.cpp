#include <iostream>
#include <vector>

#define INF 999999

using namespace std;
static vector<vector<int> > students; // 학생 노드 배열
static vector<int> dist; // 진입 차수 배열

int find();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    students.resize(N + 1);
    // dist init
    // students 배열을 init 하는 것이 아니라 dist 배열을 학생 수만큼 init
    dist.resize(N + 1);
    fill(dist.begin(), dist.end(), 0); // 모두 0 으로 초기화
    // students init (비교 -> 인접, 진입 차수로 대입됨.)
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        students[a].push_back(b); // 비교한 노드 -> 인접 처리
    }
    // students 배열 반복시켜 dist 배열 증가시켜주고
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < students[i].size(); j++){
            int num = students[i][j];
            dist[num]++;
        }
    }
    // dist 배열에서 다시 값 삭제하면서 최종 순위 출력
    for(int i = 0; i < N; i++){
        int num = find();
        cout << num << " ";
    }
    return 0;
}

// dist 배열에서 값이 0 인 요소의 인덱스를 반환
int find()
{
    int index = 0;
    for(int i = 1; i <= dist.size(); i++){
        if(dist[i] == 0) {
            // TODO: 얘를 INF 로 두는 것이 아니라 queue 와 방문 표시 배열을 둬야 할 듯
            dist[i] = INF; 
            index = i;
            for(int j = 0; j < students[i].size(); j++){
                if(dist[students[i][j]] > 0) dist[students[i][j]]--;
            }
            break;
        }
    }
    return index;
}
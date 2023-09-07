#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    long sum = 0;
    long result = 0; // 초기값 설정 안하니까 쓰레기값 들어감.
    vector<long > same(M, 0); // M 으로 나누니까 인덱스가 M 개까지 나올 수 있음.

    for(int i = 0; i < N; i++){
        int num = 0;
        scanf("%d", &num);
        sum += num; // 그래, sum 배열로 굳이 해줄 필요 없음.
        same[sum % M]++;
    }

    for(int i = 0; i < M; i++){
        if(same[i] > 1) {
            result = result + (same[i] * (same[i] - 1) / 2); // combination 연산
        }
    }

    cout << same[0]+ result << "\n"; // 나머지 0인 애들 더해주기
}
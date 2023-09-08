#include <iostream>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    int sum = 1;
    int result = 0;
    // 자연수 1부터 시작
    int start = 1;
    int end = 1;

    while(end <= N) { // 15일 때까지도 포함, result 를 0으로 둘 경우
        if(sum == N) {
            end++;
            sum += end;
            result++;
        }
        else if(sum > N) {
            sum -= start; // 현재까지의 합에서 현재의 start 를 버리고 다음 start 로 이동하는 것이므로 sum 변경이 먼저
            start++;
        }
        else{
            end++; // 해당 안되면 end 옮겨서 다음 sum 으로 반복 돌려야 하기 때문에 sum 변경이 뒤에
            sum += end;
        }
    }

    cout << result << "\n";
}
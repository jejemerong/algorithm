#include <iostream>

using namespace std;

/**
 * 1. 개수, 점수 배열 정의
 * 2. 최댓값 찾기 
 * 3. 합계 구하기
 * 4. 평균 계산
 * 5. 출력
*/

int main()
{
//   freopen("input.txt", "r", stdin);
    int N = 0;
    int A[1000]; // 1000보다 작거나 같으므로 
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    long sum = 0;
    long max= 0;

    for(int i = 0 ; i < N; i++){
        if(max < A[i]){
            max = A[i];
        }
        sum += A[i];
    }
    double result = sum * 100.0 / max / N; // 한꺼번에
    cout << result << "\n";

  return 0;
}
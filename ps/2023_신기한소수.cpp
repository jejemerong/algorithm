#include <iostream>

using namespace std;

// int oddNum[5] = {1, 3, 5, 7, 9};
// int firstPrime[4] = {2, 3, 5, 7};
int calNum = 0;
int digits;
int digitCount;

bool isPrime(int num) 
{
    for(int i = 2; i <= num / 2; i++)
    {
        if((num % i) == 0){
            return false;
        }
    }
    return true;
}

void DFS(int calNum, int digitCount)
{
    if(digitCount == digits) {
        if(isPrime(calNum)){
            cout << calNum << "\n";
        }
        return;
    }

    for(int i = 1; i < 10; i++)
    {
        if(i % 2 == 0){ // 홀수 배열에서 꺼내는 것말고 나머지 연산으로 짝수 걸러내는 것이 시간 초과 안걸림!
            continue;
        }
        // calNum = calNum * 10 + oddNum[i]; // 소수 판별하고 셋팅해야 하기 때문에 먼저 할당하지 않는다!
        if(isPrime(calNum * 10 + i)){
            // ++digitCount; // 후위연산으로 해도 되는지
            DFS(calNum * 10 + i, digitCount + 1); // TODO: ++연산자 쓰면 digits 가 4가 아닌데 출력되는 이유 찾기!
        }
    }
}

int main()
{
    scanf("%d", &digits);
    // int firstPrime[4] = {2, 3, 5, 7};
    
    // TODO: 하드코딩으로 DFS 돌리는 것말고 반복문 돌리면 시간 초과 나는지 확인
    // -> 시간 초과가 아니라 온전한 답 아래에 digits 4 자리가 안맞는데도 출력됨.
    // for(int i = 0; i < sizeof(firstPrime); i++)
    // {
    //     // 여기서 그냥 숫자 넘겨주는지 아니면 판별하고 넘겨주는지
    //     // -> 판별은 재귀가 되어야 하기 때문에 숫자만 넘겨주고 DFS 안에서 판별하는걸로!
    //     DFS(firstPrime[i], 1); // 일단 전자로 설계
    // }
    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);

    // for(int i = 0; i < sizeof(magicPrime); i++) {
    //     cout << magicPrime[i] << "\n"; // 이미 소수 배열이 오름차순이기 때문에 굳이 배열로 안 넣어도 됨.
    // }
}

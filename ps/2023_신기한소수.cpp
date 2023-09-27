#include <iostream>

using namespace std;

static int oddNum[5] = {1, 3, 5, 7, 9};
static int calNum = 0; // TODO: 이거 static 처리 디버깅하기
// int magicPrime[1] = {}; // array 는 배열 길이 resize 어떻게 하지?
int * magicPrime = new int[1];
static int digits;
int digitCount;

bool isPrime(int num) 
{
    for(int i = 2; i < num / 2; i++) 
    {
        if((num % i) == 0) return false;
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

    for(int i = 0; i < sizeof(oddNum); i++)
    {
        // calNum = calNum * 10 + oddNum[i]; // 소수 판별하고 셋팅해야 하기 때문에 먼저 할당하지 않는다!
        if(isPrime(calNum * 10 + oddNum[i])){
            digitCount++; // 후위연산으로 해도 되는지
            DFS(calNum * 10 + oddNum[i], digitCount);
        }
    }
}

int main()
{
    scanf("%d", &digits);
    int firstPrime[4] = {2, 3, 5, 7};
    
    for(int i = 0; i < sizeof(firstPrime); i++)
    {
        // 여기서 그냥 숫자 넘겨주는지 아니면 판별하고 넘겨주는지
        // -> 판별은 재귀가 되어야 하기 때문에 숫자만 넘겨주고 DFS 안에서 판별하는걸로!
        DFS(i, 1); // 일단 전자로 설계
    }

    // for(int i = 0; i < sizeof(magicPrime); i++) {
    //     cout << magicPrime[i] << "\n"; // 이미 소수 배열이 오름차순이기 때문에 굳이 배열로 안 넣어도 됨.
    // }
}

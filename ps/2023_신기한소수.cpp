#include <iostream>

using namespace std;

static int digitInput;

void DFS (int num, int digitCount);
bool isPrime(int num);

/**
 * digitCount 와 num 과 같은 변수들을 연산 후 할당하지 않아야 한다. 
 * 예를 들어, digitCount 변수 값을 바꿔버리면 count 가 4 까지 도달하고 나서는 초기화가 안되기 때문
 * 첫번째 소수를 인자로 넘기며 DFS 를 호출할 때만 초기화가 되는 구조로
 * 만약 함수 호출 내에서는 할당한다면 초기화가 안되기 때문에 자리수가 꼬임.
*/

int main()
{
    scanf("%d", &digitInput); // 4

    DFS(2, 1); 
    DFS(3, 1); // digitCount 초기화시켜주기
    DFS(5, 1);
    DFS(7, 1);

    return 0;
}

void DFS(int num, int digitCount)
{
    if(digitCount == digitInput){
        if(isPrime(num)){
            cout << num << "\n";
        }
    }

    for(int i = 1; i < 10; i = i + 2){ // 모듈러 연산할 필요 없이!
        if(isPrime(num * 10 + i)){ // num 또한 연산하지 않고 넘겨주기만 한다!
            // digitCount++;
            DFS(num * 10 + i, digitCount + 1);
        }
    }
}

bool isPrime(int num)
{
    for(int i = 2; i <= num / 2; i++){ // TODO: 왜 등호가 포함되는지
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}
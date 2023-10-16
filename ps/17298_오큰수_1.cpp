#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);

    // Init
    int N = 0;
    scanf("%d", &N);

    // vector<int> Arr(N, 0); // array vs vector -> 아마 시간 초과 때문에 벡터로
    int Arr[N];

    stack<int> bucket;
    bucket.push(0); // 아직 아무것도 안넣은 제일 처음에는 top 출력이 되나? -> 안돼서 스택 정의하고 초기화 0 필요 

    vector<int> resultV(N, -1);

    for(int i = 0; i < N; i++){
        scanf("%d", &Arr[i]);
    }

    // int topIndex = bucket.top(); // 스택에는 값이 아닌 인덱스를 저장한다.

    // Iter
    for(int i = 1; i < N; i++){
        // int currentNum = Arr[i]; // currentNum: 2, i: 1, 
        // int topIndex = bucket.top(); // -> 근데 이 위치에서 하면 반복문을 다 돌아버리기 때문에 반복문 돌 때, 현재 인덱스에서 스택 top 시작해야 할 듯
        // TODO: topIndex 증가를 어느 타이밍에 해야 할 지...
        while(!bucket.empty() && Arr[i] > Arr[bucket.top()]){ // 5 < 7 // 비교하는 수보다 크면서 가장 오른쪽이므로 크기만 하면 바로 반복 중단 // TODO: 가장 마지막 iter 에는 topIndex 가 4가 되는데 여기서 에러 안나나?
            resultV[bucket.top()] = Arr[i];
            bucket.pop();
            // if(Arr[i] > Arr[bucket.top()]){
            //     // printf("1====> currentNum: %d, i: %d, topIndex: %d\n", currentNum, i, topIndex);
            //     bucket.push(i); // 1
            // }else {
            //     // printf("2=====>currentNum: %d, i: %d, topIndex: %d\n", currentNum, i, topIndex);
            //     bucket.pop();
            //     break;
            // }
        }
        bucket.push(i);
        // 조건절 추가해야 할 것 같고, while 문 밖으로 나온다면 -> 오큰수가 나타났다!!
        // if(Arr[i] < Arr[bucket.top()]) {
        //     // printf("3====>currentNum: %d, topIndex: %d\n", currentNum, topIndex);
        //     resultV[i] = Arr[bucket.top()];
        // }else {
        //     // printf("4====>currentNum: %d, i: %d, topIndex: %d\n", currentNum, i, topIndex);
        // }
    }

    // Print
    for(int i = 0; i < resultV.size(); i++){
        // 굳이 -1 위에서 넣지 말고, 여기서 조건부 걸어서 -1 출력하도록
        cout << resultV[i] << " ";
    }
}
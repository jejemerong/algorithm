#include <iostream>
#include <queue>

using namespace std;

queue<int> myQueue;

int main()
{
    // Init
    int N;
    scanf("%d", &N);
    // 카드 큐 만들기
    for (int i = 1; i <= N; i++){
        myQueue.push(i);
    }

    // Iter
    while(myQueue.size() > 1){ // empty 로 하면 안됨!!
        myQueue.pop();
        myQueue.push(myQueue.front());
        myQueue.pop();
    }

    // Print
    cout << myQueue.front() << "\n";
}
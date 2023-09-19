#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    // Init
    int N;
    scanf("%d", &N);
    vector<int> num(N, 0);
    for(int i = 0; i < N; i++){
        scanf("%d", &num[i]);
    }
    stack<int> Stack;
    Stack.push(0);

    vector<int> resultV(N, -1);

    // Iter
    for(int i = 1; i < num.size(); i++){
        // int topIndex = Stack.top(); // 애를 여기서 변수로 선언하면 두번 건너뛰어 오큰수 찾는 애들이 안찾아짐
        while(!Stack.empty() && num[Stack.top()] < num[i]){ // 오큰수보다 크다! 그럼 니가 들어가셈
            resultV[Stack.top()] = num[i];
            Stack.pop();
        }
        Stack.push(i);
    }

    // Print
    for(int i = 0; i < resultV.size(); i++){
        printf("%d ", resultV[i]);
    }
}
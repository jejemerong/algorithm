#include <iostream>
#include <vector>
#include <stack>

using namespace std;
stack<int> bucket;

int main()
{
    int N = 0;
    scanf("%d", &N);

    // int Arr[N]; // 배열로 하면 메모리 초과 나서 vector 로 해야 함!!!
    vector<int> Arr(N, 0);
    vector<char> resultV; // 얘는 왜 string 안되고 char 밖에 안되지?

    bool result = true;
    int num = 1;
    for(int i = 1; i <= N; i++){
        scanf("%d", &Arr[i]); // 4 ~ 1
    }
    for(int i = 1; i <= N; i++){
        if(Arr[i] >= num){
            while(Arr[i] >= num){
                bucket.push(num++); 
                // 그냥 i 를 넣으면 최상단 iter 의 index 가 들어가야 하므로 i++ 을 넣으면 while 문 안에서 증가 연산이 된 상태로 리턴? 되기 때문에
                resultV.push_back('+'); // 더블쿼터는 에러 남. -> 인수 목록이 일치하는 오버로드된 함수 "std::__1::vector<_Tp, _Allocator>::push_back [대상 _Tp=char, _Allocator=std::__1::allocator<char>]"의 인스턴스가 없습니다.
                // printf("+\n"); 로 바로 출력하면 안되는 것이 수열 출력이 안되는 경우에는 과정 없이 그냥 NO 하나만 출력해야 하기 때문
            }
            bucket.pop();
            resultV.push_back('-');
        }else {
            int n = bucket.top();
            if(n > Arr[i]){
                printf("NO");
                result = false;
                break;
            }else {
                bucket.pop();
                resultV.push_back('-');
            }
        }
    }
    if(result) {
        for(int i = 0; i < resultV.size(); i++){
            printf("%c\n", resultV[i]);
        }
    }
    return 0;
}
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    vector<int> num(N, 0);

    for(int i = 0; i < N; i++){
        scanf("%d", &num[i]);
    }
    sort(num.begin(), num.end());

    int count = 0;
    for(int k = 0; k < N; k++){
        int i = 0;
        int j = N - 1;
        // TODO: 같은 수일 경우, 인덱스 비교 포함되어있는 부분 확인하기
        while(i < j) {
            if(num[i] + num[j] == num[k]){ // long 타입으로 안해도 됨.
                if(i != k && j != k) {
                    count++;
                    break;
                }
                else if(i == k) {
                    i++;
                } 
                else if(j == k){
                    j--;
                }
            }
            else if(num[i] + num[j] < num[k]) {
                i++;
            }
            else {
                j--;
            }
        }
    }
    cout << count << "\n";
    return 0;
}
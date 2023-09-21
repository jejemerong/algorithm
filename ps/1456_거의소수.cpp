#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    // Init
    long A, B;
    scanf("%ld %ld", &A, &B);
    long Arr[10000001];
    // vector<int> Arr(B+1);
    for(int i = 2; i <= (10000001); i++){
        Arr[i] = i;
    }
    
    // Prime Init
    for(int i = 2; i <= sqrt(10000001); i++){
        if(Arr[i] == 0) continue; // 얘는 내부 포문 밖에 있어야 험.
        for(int j = i + i; j <= (10000001); j = j + i){
            Arr[j] = 0;
        }
    }

    int result = 0;

    // Iter
    for(int i = 2; i <= (10000001); i++){
        if(Arr[i] != 0)  {
            long temp = Arr[i];
            while((double)Arr[i] <= (double)B / (double)temp){
                if((double)Arr[i] >= (double)A / (double)temp) result++;
            }
            temp = temp * Arr[i];
        }
    }

    // Print
    cout << result << "\n";
}
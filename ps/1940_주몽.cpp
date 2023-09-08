#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N; 
    long M;
    scanf("%d", &N);
    scanf("%ld", &M);

    vector <int> S(N, 0);

    for(int i = 0; i < N; i++){
        scanf("%d", &S[i]);
    }
    sort(S.begin(), S.end());

    int i = 0;
    int j = N-1;
    int count = 0;

    while(i < j) {
        if(S[i] + S[j] == M) {
            count++;
            i++;
            j--;
        }
        else if(S[i] + S[j] > M) {
            j--;
        }
        else {
            i++;
        }
    }

    cout << count << "\n";
}
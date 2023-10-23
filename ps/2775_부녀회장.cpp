#include <iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    int Test[T][2];
    // Test input
    for(int i = 0; i < T; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &Test[i][j]); // j: (0, k), (1, n)
        }
        // Complex init
        int k = Test[i][0];
        int n = Test[i][1];
        int Wohnung[k+1][n]; // k 층 n 호
        for(int a = 0; a <= k; a++){ // k
            for(int b = 1; b <= n; b++) { // n
                Wohnung[0][b] = b;
                Wohnung[a][1] = 1;
            }
        }

        for(int c = 1; c <= k; c++){
            for(int d = 2; d <= n; d++){
                Wohnung[c][d] = Wohnung[c-1][d] + Wohnung[c][d-1];
            }
        }
        cout << Wohnung[k][n] << "\n";
    }

}


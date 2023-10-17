#include <iostream>

using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x, y, count = 0;
    cin >> n;
    int paper[101][101];

    for(int N = 0; N < n; N++){
        cin >> x >> y;
        for(int i = x; i < x + 10; i++){
            for(int j = y; j < y + 10; j++){
                if(paper[i][j] != 1){
                    paper[i][j] = 1;
                    count++;
                }
            }
        }
    }
    cout << count;
}
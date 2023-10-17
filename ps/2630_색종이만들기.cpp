#include <iostream>

using namespace std;
static int N, white, blue;
static int paper[128][128];
void devideConquer(int x, int y, int side);

int main()
{
    // freopen("input.txt", "r", stdin);
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d ", &paper[i][j]);
        }
    }

    white = blue = 0;
    devideConquer(0, 0, N);

    printf("%d\n%d", white, blue);

}

void devideConquer(int x, int y, int side)
{
    bool isEmpty, isColored;
    isEmpty = isColored = true;

    for(int i = x; i < x + side; i++){
        for(int j = y; j < y + side; j++){
            // TODO: 중간에 값이 바뀌는 지점에 빠져나가려면 어떻게?
            if(paper[i][j] == 1) isEmpty = false;
            if(paper[i][j] == 0) isColored = false;
        }
    }

    if(isEmpty) { white++; return; }
    if(isColored) { blue++; return; }

    devideConquer(x, y, side / 2);
    devideConquer(x + side / 2, y, side / 2);
    devideConquer(x, y + side / 2, side / 2);
    devideConquer(x + side / 2, y + side / 2, side / 2);
}

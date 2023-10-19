#include <iostream>

using namespace std;

#define MAX 1000001
static int group[MAX];

void unionFunc(int a, int b);
int find(int a);
bool isSameGroup(int a, int b);

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    for(int i = 0; i <= N; i++){
        group[i] = i;
    }

    for(int i = 0; i < M; i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if(x == 0){
            unionFunc(y, z);
        } 
        else 
        {
            if(isSameGroup(y, z)){
                cout << "YES" << "\n";
            }
            else 
            {
                cout << "NO" << "\n";
            }
        }
    }
}

void unionFunc(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a != b){
        group[b] = a;
    }
}

int find(int a)
{
    if(a != group[a]) return group[a] = find(group[a]);
    return a;
}

bool isSameGroup(int a, int b)
{
    if(find(a) != find(b)){
        return false;
    }
    return true;
}
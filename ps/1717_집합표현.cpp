#include <iostream>
#include <vector>

using namespace std;

bool isSameUnion(int a, int b);
void unionFunc(int a, int b);
int find(int a);

static vector<int> arr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    arr.resize(n + 1);
    
    // Init: 각 노드가 대표 노드인 상태
    for(int i = 1; i <= n; i++){
        arr[i] = i;
    }

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> c >> a >> b;
        if(c == 0){ // 유니온 연산
            unionFunc(a, b);
        } else {
            if(isSameUnion(a, b)){
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
    }
}

void unionFunc(int a, int b)
{
    // TODO: 같은 변수에 재할당해도 되는건가?
    int A = find(a);
    int B = find(b);

    if(A != B) {
        arr[B] = a;
    }
}

int find(int a)
{
    // 인덱스가 같을 경우, 대표 노드이기 때문에 인덱스와 값이 같은지 확인
    if(a == arr[a]){ 
        return a;
    }
    else {
        return arr[a] = find(arr[a]);
    }
}

bool isSameUnion(int a, int b)
{
    int A = find(a);
    int B = find(b);

    if(A == B) {
        return true;
    }
    return false;
}
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int N, M; // 저장 주소 개수, 찾는 주소 개수
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    unordered_map<string, string> siteInfo;
    siteInfo.reserve(N<<1);
    string addr, pwd;

    for(int i = 0; i < N; i++){
        cin >> addr >>  pwd;
        siteInfo[addr] = pwd;
    }

    for(int i = 0; i < M; i++){
        cin >> addr;
        cout << siteInfo[addr] << "\n";
    }

    return 0;
}
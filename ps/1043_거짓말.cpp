#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M; // 4, 1
    int people[N];
    for(int i = 1; i <= N; i++){
        people[i] = i;
    }
    int isGenuine;
    cin >> isGenuine;
    if(isGenuine == 0){
        cout << M;
        return 0;
    }

    int genuine[isGenuine];
    for(int i = 0; i < isGenuine; i++){
        cin >> genuine[i];
    }
    // party init
    int invit_num;
    cin >> invit_num;

    vector<vector<int> > parties;
    for(int i = 0; i < invit_num; i++){
        int person;
        cin >> person;
        parties[i].push_back(person);
    }
}
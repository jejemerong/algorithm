#include <iostream>
#include <vector>

using namespace std;
static vector <int> people;
static vector<int> parties;
static vector<int> genuines;

int find(int person);
void unionFunc(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // people init
    int N, M;
    cin >> N >> M;
    people.resize(N + 1);
    parties.resize(M + 1);
    for(int i = 1; i <= N; i++){
        people[i] = i;
    }
    // genuine init
    int genuine_num;
    cin >> genuine_num;
    if(genuine_num == 0){
        cout << M;
        return 0;
    }
    genuines.resize(genuine_num + 1);
    fill(genuines.begin(), genuines.end(), 0);
    for(int i = 0; i < genuine_num; i++){
        int person;
        cin >> person;
        if(i == 0){
            genuines[i] = person;
        } else {
            unionFunc(genuines[0], person);
        }
    }
    // party init
    fill(parties.begin(), parties.end(), 0);
    for(int i = 0; i < M; i++){
        int party_people_num;
        cin >> party_people_num;
        for(int j = 0; j < party_people_num; j++){ // 파티 인원을 다 넣지 말고 find 연산만 하고 나중에 그걸로 비교하게끔
            int person;
            cin >> person;
            if(j == 0){
                parties[i] = person;
            } else {
                unionFunc(parties[i], person);
            }
        }
    }

    // 지민이가 그짓말 할 수 있는 횟수
    int result = 0;
    for(int i = 0; i < M; i++){
        if(find(genuines[0]) != find(parties[i])){
            result++;
        }
    }
    cout << result;
}

int find(int person)
{
    if(person != people[person]){
        return people[person] = find(people[person]);
    }
    return person;
}

void unionFunc(int a, int b)
{
    a = find(a);
    b = find(b);

    if(a != b){
        people[b] = a;
    }
}
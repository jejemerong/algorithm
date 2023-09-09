#include <iostream>
#include <string>
#include <map>

using namespace std;

int result = 0;
map<string, int> state;

bool isValid(map<string, int > state, int condition[4], int valid)
{
    string alphabet[4] = {"A", "C", "G", "T"};
    for(int i = 0; i < 4; i++){
        if(condition[i] <= state[alphabet[i]]) {
            valid++;
        }
    }
    if(valid == 4) {
        return true;
    }
    return false;
}

int main()
{
    // DNA 문자열 개수, 부분문자열 개수
    int S, P; 
    scanf("%d %d", &S, &P);

    // DNA 문자열 입력
    string dnaStr;
    cin >> dnaStr; // char 일 경우, scanf 가능

    int A, C, G, T; // 해당 알파벳의 개수 저장
    scanf("%d %d %d %d", &A, &C, &G, &T);
    int condition[4] = {A, C, G, T};

    int start = 0;
    int end = start + P - 1;
    int valid = 0;

    // before sliding with initial array which length is P
    for(int i = 0; i < P; i++){
        // TODO: key 생성 방법 map.cpp 에 정리하기
        // 이게 key 에 대한 개념인지 , string 에 대한 개념인지 확인 필요
        string key (1, dnaStr[i]);
        state[key]++;
    }

    // isValid 검사 해주고 맞으면 result++
    if (isValid(state, condition, valid)) {
        result++; // TODO: 변수명 count 로 했을 때, 'reference count is ambiguous;' 라는 에러 뜨는데 뭐지
    }

    for(int i = P; i < S; i++){
        string key(1, dnaStr[i]);
        string removeKey(1, dnaStr[i - P]);
        state[key]++;
        state[removeKey]--;
        if(isValid(state, condition, valid)){
            result++;
        }
    }

    cout << result << "\n";
    return 0;

}
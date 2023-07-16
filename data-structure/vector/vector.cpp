#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    // 선언
    vector<int> A;

    // 삽입 연산
    A.push_back(1); //
    A.insert(A.begin(), 7); // 맨 앞에 7 삽입
    A.insert(A.begin() + 2, 10); // index 3의 위치에 10 삽입 -> 인덱스 2를 건너뛰어 move 에러 남

    // 값 변경
    A[2] = -5;

    // 삭제 연산
    A.pop_back(); // 마지막 값 삭제
    A.erase(A.begin() + 1); // index 3 에 해당하는 값 삭제
    // A.clear();

    // 정보 가져오기
    cout << A.size() << endl; // 데이터 개수
    cout << A.front() << endl;  // 처음 값
    cout << A.back() << endl; // 마지막 값
    cout << A[2] << endl; // index 3에 해당하는 값
    cout << A.at(0) << endl; // index 5 에 해당하는 값
    // 참고로 [] 와 at() 으로 인덱스 접근하는 방식은 값의 유무에 대한 평가 차이가 발생함.
    // cout << A.begin() << endl; // 첫 번째 데이터 위치 -> char 형으로 출력할 수 없다는 에러 발생
    // cout << A.end() << endl; // 마지막 데이터 위치

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    pair <int, int> position (1, 2);
    // 한 요소만 출력 시, 
    cout << position.first << position.second << endl;
    position.swap(position.first, position);
}
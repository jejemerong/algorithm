#include <iostream>

using namespace std;



int main()
{
    int N = 0;
    string numbers;

    cin >> N;
    cin >> numbers;

    int sum = 0;
    for(int i = 0; i < numbers.length(); i++){
        // numbers[i] 는 문자형이기 때문에 이를 숫자형으로 바꿔주려면 49 또는 '0' 을 빼면 됨. 이는 ASCII 코드에 의해 매핑된 값임.
        sum += numbers[i] - '0'; 
    }
    cout << sum << "\n";
    return 0;
}
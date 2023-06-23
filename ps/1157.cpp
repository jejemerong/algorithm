#include <iostream>
#include <algorithm>

using namespace std;

// ASCII
#define alphaNum 26
#define upperA 97
#define lowerA 65

int num;
string str;
int *times = new int[alphaNum];

int main()
{
  // freopen("input.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> str;
  for(int i = 0; i < str.size(); i++){
    num = int(str.at(i)) - upperA; // 대문자 A 시작점
    if(num < 0) num += 32;
    times[num]++;
  }

  int * max = max_element(times, times + alphaNum);
  int index = max - times;
  int * maxComp = find(max+1, times + alphaNum, *max);

  if(max != maxComp && *max == *maxComp){
    cout << "?" << "\n";
  }else {
    cout << char(index + lowerA) << "\n";
  }
  return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int elementNum,targetNum;
vector<int> elements, targets;

bool binarySearch(vector<int>&elements, int end, int target) {
    int start = 0;
    while(start <= end){
        int mid = (start + end) / 2;
        if(elements[mid] == target) return true;
        else if (elements[mid] > target) end = mid - 1;
        else start = mid + 1; 
    }
    return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr); // 이거 안하면 시간 초과...
  cin >> elementNum;
  elements.resize(elementNum);
  for(int  i = 0; i < elementNum; i++){
    cin >> elements[i];
  }
  sort(elements.begin(), elements.end());
  cin >> targetNum;
  targets.resize(targetNum);
  for(int i = 0; i < targetNum; i++){
    cin >> targets[i];
    cout << binarySearch(elements, elementNum-1, targets[i]) << "\n"; // 굳이 타겟을 다 받고 탐색 안해도 되니까
  }
  return 0;
}

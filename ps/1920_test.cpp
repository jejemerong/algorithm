#include <iostream>
#include <algorithm>
using namespace std;

int elementNum,targetNum;
vector<int> elements;
// vector<bool> isExsited;

/**
 * 1. 입력 받을 때, 정렬
 * 2. 이분 탐색
 * 3. 출력 시
*/

// void dumbIter(int elementNum, int targetNum, vector<int> elements, vector<int> targets) {
//     isExsited.resize(targetNum);

//     for (int i = 0; i < targetNum; i++){
//         for(int j = 0; j < elementNum; j++){
//             if(targets[i] == elements[j]) isExsited[i] = true;
//         }
//     }
// }

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
int num;
//   freopen("input.txt", "r", stdin);
  // 입력 받기
  scanf("%d", elementNum);
  elements.resize(elementNum);
  for(int  i = 0; i < elementNum; i++){
    cin >> elements[i];
  }
  sort(elements.begin(), elements.end());
  scanf("%d", targetNum);
  for(int i = 0; i < targetNum; i++){
    cin >> num;
    cout << binarySearch(elements, elementNum-1, num) << "\n"; // 굳이 타겟을 다 받고 탐색 안해도 되니까
  }

    // 시간 초과
    // dumbIter(targetNum, elementNum, targets, elements);

  return 0;
}

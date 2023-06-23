#include <iostream>

using namespace std;

int N, output;
// 10 -> 9 -> 3 -> 1
// 2 -> 1

int isDiv3 (int num){
    return num / 3;
}

int isDiv2(int num){
    return num / 2;
}

int substr1 (int num){
    return num - 1;
}

int main()
{
//   freopen("input.txt", "r", stdin);
  scanf("%d", &N);
//   for(int i = 0; i <= N; i++){

//   }
  // 10 -> 9 -> 3 -> 1: 3
  // 10 -> 5 -> 4 -> 2 -> 1: 4

int arr[N];
arr[1] = 0;
  for(int i = 2; i <= N; i++){
    arr[i] = arr[i-1] + 1;
    if(i % 2 ==0){
        arr[i] = min(substr1(1), isDiv2(i));
        output++;
        cout << "output2222" << output << endl;
    }
    if(i % 3 == 0){
        arr[i] = min(substr1(1), isDiv3(i));
        output++;
        cout << "output3333" << output << endl;
    }
  }
  cout << output << endl;
  return 0;
}

/**
 * 1 // 0
 * 1 <- 2 //1
 * 1 <- 3 //1
 * 1 <- 2 <- 4 / 1 <- 3 <- 4 // 2
 * 1 <- 2 <- 4 <- 5 // 3
 * 1 <- 2 <- 3 <- 6 // 3
 * 1 <- 2 <- 3 <- 6 <- 7 // 4
 * 1 <- 2 <- 4 <- 8 // 3
 * 1 <- 3 <- 9 //2
 * 1 <- 3 <- 9 <- 10 // 3
 * 1 <- 3 <- 9 <- 10 <- 11 // 4
 * 1 < 2 <- 4 <- 12 // 4
*/
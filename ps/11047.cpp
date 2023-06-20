#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * 어려웠던 점
 * 1. 처음에 정렬하기 싫어서 우선순위 큐로 두고 풀었음. 
 * 2. 테스트 케이스 2번은 통과, 1번은 동전 종류를 한번 건너뛰면 while 탈출
 * 3. 우선순위 큐말고 벡터 배열로 두고 while 문 밖에서 for 문으로 인덱스 접근하면 통과
*/

int n, k, x, output;

int comp(int a, int b){
  return a > b;
}

int main() {
  // freopen("input.txt", "r", stdin);

  scanf("%d %d", &n, &k);
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    scanf("%d", &v[i]);
  }

  sort(v.begin(), v.end(), comp);
	// for (int i = 0; i < n; i++) {
	// 	while (k - v[i] >= 0) {
	// 		output++;
	// 		k -= v[i];
	// 	}
	// }
  for(int i = 0; i < v.size(); i++){
    output += k / v[i];
    k = k % v[i];
  }
    
  printf("%d\n", output);
  return 0;
}
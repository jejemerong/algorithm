#include <iostream>
#include <vector>

using namespace std;

/**
 * 어려웠던 점
 * 1. n 이 90일 때, int 타입의 최대 수인 2147483647 을 넘어감 => long long 타입 사용
 * 2. vector 사용하면 런타임 에러 발생 => 배열 초기화 사용
*/

int main()
{
  int n;
  long long v[91] = {0, 1,};

  // freopen("input.txt", "r", stdin);
  scanf("%d", &n); // 10

  for(int i = 2; i <= n; i++){
    v[i] = v[i - 1] + v[i - 2];
  }

  printf("%lld", v[n]);
  return 0;
}
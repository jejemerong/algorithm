#include <iostream>
#include <queue>

using namespace std;

int N, K;
int W, V;

// vector< priority_queue <pair <int, int > > > pair_q;
// priority_queue <pair<int, int > > pair_q;
// priority_queue <int> single_q;

int main()
{
//   freopen("input.txt", "r", stdin);
  scanf("%d %d", &N, &K);
  int * maxIndex = new int[K];
  std::fill(maxIndex, maxIndex+K, 0);
  for(int i = 0; i < N; i++){
    scanf("%d %d", &W, &V);
    // if(maxIndex[W] > V) return 0;
    // if(W > K) return 0;
    *&maxIndex[W] = V;
  }

  for(int i = 1; i <= K; i++){
    for(int j = K; j > i; j--){
        if(i + j <= K){
            cout << "i: "<< i << ", j: " << j << ", *&maxIndex[i]: " << *&maxIndex[i] << ", " << *&maxIndex[j] << endl;
            *&maxIndex[i] = *&maxIndex[j] + *&maxIndex[i];
        }
    }
  }

  for(int i = 1; i <= K; i++){
    cout << i << ": " << *&maxIndex[i] << endl;
  }

  return 0;
}

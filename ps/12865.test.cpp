#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;
int W, V;
int result = 0;

int main()
{
  // freopen("input.txt", "r", stdin);
  scanf("%d %d", &N, &K);
  vector<pair<int, int> > arr;
  arr.resize(N+1);
  while (cin >> W >> V) {
    // scanf("%d %d", &W, &V);
    cin >> W >> V;
    arr.push_back(make_pair(V, W));
  }
  sort(arr.begin(), arr.end());

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
        if(arr[i].second + arr[j].second <= K && result < arr[i].first + arr[j].first){
            result = arr[i].first + arr[j].first;
        }
    }
  }

  for(int i = 0; i < arr.size(); i++){
    cout << arr[i].first << ": " << arr[i].second <<endl;
  }
  cout << N << ", " << result <<  ", " << arr.size();
  return 0;
}
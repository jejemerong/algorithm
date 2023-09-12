#include <iostream>
#include <deque>

using namespace std;

typedef pair<int, int> Node;

int main()
{
    int N, L;
    scanf("%d %d", &N, &L);
    deque<Node> mydeque;

    for(int i = 0; i < N; i++){
        int now;
        scanf("%d", &now);

        while(mydeque.size() && mydeque.back().first > now) {
            mydeque.pop_back();
        }

        mydeque.push_back(Node(now, i));

        if(mydeque.front().second <= i - L) {
            mydeque.pop_front();
        }

        cout << mydeque.front().first << " ";
    }

    return 0;
}
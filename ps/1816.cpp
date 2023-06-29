#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e6 + 1; // 이거 왜 1을 더해야 하는지

int minFactor[MAX] = {-1, -1, }; // 
vector<int> prime; // 소수 배열

void eratosthenes(void)
{
	// minFactor[0] = minFactor[1] = -1; // {} 로 초기화할 수 있는지 -> 할 수 있음.

	for (int i = 2; i < MAX; i++)
	{
		minFactor[i] = i;
	}

	for (int i = 2; i*i < MAX; i++)
	{
		if (minFactor[i] == i)
		{
			for (int j = i * i; j < MAX; j += i)
			{
				if (minFactor[j] == j)
				{
					minFactor[j] = i;
				}
			}
		}
	}

	for (int i = 2; i < MAX; i++)
	{
		if (minFactor[i] == i)
		{
			prime.push_back(i);
		}
	}
}

int main(void)
{
	int N;
    scanf("%d", &N);

	eratosthenes();

	for (int n = 0; n < N; n++)
	{
		long long S;
		scanf("%lld", &S);
		
		bool flag = true;

		for (int i = 0; i < prime.size(); i++)
		{
			if (S%prime[i] == 0)
			{
				flag = false;

				break;
			}
		}

		if (flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}

	return 0;
}
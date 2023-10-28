#include<iostream>
int main()
{
	int N,K,sum=1;
	scanf("%d%d",&N,&K);
	// for(int n = K+1,K = 1;--n;N--) sum=sum*N/(K++);
    for(int n = K + 1, K = 1; n > 0; n--){
        sum = sum * N / K;
        K++;N--;
    }
	printf("%d\n",sum);
	return 0;
}
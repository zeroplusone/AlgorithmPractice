#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX 1000001
bool prime[MAX];

void setprime()
{
	memset(prime,true,sizeof(prime));
	prime[0]=false; prime[1]=false;
	for(int i=2;i<int(sqrt(float(MAX)));++i)	 // 'long double sqrt(long double)''float sqrt(float)' 'double sqrt(double)'
		if(prime[i])		
			for(int j=i*i;j<MAX;j+=i)
				prime[j]=false;	
}

int main()
{
	int n,i;
	setprime();
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		for(i=2;i<=n/2;++i)
		{
			if(prime[i])
			{
				if(prime[n-i])
				{
					printf("%d = %d + %d\n",n,i,n-i);
					break;	
				}
			}			
		}
		if(i==n/2+1)
			printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}
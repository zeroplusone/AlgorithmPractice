#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAX 1000001
bool prime[MAX];

void setprime()
{	
	prime[0]=prime[1]=false;
	for(int i=2;i<MAX;++i)
		prime[i]=true;
	for(int j=2;j<int(sqrt(float(MAX)));++j)
		if(prime[j])
			for(int k=j*j;k<MAX;k+=j)				
				prime[k]=false;
}

int main()
{
	int a,d,n,count,tmp;
	setprime();
	while(scanf("%d %d %d",&a,&d,&n))
	{
		if(a==0 && d==0 &&n==0)
			break;
		count=0;	
		for(a-=d;count!=n;count++)
		{
			a+=d;
			while(!prime[a])
			{
				a+=d;
			}						
		}
		printf("%d\n",a);
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

#define MAX 1100000
int w[MAX];
int ans;
int sum;
int s,t;

void find(int a,int b)
{
	//printf("%d %d %d\n",a,b,sum);
	if(a==b)
	{
		
		sum+=w[b];
		//printf("%d ya\n",sum);
		ans=ans>=sum?sum:ans;
		sum-=w[b];
		return;
	}
	
	int max=a>b?a:b;

		for(int i=1;i<max;i*=2)
		{
			if( (a&i) ^ (b&i))
			{
				sum+=w[a];
				find(a|i,b);
				//printf("back %d %d %d\n",a,b,sum);
				sum-=w[a];
			}
		}
	
}

int main()
{
	int n,size;

	while(scanf("%d%d%d",&n,&s,&t)!=EOF)
	{
		if(n==0 && s==0 && t==0)
			break;
		ans=10100;
		sum=0;
		size=(int)pow(2,n);
		for(int i=0;i<size;++i)
			scanf("%d",&w[i]);
		find(s,t);
		printf("%d\n",ans);
	}
	return 0;
}
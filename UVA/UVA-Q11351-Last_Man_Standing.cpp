#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
/*
int kill(int n,int k)
{
	if(n==1)
		return 0;
	return (kill(n-1,k)+k)%n;
}

int main()
{
	int c,n,k;
	scanf("%d",&c);
	for(int i=1;i<=c;++i)
	{
		scanf("%d %d",&n,&k);
		printf("Case %d: %d\n",i,kill(n,k)+1);
	}
	return 0;
}
*/

#define MAX 100010

int main()
{
	int c,n,k;
	int id[MAX];
	id[1]=0;
	scanf("%d",&c);
	for(int i=1;i<=c;++i)
	{
		scanf("%d %d",&n,&k);
		for(int j=2;j<=n;++j)
			id[j]=(id[j-1]+k)%j;
		printf("Case %d: %d\n",i,id[n]+1);
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int count;
int smoke(int n,int k)
{	
	if(n/k==0)
		return count;
	count+=n/k;
	return smoke(n/k+n%k,k);
}

int main()
{
	int n,k,ans;
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		count=n;
		ans=smoke(n,k);
		printf("%d\n",ans);
		
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int n;
	int i,len,j,ans,tmp;
	while(scanf("%d",&n)!=EOF)
	{
		if(n>=0)	printf("%d\n",n);
		else
		{
			n*=-1;
			len=(n%100)/10;
			tmp=(n/100)*10+n%10;
			ans=n/10;
			ans=ans>tmp?tmp:ans;
			ans*=-1;
			printf("%d\n",ans);
		}
	}
	return 0;
}
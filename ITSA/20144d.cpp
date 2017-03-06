#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int LCM(int a,int b)
{
	int ans,tmp;
	if(a<b)
	{
		tmp=a;
		a=b;
		b=tmp;
	}
	for(ans=a;ans<=a*b;ans++)
	{
		if(ans%a==0 && ans%b==0)
			break;
	}
	return ans;
}
int findd(int a,int b,int c)
{
	int ans,tmp;
	tmp=LCM(a,b);
	ans=LCM(tmp,c);
	return ans;

}


int main()
{
	int t;
	scanf("%d",&t);
	int n,a,b,c;
	int ans;
	int edge;
	int tmp,i;
	while(t--)
	{
		scanf("%d%d%d%d",&n,&a,&b,&c);
		ans=findd(a,b,c);
		for(i=1;i<n;++i)
		{
			tmp=ans*i;
			if((tmp/a)*(tmp/b)*(tmp/c)>n)
				break;
		}
		tmp-=ans;
		//printf("%d\n",ans);
		edge=(tmp/a)*(tmp/b)*(tmp/c);
		if(edge>n || tmp==0)
			printf("No solution\n");
		else
			printf("%d\n",edge);
	}
	return 0;
}

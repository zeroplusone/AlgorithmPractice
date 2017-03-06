#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXN 25
int num[MAXN];

int main()
{
	int n,ans1,ans2,sum,tmp;
	int i;
	int zero;
	bool ch=true;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		zero=0;
		for(i=0;i<n;++i)
		{
			scanf("%d",&num[i]);
			if(num[i]==0)
				zero++;
		}
		sort(num,num+n);
		ans1=0;	ans2=0;	
		if(zero!=0)
		{
			if(n-zero>=2)
			{
				ans1=ans1*10+num[zero];
				ans2=ans2*10+num[zero+1];
				ch=true;
				tmp=zero;
				while(tmp!=0)
				{
					if(ch)	ans1=ans1*10;
					else	ans2=ans2*10;
					tmp--;	ch=!ch;
				}
				for(i=zero+2;i<n;++i)
				{
					if(ch)	ans1=ans1*10+num[i];
					else	ans2=ans2*10+num[i];
					ch=!ch;
				}
			}
			else if(n-zero==1)
			{
				ans1=ans1*10+num[zero];
				ch=false;
				tmp=zero;
				while(tmp!=0)
				{
					if(ch)	ans1=ans1*10;
					else	ans2=ans2*10;
					tmp--;	ch=!ch;
				}
				for(i=zero+1;i<n;++i)
				{
					if(ch)	ans1=ans1*10+num[i];
					else	ans2=ans2*10+num[i];
					ch=!ch;
				}
			}
			else
			{
				ans1=ans2=0;
			}
		}
		else
		{
			ch=true;
			for(i=0;i<n;++i)
			{
				if(ch)	ans1=ans1*10+num[i];
				else	ans2=ans2*10+num[i];
				ch=!ch;
			}		
		}
		printf("%d\n",ans1+ans2);

	}
	return 0;
}
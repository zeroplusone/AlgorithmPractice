#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAX 55


int main()
{
	int t,n;
	int i,j;
	int pre,now,h,d;
	while(scanf("%d",&t)!=EOF)
	{
		for(i=1;i<=t;++i)
		{
			h=d=0;
			scanf("%d",&n);
			for(j=0;j<n;++j)
			{
				if(!j)
				{
					scanf("%d",&pre);
				}
				else
				{
					scanf("%d",&now);
					if(pre>now)	d++;
					else if(pre<now)	h++;
					pre=now;
				}					
			}
			
			printf("Case %d: %d %d\n",i,h,d);
		}
	}
	return 0;
}
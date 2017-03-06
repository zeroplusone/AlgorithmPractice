#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;


#define MAXN 1100
int r[MAXN],c[MAXN];

int main()
{
	int i,j,in,n;
	bool ya=false;
	while(scanf("%d",&n)!=EOF)
	{
		memset(r,0,sizeof(r));
		memset(c,0,sizeof(c));
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				scanf("%d",&in);
				r[i]+=in;
				c[j]+=in;
			}
				
		}
		ya=false;
		for(i=0;i<n;++i)
		{
			if(r[i]==1 && c[i]==n)
			{
				printf("%d\n", i+1);
				ya=true;
				break;
			}
			
		}
		if(!ya)
			printf("-1\n");
	}
	return 0;
}
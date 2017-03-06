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
	freopen("testdata.in","r",stdin);
	int i,j,n;
	char in;
	bool ya=false;
	while(scanf("%d",&n)!=EOF)
	{
		memset(r,0,sizeof(r));
		memset(c,0,sizeof(c));
		
		for(i=0;i<n;++i)
		{
			getchar();
			for(j=0;j<n;++j)
			{
				scanf("%c",&in);
				r[i]+=in-'0';
				c[j]+=in-'0';
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
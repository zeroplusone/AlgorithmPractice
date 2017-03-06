#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int ti[12];
int i,j;
int main()
{
	int k;
	char in;
	bool ya=true;
	while(scanf("%d",&k)!=EOF)
	{
		getchar();	
		memset(ti,0,sizeof(ti));
		for(i=0;i<4;++i)
		{
			for(j=0;j<4;++j)
			{
				scanf("%c",&in);
				ti[in-'0']++;
			}
			getchar();	
		}
		ya=true;
		for(i=0;i<10;++i)
		{
			if(ti[i]>2*k)
			{
				ya=false;
				break;
			}			
		}
		if(ya)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
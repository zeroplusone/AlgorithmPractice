#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 33
int r[MAXN][MAXN];
bool v[MAXN];
int start;
bool flag=false;
void dfs(int s,int lev)
{
	if(flag)	return;
	if(lev==4)
	{
		if(s==start)
			flag==true;
		return;
	}
	int i;
	v[s]=true;
	for(i=0;i<n;++i)
	{
		if(r[s][i] && !v[i])
		{
			dfs(i,lev+1);
		}
	}
}

int main()
{
	int n;
	int i,j;
	
	while(scanf("%d",&n)!=EOF)
	{
		
		if(n<4)	flag=false;
		else
		{
			for(i=0;i<n;++i)
				for(j=0;j<n;++j)
					scanf("%d",&r[i][j]);
			for(i=0;i<n && (!flag);++i)
			{
				memset(v,false,sizeof(v));
				start=i;
				dfs(i,0);
			}
		}
		printf("%s\n",flag?"yes":"no");
	}
	return 0;
}
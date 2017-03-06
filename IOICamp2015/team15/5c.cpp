#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

#define MAXN 1100
int f[MAXN],f2[MAXN];
int lcs[MAXN][MAXN];
int dir[MAXN][MAXN];
vector<int> ans;

void build(int n)
{
	memset(lcs,0,sizeof(lcs));
	memset(dir,0,sizeof(dir));

	int i,j;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(f[j]==f2[i])
			{
				lcs[i][j]=lcs[i-1][j-1]+1;
				dir[i][j]=1;
			}
			else
			{
				lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
				//if(lcs[i][j]==lcs[i-1][j-1])
				//	dir[i][j]=1;
				if(lcs[i][j]==lcs[i][j-1])
					dir[i][j]=2;
				else if(lcs[i][j]==lcs[i-1][j])
					dir[i][j]=3;
			}
		}
	}
/*
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
			printf("%d ",lcs[i][j]);
		printf("\n");
	}
*/
	i=n;j=n;
	while(!(j==0 || i==0))
	{	
			if(dir[i][j]==1)
			{
				ans.push_back(f[j]);
				i--; j--;
			}			
			else if(dir[i][j]==2)
				j--;
			else if(dir[i][j]==3)
				i--;
	}

}

int main()
{
	int T,n,i,j,len;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%d",&f[i]);
		for(i=1,j=n;i<=n;++i,--j)
			f2[i]=f[j];	
		
		build(n);
		len=ans.size();
		for(i=0;i<len;++i)
			printf("%d%c",ans[i],i==len-1?'\n':' ');
	}
	return 0;
}
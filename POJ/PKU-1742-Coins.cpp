/******************
Judge   : poj
Problem : 1742-Coins
Course  : Course12
discribe: how many prices(form 1 to m) Tony can pay use these coins.
Input   :
			3 10  //n(#coin type~100) m($<=m~100000))
			1 2 4 2 1 1 //coin type , coin num
			2 5
			1 4 2 1
			0 0	//over
Output  :
			8	//ans
			4
Solve   : coin problem
			硬幣有限，是否湊的到某價位
*****************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

#define MAXN 110
#define MAXM 100010
bool dp[MAXM];
int v[MAXN];
int num[MAXN];
int used[MAXM];

int n,m;
void build()
{
	int i,j,tmp,k;
	dp[0]=1;
	for(i=1;i<=n;++i)
	{
		memset(used,0,sizeof(used));
		for(j=0;j<=m-v[i];++j)
		{
			if(dp[j]>0 && dp[j+v[i]]==0 && used[j]<num[i] )
			{
				dp[j+v[i]]=true;
				used[j+v[i]]=used[j]+1;
			}
		}
		/*for(j=0;j<=m;++j)
			printf("%d ",dp[i][j]);
		printf("\n");*/
	}
}

int main()
{
	//freopen("u674","r",stdin);
	int i,ans;
	memset(num,0,sizeof(num));
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)	break;
		for(i=1;i<=n;++i)
			scanf("%d",&v[i]);
		for(i=1;i<=n;++i)
			scanf("%d",&num[i]);
		memset(dp,false,sizeof(dp));
		build();
		ans=0;
		for(i=1;i<=m;++i)
			if(dp[i])	ans++;
		printf("%d\n",ans);
	}
	return 0;
}

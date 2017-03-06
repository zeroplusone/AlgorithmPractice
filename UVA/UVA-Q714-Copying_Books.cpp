/******************
Judge   : POJ
Problem : 1505-Copying Books
Course  : IOI
discribe: m book writen by k man
		  find the minimun of (max of the pages) 
		  If there is more than one solution, print the one that minimizes the work assigned to the first scriber,
			
Input   : 
			2									//n(#case)
			9 3									//m k
			100 200 300 400 500 600 700 800 900	//pages
			5 4									//m k
			100 100 100 100 100					//pages
Output  : 
			100 200 300 400 500 / 600 700 / 800 900	  //cut books by slash
			100 / 100 / 100 / 100 100
Solve   : DP
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXK 510

int dp[MAXK][MAXK];		//dp[i][j] : 前i本書j個人抄寫，所需時間(與頁數成正比)的最小值(1 <= i <= m , 1 <= j <= k)
int cut[MAXK];			//cut[i]   : 第i個slash放在第cut[i]本書後(1 <= i <= k-1)
int sum[MAXK];			//sum[i]   : 前i本書(包含第i本)的所有頁數(1 <= i <= m)

int main()
{
	int n,m,k;
	int i,j,v,in,tmp;
	int minval;
	
	scanf("%d",&n);	//case
	
	while(n--)
	{
		//=======initial========//
		memset(dp,0,sizeof(dp));
		memset(cut,0,sizeof(cut));
		memset(sum,0,sizeof(sum));
		
		
		//=======read========//
		scanf("%d %d",&m,&k);
		for(i=1;i<=m;++i)
		{
			scanf("%d",&in);
			sum[i]=sum[i-1]+in;	//前i本書的總和=前i-1本書的總和+第i本書的頁數
			dp[i][1]=sum[i];	//當人數=1時，不須分割，負責所有頁數=sum[i]
		}
		
		//=======dynamic programming========//
		for(i=2;i<=k;++i)					//從2個人到k個人(i->人)
		{
			for(j=1;j<=m;++j)				//從1本書到m本書(j->書)
			{
				if(i>j)	dp[j][i]=0;			//一個人至少要一本書，不存在的狀況
				else						//計算dp[j][i]
				{			
					minval=dp[j][i-1];		//****
					for(v=j-1;v>=i-1;--v)	//第i個人要從哪本書(v)開始抄會得到最佳解( i-1 <= v <= j-1 ,前面的i-1人至少有一本書，第i個人至少要拿最後一本(第j本))
					{						//****from end to start 需從後面開始搜尋迴圈，當數字相等時才會切在最前面
						tmp=dp[v][i-1]>(sum[j]-sum[v])?dp[v][i-1]:(sum[j]-sum[v]);	//當切在v時，找出前後兩個部分的最大值(dp[v][i-1] 前v本書，i-1個人 (前) & v+1本書到最後一本(j) sum[j]-sum[v](後) )
						if(minval>=tmp)		//找出不同切法算出來的最小值
						{
							minval=tmp;
						}
					}
					dp[j][i]=minval;		//記錄
				}
			}
		}
		
		//=======cut========//	
		tmp=0;
		for(i=m,j=k-1;i>0 && j>0;--i)		//從後面開始切，當總合超過最小值(dp[m][k])時，切一刀
		{
			tmp+=sum[i]-sum[i-1];
			if(tmp>dp[m][k] || j>=i)
			{
				cut[j]=i;
				tmp=sum[i]-sum[i-1];
				j--;
			}
		}
		
		//=======print answer========//
		for(i=1,j=1;i<=m;++i)
		{
			if(i!=1)	printf(" ");
			printf("%d",sum[i]-sum[i-1]);
			if(j<k && i==cut[j])
			{
				printf(" /");
				j++;
			}
		}
		printf("\n");
		
	}
	return 0;
}
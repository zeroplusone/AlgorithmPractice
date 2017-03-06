/******************
Judge   : UVA
Problem : UVA-Q111-History_Grading.cpp
Course  : Course9
discribe: find lcs size
			
Input   : 
			4	//n (size of array)
			4 2 3 1	//origin
			1 3 2 4 //compare1
			3 2 1 4 //compare2
			2 3 4 1 //compare3
Output  : 
			1		//size 1
			2		//size 2
			3		//size 3
Solve   : lcs
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 25
int map[MAX][MAX];
int o[MAX];
int q[MAX];
int tmp[MAX];

int lcs(int n)
{
	
	memset(map,0,sizeof(map));
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(o[i]==q[j])						
				map[i][j]=map[i-1][j-1]+1;			
			else
				map[i][j]=map[i-1][j]>map[i][j-1]?map[i-1][j]:map[i][j-1];
			
		}
		
	}
	return map[n][n];
}

int main()
{
	int n,now,ans;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	
		scanf("%d",&tmp[i]);
	for(int i=1;i<=n;++i)	
		o[tmp[i]]=i;
	
	now=1;
	while(scanf("%d",&tmp[now])!=EOF)
	{
		if(now<n)
		{
			now++;
			continue;
		}
		else if(now==n)
		{			
			for(int i=1;i<=n;++i)	
				q[tmp[i]]=i;
			ans=lcs(n);
			printf("%d\n",ans);
			now=1;
		}		
	}	
	return 0;
}
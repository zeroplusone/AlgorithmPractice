#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

//greedy

vector<int> lis;

void print()
{
	
	for(int i=0;i<lis.size();++i)
	{
		printf("%d ",lis[i]);
	}
	printf("\n");
}


int main()
{	
	int n;
	int seq,now,flag;
	while(scanf("%d",&n)!=EOF)
	{
		lis.clear();
		for(int i=0;i<n;++i)
		{	
			scanf("%d",&seq);
			if(lis.empty())
				lis.push_back(seq);
			else
			{
				if(lis.back()<seq)
					lis.push_back(seq);
				else if(lis.back()>seq)				
					*lower_bound(lis.begin(),lis.end(),seq)=seq;
				//比n大一點的位置->by binary search tree
				print();				
			}
			
		}

		printf("%d\n",lis.size());
	}
	return 0;
}

/*   dp
#define MAX 1010
int dp[MAX],pi[MAX],seq[MAX];
int n;

void build()
{
	int max,tmp;
	for(int i=0;i<n;++i)
	{	
		max=0; tmp=-1;
		for(int j=i-1;j>=0;--j)
		{	
			if(j>=0)        //小心記憶體區段錯誤
			{
				if(seq[j]<seq[i])
				{
					if(dp[j]>=max)
					{	
						max=dp[j];
						tmp=j;
					}
				}
			}
		}
		dp[i]=max+1;
		pi[i]=tmp;
	}
		
}

void print()
{
	int max=0;
	for(int i=0;i<n;++i)
	{
		if(dp[i]>max)
			max=dp[i];
	}
	printf("%d\n",max);
}

int main()
{	
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&seq[i]);
		memset(dp,1,sizeof(dp));
		memset(pi,-1,sizeof(pi));
		build();
		print();
	}
	return 0;
}
*/
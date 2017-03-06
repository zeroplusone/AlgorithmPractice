/******************
Judge   : UVA
Problem : 10534 - Wavio Sequence
Course  : Course9
discribe:  
			Wavio is of odd length i.e. L = 2*n + 1.
			¡P  The first (n+1) integers of Wavio sequence makes a strictly increasing sequence.
			¡P  The last (n+1) integers of Wavio sequence makes a strictly decreasing sequence.
			
Input   : 
			10 //n
			1 2 3 4 5 4 3 2 1 10 //array
			19
			1 2 3 2 1 2 3 4 3 2 1 5 4 1 2 3 2 2 1
			5
			1 2 3 4 5
Output  : 
			9
			9
			1
Solve   : LIS
*******************/
#include<bits/stdc++.h>
using namespace std;
#define MAXN 10010
int lis2[MAXN],lds2[MAXN],ary[MAXN];

int main()
{
	int n;
	int i,j,mi,md,ans;
	vector<int> lis,lds;
	while(scanf("%d",&n)!=EOF)
	{
		mi=0;	md=0;	ans=0;

		lis.clear();	lds.clear();
		for(i=0;i<n;++i)
		{
			/*TLE
			scanf("%d",&ary[i]);
			
			for(j=0;j<i;++j)
			{
				if(ary[i]>ary[j] && lis[j]+1>lis[i])
					lis[i]=lis[j]+1;
			}
			for(j=0;j<i;++j)
			{
				if(ary[i]<ary[j] && lds[j]+1>lds[i])
					lds[i]=lds[j]+1;
			}		
			
			mi=mi<lis[i]?lis[i]:mi;
			md=md<lds[i]?lds[i]:md;
			ans=ans<(mi<md?mi:md)?(mi<md?mi:md):ans;
			*/
			scanf("%d",&ary[i]);
			if(lis.empty())	lis.push_back(ary[i]);
			else
			{
				if(ary[i]<lis.back())	*lower_bound(lis.begin(),lis.end(),ary[i])=ary[i];
				else if(ary[i]>lis.back())	lis.push_back(ary[i]);
			}
			lis2[i]=lis.size();
		}
		for(i=n-1;i>=0;--i)
		{
			if(lds.empty())	lds.push_back(ary[i]);
			else
			{
				if(ary[i]<lds.back())	*lower_bound(lds.begin(),lds.end(),ary[i])=ary[i];
				else if(ary[i]>lds.back())	lds.push_back(ary[i]);
			}
			lds2[i]=lds.size();
		}
		for(i=0;i<n;++i)
		{
			j=lis2[i]<lds2[/*n-i-1*/i]?lis2[i]:lds2[/*n-i-1*/i];
			ans=ans<j?j:ans;
			//printf("%d %d %d\n",lis2[i],lds2[i],ans);
		}
		
		
		printf("%d\n",ans*2-1);
	}
	return 0;
}


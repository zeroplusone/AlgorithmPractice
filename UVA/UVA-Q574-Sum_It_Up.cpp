/******************
Judge   : UVA
Problem : 574 - Sum It Up
Course  : Course7
discribe:  Given t and a list of n integers(each list appear in nonincreasing order), find all distinct sums using numbers from the list that add up to t
Input   : 	t n num~~~~~~~
			4 6 4 3 2 2 1 1
			5 3 2 1 1
			400 12 50 50 50 50 50 50 25 25 25 25 25 25
			0 0   //end
			
Output  : 	
Sums of 4:
			4
			3+1
			2+2
			2+1+1
			Sums of 5:
			NONE
			Sums of 400:
			50+50+50+50+50+50+25+25+25+25
			50+50+50+50+50+25+25+25+25+25+25
Solve   :	backtracking
*******************/
#include<bits/stdc++.h>
using namespace std;

#define MAXN 15
int n,t;
int num[MAXN];
vector<int> ans[10010];
int ansnum;

void back(int now,int index)
{
	if(now==t)
	{
		ans[ansnum+1]=ans[ansnum];	//copy to find new sol
		ansnum++;
		return;
	}
	for(int i=index;i<n;++i)
	{
		if(now+num[i]<=t)
		{
			ans[ansnum].push_back(num[i]);
			back(now+num[i],i+1);
			ans[ansnum].pop_back();
		}
	}
}

bool cmp(vector<int> a,vector<int> b)
{
	int i;
	for(i=0;i<a.size();++i)
		if(a[i]!=b[i])
			return a[i]>b[i];
	return a.size()>b.size();
}

int main()
{
	int i;
	vector<int>::iterator itr;
	
	while(scanf("%d%d",&t,&n)!=EOF)
	{
		if(t==0 && n==0)	break;
		
		for(i=0;i<=n;++i)	ans[i].clear();
		ansnum=0;
		for(i=0;i<n;++i)
			scanf("%d",&num[i]);
		
		back(0,0);
		
		printf("Sums of %d:\n",t);
		sort(ans,ans+ansnum,cmp);
		if(ansnum==0)	printf("NONE\n");		
		else
		{
			for(itr=ans[0].begin();itr!=ans[0].end();++itr)			
				printf("%d%c",*itr,itr==ans[0].end()-1?'\n':'+');
						
			for(i=1;i<ansnum;++i)
			{
				if(ans[i]!=ans[i-1])
				{
					for(itr=ans[i].begin();itr!=ans[i].end();++itr)
					{
						printf("%d%c",*itr,itr==ans[i].end()-1?'\n':'+');
					}
				}
			}
			
		}
	}
	return 0;
}

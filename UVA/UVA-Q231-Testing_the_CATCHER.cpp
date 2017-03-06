/******************
Judge   : UVA
Problem : UVA-Q231-Testing_the_CATCHER.cpp
Course  : Course9
discribe: the maximum number of incoming missiles that the CATCHER could possibly intercept for the test.
			 CATCHER is able to intercept it if and only if it satisfies one of these two conditions:

				The incoming missile is the first missile to be intercepted in this test.
				-or-
				The missile was fired after the last missile that was intercepted and it is not higher than the last missile which was intercepted.
Input   : 
			389
			207
			155
			300
			299
			170
			158
			65
			-1
			      //------
			23
			34
			21
			-1
				//---------
			-1
Output  : 
			Test #1:
			  maximum possible interceptions: 6

			Test #2:
			  maximum possible interceptions: 2
Solve   : lis
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct missiles
{
	int dp;
	int num;
};

int main()
{
	 
	int c=1,i=0,tmp,max,ans;
	vector<struct missiles> m;
	struct missiles a;
	while(scanf("%d",&tmp)!=EOF)
	{
		if(tmp==-1)
			break;
		if(c!=1)
			printf("\n");
		
		a.num=tmp;	a.dp=1; m.push_back(a); i++;
		ans=0;
		while(scanf("%d",&tmp))
		{
			if(tmp==-1)
				break;
			a.num=tmp;	a.dp=1; m.push_back(a);
			++i;
		}
		
		for(int j=0;j<i;++j)
		{
			max=0;
			for(int k=0;k<j;++k)
			{
				if(m[k].num>m[j].num && m[k].dp>=max)
				{
					max=m[k].dp;
				}
			}
			m[j].dp=max+1;
			//printf("@%d %d %d \n",j,m[j].num,m[j].dp);
			if(m[j].dp>ans)	ans=m[j].dp;
		}
		printf("Test #%d:\n  maximum possible interceptions: %d\n",c,ans);
		c++;
		m.clear();		
		i=0;
	}
	return 0;
}
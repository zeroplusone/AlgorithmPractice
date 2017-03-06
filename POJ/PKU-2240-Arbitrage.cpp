/******************
Judge   : POJ
Problem : 2240-Arbitrage
Course  : Course10
discribe: t takes a list of currency exchange rates as input and then determines whether arbitrage is possible or not. 
Input	:
			3			//#node(1~30)
			USDollar	//node name
			BritishPound
			FrenchFranc
			3			//#edge
			USDollar 0.5 BritishPound	
			BritishPound 10.0 FrenchFranc
			FrenchFranc 0.21 USDollar

			3			//#node
			USDollar
			BritishPound
			FrenchFranc
			6
			USDollar 0.5 BritishPound
			USDollar 4.9 FrenchFranc
			BritishPound 10.0 FrenchFranc
			BritishPound 1.99 USDollar
			FrenchFranc 0.09 BritishPound
			FrenchFranc 0.19 USDollar

			0			//end

Output	:
			Case 1: Yes
			Case 2: No

solve:
		all pair shortest path
		floyd
[direction ,no cycle]
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;

#define MAXN 50
double d[MAXN][MAXN];

int main()
{
	int n,m;
	int i,j,k;
	map<string,int> cur;
	string in,tmp1,tmp2;
	double money;
	bool flag=false;
	int casenum=1;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		cur.clear();
		for(i=0;i<=n;++i)
			for(j=0;j<=n;++j)
				d[i][j]=1;
		
		i=n;
		while(i--)
		{
			cin>>in;
			cur[in]=i;
		}
		
		scanf("%d",&m);
		i=m;
		
		while(i--)
		{
			cin>>tmp1;
			cin>>money;
			cin>>tmp2;
			d[cur[tmp1]][cur[tmp2]]=money;
			//cout<<tmp1<<" "<<tmp2<<" "<<money<<endl;
		}
		
		//floyd
		for(k=0;k<n;++k)
		{
			for(i=0;i<n;++i)
			{
				for(j=0;j<n;++j)
				{
					if(d[i][k]*d[k][j]>d[i][j])
						d[i][j]=d[i][k]*d[k][j];
				}
			}
		}
		//find ans
		flag=false;
		for(i=0;i<n;++i)
		{			
			if(d[i][i]>1)
			{
				flag=true;
			}			
		}
		if(flag)
			printf("Case %d: Yes\n",casenum++);
		else
			printf("Case %d: No\n",casenum++);
	}
	return 0;
}
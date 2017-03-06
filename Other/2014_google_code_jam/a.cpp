#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>
using namespace std;

#define MAXN 4
int row[MAXN];

int main()
{
	int t,tt;
	int i,j,ans,num,r;
	set<int> poke;
	scanf("%d",&t);
	freopen("a.out","w",stdout);
	for(tt=1;tt<=t;++tt)
	{
		poke.clear();
		scanf("%d",&r);
		for(i=1;i<=MAXN;++i)
		{
			for(j=0;j<MAXN;++j)
			{
				scanf("%d",&row[j]);
				if(i==r)					
					poke.insert(row[j]);
									
			}	
		}
		ans=-1;	num=0;
		scanf("%d",&r);
		for(i=1;i<=MAXN;++i)
		{
			for(j=0;j<MAXN;++j)
			{
				scanf("%d",&row[j]);
				if(i==r && poke.count(row[j]))
				{	
					num++;
					ans=row[j];
				}				
			}	
		}
		
		printf("Case #%d:",tt);
		if(num==0)
			printf(" Volunteer cheated!\n");
		else if(num==1)
			printf(" %d\n",ans);
		else 
			printf(" Bad magician!\n");
	}
	return 0;
}
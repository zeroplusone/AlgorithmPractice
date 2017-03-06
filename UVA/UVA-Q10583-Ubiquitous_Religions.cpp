
/******************
Judge   : UVA
Problem : 10583 - Ubiquitous Religions 
Course  : Course8
Sample Input
10 9   //十個人 九筆資料
1 2    //1和2同宗教
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
10 4
2 3
4 5
4 8
5 8
0 0

Sample Output
Case 1: 1    //最多有幾種宗教
Case 2: 7

sol:disjoint set 最後算有幾個root
*/
Solve   : disjoint set
*******************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAX 50010
int p[MAX];
int rank[MAX];

void makeset(int x)
{
	p[x]=x;
	rank[x]=0;
}

int findset(int x)
{
	if(x!=p[x])
		p[x]=findset(p[x]);
	return p[x];
}

void link(int x,int y)
{
	if(rank[x]>rank[y])
		p[y]=x;
	else
	{
		p[x]=y;
		if(rank[x]==rank[y])
			rank[y]++;
	}	
}

int main()
{
	int count=0,n,m,a,b,ans;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)
			break;
		count++;	ans=0;
		for(int i=1;i<=n;++i)
			makeset(i);
		for(int j=0;j<m;++j)
		{
			scanf("%d %d",&a,&b);
			link(findset(a),findset(b));
		}
		for(int k=1;k<=n;++k)
			if(k==p[k])				
				ans++;				
			
		printf("Case %d: %d\n",count,ans);
	}
	return 0;	
}
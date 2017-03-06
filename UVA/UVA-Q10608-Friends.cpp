/******************
Judge   : UVA
Problem : 10608-Friends.cpp
Course  : Course8
discribe: find biggest friend group

Sample Input
2        //兩筆
3 2      //3個人2筆資料
1 2          1和2是朋友
2 3          朋友的朋友也是朋友
10 12    //case2
1 2
3 1
3 4
5 4
3 5
4 6
5 2
2 1
7 10
1 2
9 10
8 9

Sample Output
3       //數量最大的朋友群
6

Solve   : disjoint set
*******************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
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
	map<int,int> ans;
	int n,m,a,b,c,max;
	scanf("%d",&c);
	for(int cc=0;cc<c;++cc)
	{
		scanf("%d %d",&n,&m);
		ans.clear();
		for(int i=1;i<=n;++i)
			makeset(i);
		for(int j=0;j<m;++j)
		{
			scanf("%d %d",&a,&b);
			link(findset(a),findset(b));
		}
		max=0;
		for(int k=1;k<=n;++k)
		{	
			findset(k);
			ans[p[k]]++;	
		}
		std::map<int,int>::iterator itr;
		for(itr=ans.begin();itr!=ans.end();++itr)
			if((itr->second)>max)
				max=(itr->second);
		printf("%d\n",max);
	}
	return 0;	
}


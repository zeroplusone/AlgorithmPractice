/******************
Judge   : UVA
Problem : 11418 - Clever Naming Patterns
Course  : Course11
discribe:   name the first problem starting with the letter A, the second problem starting with the letter B
			pick an ordering of the problems and an acceptable name for each one so that each problem's name starts with the correct letter of the alphabet.
Input   :

		4	//case  ~~~30
		3	//#problem  ~~~26
		2 Apples Oranges	//num ~~26 string
		1 Bananas
		5 Apricots Blueberries Cranberries Zuccini Yams
		1	//#problem
		1 ApPlEs
		2	//#problem
		2 a b
		1 axe
		4	//#problem
		4 Aa Ba Ca Da
		3 Ab Bb Cb
		2 Ac Bc
		1 Ad

Output	:
		Case #1:
		Apples
		Bananas
		Cranberries
		Case #2:
		Apples
		Case #3:
		Axe
		B
		Case #4:
		Ad
		Bc
		Cb
		Da
solve:
		maximun flow
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

#define MAXN 110
#define INF 9999999
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int pa[MAXN];
bool v[MAXN];
int n;

string pstr[MAXN][30];

bool DFS(int cur,int t)
{
	int i;
	v[cur]=true;
	if(cur==t)	return true;
	for(i=1;i<=n+27;++i)
	{
		if(v[i])	continue;
		if(cap[cur][i]-flow[cur][i]>0 || flow[i][cur]>0)
		{
			pa[i]=cur;
			if(DFS(i,t))	return true;
		}
	}
	return false;
}
int findflow(int s,int t)
{
	int i,pre;
	int f=INF;
	for(i=t;i!=s;i=pa[i])
	{
		pre=pa[i];
		if(cap[pre][i]-flow[pre][i]>0)
			f=min(f,cap[pre][i]-flow[pre][i]);
		else
			f=min(f,flow[i][pre]);
	}
	for(i=t;i!=s;i=pa[i])
	{
		pre=pa[i];
		if(cap[pre][i]-flow[pre][i]>0)
			flow[pre][i]+=f;
		else
			flow[i][pre]-=f;
	}
	return f;
}

int Ford(int s,int t)
{
	int ret=0;
	while(1)
	{
		memset(v,false,sizeof(v));
		if(!DFS(s,t))	break;
		ret+=findflow(s,t);
	}
	return ret;
}

int main()
{
	//freopen("f","r",stdin);
	int s,t,edge;
	int i,j,len;
	int casenum,cc;
	string tmp;
	scanf("%d",&casenum);
	for(cc=1;cc<=casenum;++cc)
	{
		scanf("%d",&n);

		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		memset(pa,0,sizeof(pa));
		for(i=1;i<=n;++i)
			cap[0][i]=1;
		for(i=1;i<=n;++i)
			cap[n+i][n+27]=1;

		for(i=1;i<=n;++i)
		{
			scanf("%d",&edge);
			while(edge--)
			{
				cin>>tmp;
				if(tmp[0]>='a' && tmp[0]<='z')
						tmp[0]+='A'-'a';
				for(j=1;j<tmp.length();++j)
				{
					if(tmp[j]>='A' && tmp[j]<='Z')
						tmp[j]+='a'-'A';
				}
				pstr[i][tmp[0]-'A'+1]=tmp;
				cap[i][n+tmp[0]-'A'+1]=1;
			}
		}
		printf("Case #%d:\n",cc);
		Ford(0,n+27);

		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				//printf("%d ",flow[i][j]);
				if(flow[j][n+i]!=0)
				{
					cout<<pstr[j][i]<<endl;
					break;
				}
			}
		}
	}
	return 0;
}

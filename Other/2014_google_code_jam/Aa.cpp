#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<map>
using namespace std;

#define MAXN 180
#define INF 9999999
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int pa[MAXN];
int v[MAXN];
map<int,string> ele;
int n,l;
string swi[50];
string tmp[50];
bool DFS(int cur,int t)
{
	int i;
	v[cur]=true;
	if(cur==t)	return true;
	for(i=0;i<=2*n+1;++i)
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
void change(int b)
{
	int i,j;

	{
		for(i=1;i<=n;++i)
		{
			tmp[i]=swi[i];
			if(b!=0)
			{
				if(tmp[i][l-b]=='1')
					tmp[i][l-b]='0';
				else
					tmp[i][l-b]='1';

			}
			cout<<b<<" "<<tmp[i]<<endl;
		}
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(tmp[i]==ele[j])
				cap[i][n+j]=1;
			else
				cap[i][n+j]=0;
		}
	}
}

int main()
{
	int casenum,cc;
	scanf("%d",&casenum);
	bool ya=true;
	int i;
	string in;
	int ans;
	//freopen("input","r",stdin);
	freopen("Aa.out","w",stdout);
	for(cc=1;cc<=casenum;++cc)
	{
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		memset(pa,0,sizeof(pa));
		ele.clear();
		ya=false;
		scanf("%d%d",&n,&l);
		printf("Case #%d: ",cc);
		for(i=1;i<=n;++i)
		{
			cin>>swi[i];
			cap[n+i][2*n+1]=1;
		}
		for(i=1;i<=n;++i)
		{
			cin>>in;
			ele[i]=in;
			cap[0][i]=1;
		}


		for(i=0;i<=l;++i)
		{
			change(i);
			memset(flow,0,sizeof(flow));
			if(Ford(0,2*n+1)==n)
			{
				ya=true;
				ans=i;
				break;
			}
			int j,k;
			for(j=0;j<=2*n+1;++j)
			{
				for(k=0;k<=2*n+1;++k)
					printf("%d ",cap[j][k]);
				printf("\n");
			}
			printf("========\n");
			for(j=0;j<=2*n+1;++j)
			{
				for(k=0;k<=2*n+1;++k)
					printf("%d ",flow[j][k]);
				printf("\n");
			}
			printf("========\n");
		}


		if(ya)
			printf("%d\n",ans);
		else
			printf("NOT POSSIBLE\n");
	}
	return 0;
}

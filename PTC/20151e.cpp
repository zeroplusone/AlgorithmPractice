#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXN 2200
#define INF 999999

int dis[MAXN];
struct EDGE
{
	int a,b;
	int st,et,len;
	bool pass;
}e[MAXN*2];

int diff(int s,int e)
{
	if(s/100==e/100)
		return e-s;
	else
		return (60-s%100)+(e/100-(s/100+1))*60+e%100;	
}
int addtime(int s,int addt)
{
	return s/100*100+(s%100+addt)/60*100+(s%100+addt)%60;
}
int main()
{
	freopen("testdata.in","r",stdin);
	int caseN,cc;
	int n,edgeN,i,j,x,y,tmp,tran;
	scanf("%d",&caseN);
	int qa,qb,qst,qet;
	for(cc=1;cc<=caseN;++cc)
	{
		printf("%d\n",cc);
		scanf("%d%d",&n,&edgeN);
		for(i=0;i<=n;++i)
			dis[i]=INF;
		for(i=0;i<edgeN;++i)		
		{
			scanf("%d%d%d%d",&e[i].st,&e[i].a,&e[i].et,&e[i].b);
			e[i].len=diff(e[i].st,e[i].et);
			e[i].pass=true;
		}
		scanf("%d%d%d%d",&qst,&qa,&qet,&qb);
		dis[qa]=0;
		for(i=0;i<n-1;++i)	//bellman-ford
		{
			for(j=0;j<edgeN;++j)
			{
				if(!e[j].pass)	continue;
				x=e[j].a;	y=e[j].b;				

					if(x==qa)
					{
						tmp=e[j].len+diff(qst,e[j].st);
						e[j].pass=false;
					}
					else
					{
						tran=diff(addtime(qst,dis[x]),e[j].st);
						if(tran>=5)
							tmp=dis[x]+e[j].len+tran;
						else
						{ 
							tmp=INF;
							e[j].pass=false;
						}
					}
					if(dis[y]>tmp)
						dis[y]=tmp;

				//printf("%d to %d ( %d min) mid %d\n",x,y,e[j].len,diff(addtime(qst,dis[x]),e[j].st));						
			}
		}
		/*for(i=1;i<=n;++i)
			printf("%d # ",dis[i]);
		printf("\n");*/
		if(dis[qb]==INF)		
			printf("no connection\n");		
		else if(addtime(qst,dis[qb])+5>qet)
			printf("time out\n");	
		else
			printf("%04d %d\n",addtime(qst,dis[qb]),dis[qb]);	
	}
	return 0;
}

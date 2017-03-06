#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 20
#define INF 999999
int r[MAX][MAX];
int tran[MAX];
int odd[MAX];
int dp[1<<MAX];
bool vv[1<<MAX];

int match(int bit,int n)
{

	if(bit==0)
		return 0;
	if(vv[bit])
		return dp[bit];
	for(int i=0;i<n;++i)
	{
		printf("%d %d\n",bit,(1<<i));
		if(bit &(1<<i))
		{
			for(int j=i+1;j<n;++j)
			{
				if(bit & (1<<j))
				{
					printf("@%d\n",r[tran[i]][tran[j]]);
					dp[bit]=min(dp[bit],match(bit-(1<<i)-(1<<j),n)+r[tran[i]][tran[j]]);
					vv[bit]=true;
				}
			}
		}
	}
	return dp[bit];
}

int main()
{
	int v,e,v1,v2,l,sum,num,plus;
	while(scanf("%d",&v)!=EOF)
	{
		if(v==0)
			break;
		for(int i=0;i<v;++i)    //Initial
		{	
			for(int j=0;j<v;++j)
				r[i][j]=INF;
			odd[i]=0;
		}
		memset(vv,false,sizeof(vv)); 
		for(int i=0;i<=(1<<MAX);++i)
			dp[i]=INF;			//End Initial
		
		if(v==0)
			break;
		scanf("%d",&e);
		sum=0;
		for(int i=0;i<e;++i)
		{
			scanf("%d %d %d",&v1,&v2,&l);
			sum+=l;
			v1--;	v2--;
			if(l<r[v1][v2])
			{
				r[v1][v2]=l;
				r[v2][v1]=l;
			}
			odd[v1]++;	odd[v2]++;
		}
		
		num=0;
		for(int i=0;i<v;++i)
		{
			if(odd[i]%2==1)
			{
				tran[num]=i;
				num++;
			}
		}
		/*for(int i=0;i<v;++i)
		{	for(int j=0;j<v;++j)
			{
				printf("%d ",r[i][j]);
				
			}
			printf("\n");
		}*/
		plus=match((1<<num)-1,num);
		printf("%d",plus);
	}
	return 0;
}
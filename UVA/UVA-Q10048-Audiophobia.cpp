/******************
Judge   : UVA
Problem : 10048 - Audiophobia
Course  : Course10
discribe: find the lowest sound in the path
Input	:

			7 9 3	//#node #edge #question
			1 2 50	//source destination sound
			1 3 60
			2 4 120
			2 5 90
			3 6 50
			4 6 80
			4 7 70
			5 7 40
			6 7 140
			1 7		//Q1
			2 6		//Q2
			6 2		//Q3
			7 6 3	//#node #edge #question
			1 2 50
			1 3 60
			2 4 120
			3 6 50
			4 6 80
			5 7 40
			7 5
			1 7
			2 4
			0 0 0	//end

Output	:
			Case #1
			80
			60
			60
			 
			Case #2
			40
			no path
			80
solve:
1.Bellman Ford
2.floyd
[bidirection ]
*******************/
//Bellman Ford
/*
#include<bits/stdc++.h>
using namespace std;

#define MAXN 500
#define MAXE 5000
#define INF 9999999
int d[MAXN];

struct edge
{
	int from,to,len;
}e[MAXE];

int main()
{
	int c,s,q;
	int i,j;
	int start,end;
	int tmpf,tmpt,tmpl,tmp;
	int casenum=1;
	int change=0;
	while(scanf("%d%d%d",&c,&s,&q)!=EOF)
	{
		if(c==0 && s==0 && q==0)	break;
		
		if(casenum!=1)	printf("\n");		
		printf("Case #%d\n",casenum++);
		s*=2;	
		for(i=0;i<s;i+=2)
		{
			scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].len);
			e[i+1].from=e[i].to;
			e[i+1].to=e[i].from;
			e[i+1].len=e[i].len;
		}
		while(q--)
		{
			for(i=0;i<=c;++i)	d[i]=INF;
			scanf("%d%d",&start,&end);
			d[start]=0;			
			for(i=0;i<c-1;++i)
			{
				change=0;
				for(j=0;j<s;++j)
				{
					tmpf=e[j].from;
					tmpt=e[j].to;
					tmpl=e[j].len;
					if(d[tmpf]!=INF)
					{	
						tmp=tmpl>d[tmpf]?tmpl:d[tmpf];
						if(d[tmpt]>tmp)
						{
							d[tmpt]=tmp;
							change=1;
						}
					}	
				}
				if(!change)	break;
			}
			if(d[end]==INF)
				printf("no path\n");
			else
				printf("%d\n",d[end]);
		}
	}
	return 0;
}
*/
//Floyd
#include<bits/stdc++.h>
using namespace std;

#define MAXN 500
#define MAXE 5000
#define INF 9999999
int d[MAXN][MAXN];

void reset(int n)
{
	int i,j;
	for(i=0;i<=n;++i)
	{
		for(j=0;j<=n;++j)
		{
			if(i==j)	d[i][j]=0;
			else 		d[i][j]=INF;
		}
	}		
}

void Floyd(int n)
{
	int i,j,k,tmp;
	for(k=1;k<=n;++k)
	{
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				tmp=d[i][k]>d[k][j]?d[i][k]:d[k][j];
				if(tmp<d[i][j])
					d[i][j]=tmp;
			}
		}
	}
}

int main()
{
	int c,s,q;
	int i,j;
	int start,end;
	int tmpf,tmpt,tmpl;
	int casenum=1;
	int change=0;
	while(scanf("%d%d%d",&c,&s,&q)!=EOF)
	{
		if(c==0 && s==0 && q==0)	break;
		
		if(casenum!=1)	printf("\n");		
		printf("Case #%d\n",casenum++);
		
		reset(c);
		for(i=0;i<s;i++)
		{
			scanf("%d%d%d",&tmpf,&tmpt,&tmpl);
			d[tmpf][tmpt]=d[tmpt][tmpf]=tmpl;
		}		
		Floyd(c);		
		while(q--)
		{			
			scanf("%d%d",&start,&end);			
			if(d[start][end]==INF)
				printf("no path\n");
			else
				printf("%d\n",d[start][end]);
		}
	}
	return 0;
}
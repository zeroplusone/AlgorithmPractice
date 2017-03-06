#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 1000

struct bomb
{
	int r,d;
	/*bool operator<(const bomb& p)const
	{
		return d<p.d;
	}*/
}b[MAXN];
int abc[MAXN];
int main()
{
	int n;
	int i,j;
	int sd,sr,si,snum;
	int win;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		snum=0;	sd=0; sr=0;	si=0;
		memset(abc,0,sizeof(abc));
		for(i=0;i<n;++i)
		{
			scanf("%d %d",&b[i].d,&b[i].r);
		}	
			//sort(b,b+n);
		for(i=0;i<n;++i)
		{
			win=1;

			for(j=0;j<n;++j)
			{
				//printf("!%d %d %d %d %d %d %d\n",n,i,j,b[i].d,b[j].d,b[i].r,b[j].r);
				if(i==j)	continue;
				
				if(b[i].d<b[j].d && b[i].r<b[j].r)
				{
					//printf("~%d %d\n",i,j);
					win=0;
					abc[j]++;
					//break;
				}
				/*if(b[i].d>b[j].d && b[i].r>b[j].r)
				{
					coun++;
				}*/
			}
			if(win==1)
			{
				snum++;
				//printf("%d %d %d %d %d %d\n",i,coun,sd,sr,b[i].d,b[i].r);
			}
				/*if(coun>0 && coun>=si)
				{
					if(coun>si)
					{
						sd=b[i].d;
						sr=b[i].r;
						si=coun;
						//printf("1\n");
					}
					else
					{
						if(b[i].d>sd)
						{
							//printf("2\n");
							sd=b[i].d;
							sr=b[i].r;
							si=coun;
						}
						else if(b[i].d==sd && b[i].r>sr)
						{
							sd=b[i].d;
							sr=b[i].r;
							si=coun;
							//printf("3\n");
						}
					}	
				}*/
			
		}
		for(i=0;i<n;++i)
		{
			if(abc[i]>=si && abc[i]!=0)
			{
				if(abc[i]>si)
				{
					sd=b[i].d;
					sr=b[i].r;
					si=abc[i];
						//printf("1\n");
				}
				else if(abc[i]==si)
				{
					if(b[i].d>sd)
					{
							//printf("2\n");
							sd=b[i].d;
							sr=b[i].r;
							si=abc[i];
					}
					else if(b[i].d==sd && b[i].r>sr)
					{
						sd=b[i].d;
						sr=b[i].r;
						si=abc[i];
							//printf("3\n");
					}
				}	
			}
		}
		printf("%d %d %d\n",snum,sd,sr);
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAXR 150
#define MAXC 55
char ans[MAXR][MAXC];
int r,c;
void print()
{
	int i,j;
	for(i=0;i<r;++i)
	{
		for(j=0;j<c;++j)
		{
			printf("%c",ans[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int t,tt;
	int m,num,part,count;
	double tmp;
	int i,j;
	int checki,checkj;
	scanf("%d",&t);
	freopen("c.out","w",stdout);
	for(tt=1;tt<=t;++tt)
	{		
		printf("Case #%d:\n",tt);
		scanf("%d%d%d",&r,&c,&m);
		num=r*c-m;


		for(i=0;i<r;++i)
		{
			for(j=0;j<c;++j)
			{
				ans[i][j]='*';
			}
		}
		for(i=0;i<50;++i)
		{
			if((r-i)*(c-i)<num)
			{
				part=i-1;
				break;
			}
		}
		//printf("!!%d\n",part);
		for(i=0,count=0;i<r-part;++i)
		{
			for(j=0;j<c-part;++j)
			{
				count++;
				ans[i][j]='.';
				if(count>=num)
				{
					checki=i+1;
					checkj=j+1;
					break;
				}
			}
			if(count>=num)
					break;
		}
		//printf("%d %d\n",checki,checkj);
		ans[0][0]='c';
		if(r*c-m==1)
			print();
		if(r==1 || c==1)
		{
			print();
		}
		else if(checki==1 || checkj==1)
			printf("Impossible\n");
		else
		{
			print();
		}
	}
	return 0;
}
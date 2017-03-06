#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 1100
int a[MAX];
int b[MAX];

int main()
{
	int c1,c2,c3,c4;
	int n,m,sb,st,min,tmpb,tmpt;
	while(scanf("%d %d %d %d %d %d",&c1,&c2,&c3,&c4,&n,&m)!=EOF)
	{
		sb=0;	st=0;
		tmpb=0;	tmpt=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
			sb+=a[i];
			if(c1*a[i]<c2)
				tmpb+=c1*a[i];
			else
				tmpb+=c2;
		}
		for(int i=0;i<m;++i)
		{
			scanf("%d",&b[i]);
			st+=b[i];
			if(c1*b[i]<c2)
				tmpt+=c1*b[i];
			else
				tmpt+=c2;
		}
		min=c4;
		min=c3*2<min?c3*2:min;
		if(c3>=tmpb && c3>=tmpt)
			min=tmpb+tmpt<min?tmpb+tmpt:min;
		else if(c3>=tmpb && c3<=tmpt)
			min=tmpb+c3<min?tmpb+c3:min;
		else if(c3<=tmpb && c3>=tmpt)
			min=tmpt+c3<min?tmpt+c3:min;
		
		printf("%d\n",min);
		
	}
	return 0;
}
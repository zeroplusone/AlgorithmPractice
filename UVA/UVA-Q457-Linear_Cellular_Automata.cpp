#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n;
int dna[10];
int today[40];
int next[40];

void print()
{
	for(int i=0;i<40;++i)
	{
		if(next[i]==0)
			printf(" ");
		else if(next[i]==1)
			printf(".");
		else if(next[i]==2)
			printf("x");
		else if(next[i]==3)
			printf("W");
	}	
	printf("\n");
}

int main()
{

	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		if(i)
			printf("\n");
		for(int j=0;j<10;++j)
			scanf("%d",&dna[j]);
		memset(today,0,sizeof(today));
		memset(next,0,sizeof(next));
		today[19]=1; next[19]=1;
		for(int k=0;k<50;++k)
		{
			print();
			for(int l=0;l<40;++l)
			{
				if(l==0)
					next[l]=dna[today[l]+today[l+1]];
				else if(l==39)
					next[l]=dna[today[l]+today[l-1]];
				else
					next[l]=dna[today[l]+today[l-1]+today[l+1]];
			}
			for(int m=0;m<40;++m)
				today[m]=next[m];
		}
	}
	return 0;
}

/*dna 隔天的密度=DNA[自己+前一個+後一個今天的密度]*/
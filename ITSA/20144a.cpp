#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 13
int in[MAXN][MAXN];
int tmp[MAXN][MAXN];
char str[100];
int n;

void rr()
{
	int i,j,a,b;
	for(i=0,a=n-1;i<n;++i,--a)
		for(j=0;j<n;++j)
			tmp[j][a]=in[i][j];
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			in[i][j]=tmp[i][j];
}

void ll()
{
	int i,j,a,b;
	for(i=0;i<n;++i)
		for(j=0,a=n-1;j<n;++j,--a)
			tmp[a][i]=in[i][j];
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			in[i][j]=tmp[i][j];
}

void nn()
{
	int i,j,a,b;
	for(i=0,a=n-1;i<n;++i,--a)
		for(j=0;j<n;++j)
			tmp[a][j]=in[i][j];
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			in[i][j]=tmp[i][j];
}
int main()
{
	int t;
	int i,j,len;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n*n;++i)
			in[i/n][i%n]=i+1;
		getchar();
		scanf("%s",str);
		len=strlen(str);
		for(i=0;i<len;++i)
		{
			if(str[i]=='R')
				rr();
			else if(str[i]=='L')
				ll();
			else if(str[i]=='N')
				nn();
		}
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
				printf("%d%c",in[i][j],j==n-1?'\n':' ');
		}
		if(t!=0)
			printf("\n");
	}
	return 0;
}

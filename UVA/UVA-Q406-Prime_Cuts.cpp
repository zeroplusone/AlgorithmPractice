#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

#define MAXN 1100
bool isprime[MAXN];
int prime[MAXN];
int coun;

void makeprime()
{
	int i,j;
	coun=1;
	memset(isprime,true,sizeof(isprime));
	isprime[0]=false;
	for(i=2;i<=sqrt(MAXN);++i)
	{
		if(isprime[i])
		{
			for(j=i*i;j<MAXN;j+=i)
			{
				isprime[j]=false;	
			}
		}
	}
	for(i=1;i<MAXN;++i)
	{
		if(isprime[i])
			prime[coun++]=i;
	}
}

void print(int start,int end)
{
	for(int i=start;i<=end;++i)
	{
		printf(" %d",prime[i]);
	}
	printf("\n");
}

int main()
{
	makeprime();
	int a,b,i,num;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		printf("%d %d:",a,b);
		for(i=1;i<coun;++i)
		{
			if(prime[i]>a)
			{
				i--;	
				break;
			}
		}
		if(i%2==1)
		{
			num=b*2-1;
			if(num>i)
				print(1,i);
			else
				print((i+1)/2-b+1,(i+1)/2+b-1);
		}	
		else
		{
			num=b*2;
			if(num>i)
				print(1,i);
			else
				print((i+2)/2-b,i/2+b);
		}
	}
}
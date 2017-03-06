/******************
Judge   : poj
Problem : 2541-Binary Witch
Course  : Course17
discribe:  ak+t the last t elements. If that postfix is encountered somewhere before the position N-t+1,
Input   :
		
			10 7		//n L
			1101110010  //a1~ an 

Output	:

			0100100	//an+1~an+L
solve:
			KMP
			suffix->reverse => prefix
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 1000100
int pi[MAXN];
char w[MAXN],t[MAXN*100];
int n,l;

void buildPi()
{	
	int i,j,len;
	len=strlen(w+1);
	memset(pi,0,(len+1)*sizeof(int));
	pi[1]=0;	j=0;
	for(i=2;i<=len;++i)
	{
		while(j>0 && w[j+1]!=w[i])
		{
			j=pi[j];
		}

		if(w[j+1]==w[i])
			j++;
		pi[i]=j;

	}
}

void KMP()
{
	int i,j;
	int lent=strlen(t+1);
	int lenw=strlen(w+1);
	j=0;
	for(i=1;i<=lent;++i)
	{
		while(j>0 && t[i]!=w[j+1])
		{
			j=pi[j];
		}
			
		if(t[i]==w[j+1])
			j++;
		if(j==lenw)
		{
			j=pi[j];
			ans++;
		}
	}
}

int main()
{	
	while(scanf("%d %d",&n,&l)!=EOF)
	{
		getchar();
		scanf("%s",w+1);		
		for()
		buildPi();
		//for(int i=1;i<=strlen(w+1);++i)
		//	printf("%d ",pi[i]);
		//printf("\n");
		ans=0;
		KMP();
		printf("%d\n",ans);
	}
	return 0;
}
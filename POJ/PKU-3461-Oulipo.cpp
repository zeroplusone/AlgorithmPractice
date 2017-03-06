/******************
Judge   : poj
Problem : 3461-Oulipo
Course  : Course17
discribe:  the number of occurrences of the word W in the text T.
Input   :
		
			3		//#case
			BAPC	//W
			BAPC	//T
			AZA
			AZAZAZA
			VERDI
			AVERDXIVYERDIAN

Output	:

			1
			3
			0
solve:
			KMP
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 10010
int pi[MAXN];
char w[MAXN],t[MAXN*100];
int ans;

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
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
		getchar();
		scanf("%s",w+1);		
		getchar();
		scanf("%s",t+1);	

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
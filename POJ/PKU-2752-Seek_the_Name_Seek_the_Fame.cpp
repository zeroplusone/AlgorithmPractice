/******************
Judge   : poj
Problem : 2752-Seek the Name, Seek the Fame
Course  : Course17
discribe:  Step1. Connect the father's name and the mother's name, to a new string S. 
Step2. Find a proper prefix-suffix string of S (which is not only the prefix, but also the suffix of S). 
Input   :
		
			ababcababababcabab //1~400000
			aaaaa

Output	:

			2 4 9 18
			1 2 3 4 5
solve:
			KMP
*******************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 400100
int pi[MAXN];
char w[MAXN];
int ans[MAXN];
int len;

void buildPi()
{	
	int i,j;
	
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

int main()
{
	int i,j;
	while(scanf("%s",w+1)!=EOF)
	{
		getchar();
		len=strlen(w+1);
		buildPi();
		for(i=len,j=0;pi[i]>0;i=pi[i],j++)
		{
			ans[j]=i;
		}
		ans[j]=i;
		for(i=j;i>=0;--i)
			printf("%d%c",ans[i],i==0?'\n':' ');
	}
	return 0;
}
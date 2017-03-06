/******************
Judge   : poj
Problem : 2406- Power Strings
Course  : Course17
discribe:   print the largest n such that s = a^n for some string a
			The length of s will be at least 1 and will not exceed 1 million characters.
Input   :
		
			abcd
			aaaa
			ababab
			.

Output	:
			1
			4
			3
solve:
			KMP
*******************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 1000100
int pi[MAXN];
char w[MAXN]/*,t[MAXN]*/;
int ans,len;

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

	while(scanf("%s",w+1)!=EOF)
	{	
		getchar();
		if(!strcmp(w+1,"."))	
			break;
		len=strlen(w+1);
		buildPi();
		
		/*for(int i=0;i<=strlen(w+1);++i)
			printf("%d ",pi[i]);*/
		if(len%(len-pi[len])==0)
			ans=len/(len-pi[len]);
		else
			ans=1;
		printf("%d\n",ans);
	}
	return 0;
}
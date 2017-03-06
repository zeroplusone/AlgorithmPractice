/******************
Judge   : poj
Problem : 1961-Period
Course  : Course17
discribe:   the prefix of S with length i can be written as AK
Input   :
		
			3
			aaa
			12
			aabaabaabaab
			0

Output	:

			Test case #1
			2 2
			3 3

			Test case #2
			2 2
			6 2
			9 3
			12 4
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
char w[MAXN];
int n;

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

int main()
{
	int tt=1,ans;	
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		getchar();
		printf("Test case #%d\n",tt++);
		scanf("%s",w+1);		
		buildPi();
		for(int i=1;i<=n;++i)
		{
			ans=i/(i-pi[i]);
			if(ans>1 && (i%(i-pi[i])==0))
				printf("%d %d\n",i,ans);
		}
		printf("\n");
	}
	return 0;
}
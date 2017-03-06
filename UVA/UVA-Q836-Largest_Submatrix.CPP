/******************
Judge   : UVA
Problem : 836 - Largest Submatrix
Course  : Course9
discribe:  determines the number of elements of the largest submatrix of ones in A. Largest here is measured by area.
			
Input   : 
			1	//CASE

			10111000	//ARRAY
			00010100
			00111000
			00111010
			00111111
			01011110
			01011110
			00011110
Output  : 
			16	//largest submatrix 
Solve   : dp
*******************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXN 30
int x[MAXN][MAXN];
int mss[MAXN];
char in[MAXN];

int main()
{
	int n,num,i,j,k,len,ans,tmp;
	scanf("%d",&n);
	getchar();getchar();
	while(n--)
	{
		memset(x,0,sizeof(x));
		memset(mss,0,sizeof(mss));
		num=1;
		
		while(gets(in))
		{		
			tmp=strlen(in);
			if(tmp==0)
				break;
			len=tmp;
			for(i=1;i<=tmp;++i)
			{
				x[num][i]=in[i-1]=='1'?x[num][i-1]+1:0;				
			}
			num++;
		}
		
		ans=0;
		for(i=0;i<len;++i)
		{
			for(j=i+1;j<=len;++j)
			{
				
				for(k=1;k<=num;++k)
				{
					if(x[k][j]-x[k][i]==j-i)
						mss[k]=mss[k-1]+1;
					else
						mss[k]=0;
					ans=mss[k]*(j-i)>ans?mss[k]*(j-i):ans;
				}
				
			}
		}
		printf("%d\n",ans);	
		if(n!=0)	printf("\n");
	}
	return 0;
}
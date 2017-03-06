#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

#define MAX 300
int pr[MAX];
int qr[MAX];
int lcs[MAX][MAX];

int main()
{
	int ans,c,p,q,n;
	scanf("%d",&c);
	for(int ii=1;ii<=c;++ii)
	{	
		scanf("%d %d %d",&n,&p,&q);
		
		ans=0;
		for(int i=0;i<=p;++i)
			for(int j=0;j<=q;++j)
				lcs[i][j]=0;
				
		for(int i=0;i<p;++i)
			scanf("%d",&pr[i]);
		for(int i=0;i<q;++i)
			scanf("%d",&qr[i]);
			
		for(int i=1;i<p-1;++i)
		{
			for(int j=1;j<q-1;++j)
			{
				if(pr[i]==qr[j])
					lcs[i+1][j+1]=lcs[i][j]+1;
				else if(pr[i]!=qr[j])
				{
					lcs[i+1][j+1]=lcs[i][j+1]>lcs[i+1][j]?lcs[i][j+1]:lcs[i+1][j];
				}
				if(lcs[i+1][j+1]>ans)
					ans=lcs[i+1][j+1];
			}
		}
		printf("Case %d: %d\n",ii,ans+2);
	}
	return 0;
}

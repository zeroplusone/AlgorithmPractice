#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

char x[25];
int xnum[13];
int main()
{
	int n,min,ans;
	while(scanf("%d",&n)!=EOF)
	{
		min=25;
		ans=0;
		if(n==0)
			break;
		memset(xnum,0,sizeof(xnum));	
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<25;++j)
			{
				scanf("%c",&x[j]);
				if(x[j]==' ')
					xnum[i]++;
			}		
			if(xnum[i]<min)
				min=xnum[i];
			getchar();
		}
		for(int k=0;k<n;++k)		
			ans+=xnum[k]-min;
		printf("%d\n",ans);
		
	}
	return 0;
}

/*一個數字n表示有n列 n=0結束
  每一列都插入x直到有其中一列滿(一列都25個字元)
  此時還有幾個空白*/
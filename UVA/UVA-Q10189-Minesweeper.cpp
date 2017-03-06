#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int a,b;
	int count=0;
	int flag=0;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		getchar();
		if(a==0 && b==0)
			break;
		else if(flag)
			printf("\n");
		flag=1;
		char bomb[a][b];
		int num[a][b];
		
		for(int i=0;i<a;++i)
		{
			for(int j=0;j<b;++j)
			{
				scanf("%c",&bomb[i][j]);	
						
				num[i][j]=0;
			}
			getchar();
			
		}
		
		for(int i=0;i<a;++i)
		{
			for(int j=0;j<b;++j)
			{
				if(bomb[i][j]=='*')
				{
					
					if((i-1)>=0)
					{
						if((j-1)>=0)num[i-1][j-1]++;
						num[i-1][j]++;
						if((j+1)<b)num[i-1][j+1]++;
					}
					if((i+1)<a)
					{
						if((j-1)>=0)num[i+1][j-1]++;
						num[i+1][j]++;
						if((j+1)<b)num[i+1][j+1]++;
					}
					if((j-1)>=0)num[i][j-1]++;
					if((j+1)<b)num[i][j+1]++;					
				}
			}
			
		}
		
		count++;
		printf("Field #%d:\n",count);
		for(int i=0;i<a;++i)
		{
			for(int j=0;j<b;++j)
			{
				if(bomb[i][j]=='*')
					printf("*");
				else
					printf("%d",num[i][j]);
			}
			printf("\n");
		}
		
		
		
	}
	return 0;
}

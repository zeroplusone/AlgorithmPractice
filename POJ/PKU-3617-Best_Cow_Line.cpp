#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define MAXN 2001
char cow[MAXN];
 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)	
		cin>>cow[i];	
	
	int beg=0;
	int end=n-1;
	int tmpb,tmpe,flag;
	int count=0;
	for(int j=0;j<n;++j)
	{
		
		
			if(cow[beg]>cow[end])
			{
				printf("%c",cow[end]);
				count++;
				end--;
			}
			else if(cow[beg]<cow[end])
			{
				printf("%c",cow[beg]);
				count++;
				beg++;		
			}
			else if(j==n-1)
			{
				printf("%c\n",cow[beg]);
				break;
			}
			else if(cow[beg]==cow[end])
			{
				tmpb=beg+1;
				tmpe=end-1;
				flag=0;
				while(cow[tmpb]==cow[tmpe])
				{
					if(tmpb>tmpe)
					{
						printf("%c",cow[beg]);
						beg++;
						count++;
						flag=1;
						break;
					}				
					tmpb++;
					tmpe--;
				}
				if(!flag)
				{					
					if(cow[tmpb]>cow[tmpe])
					{
						count++;
						printf("%c",cow[end]);
						end--;
					}
					else if(cow[tmpb]<cow[tmpe])
					{
						count++;
						printf("%c",cow[beg]);
						beg++;		
					}
				}
			}
		
		if((count)%80==0 && j!=0)
			printf("\n");
	}
	return 0;
}
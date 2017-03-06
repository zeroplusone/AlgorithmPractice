#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
#define MAXN 35

int f[MAXN];
int r[MAXN][MAXN];
bool no[MAXN];
int main()
{
	int n,in,i,j,ans,tmp,now;
	bool change=false;
	stack<int> coco;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		memset(f,0,sizeof(f));
		memset(no,false,sizeof(no));
		while(!coco.empty())	coco.pop();	
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				scanf("%d",&r[i][j]);
				f[i]+=r[i][j];
			}
			f[i]--;
		}

		now=n;
		do
		{	
			/*for(j=0;j<n;++j)
			{
				printf("%d ",f[j]);
			}printf("\n");*/
			while(!coco.empty())
			{	
				now--;
				tmp=coco.top();
				for(i=0;i<n;++i)
					if(r[tmp][i]==1 && tmp!=i)	f[i]--;
				coco.pop();
			}
			//printf("~%d\n",now-1-f[i]);
			for(i=0;i<n;++i)
			{
				//printf("~%d \n",now-1-f[i]);
				if(!no[i] &&( f[i]<2 || now-1-f[i]<2))
				{
					no[i]=true;
					f[i]=999;
					coco.push(i);
				}	
			}
			
		}while(!coco.empty());
		ans=0;
		for(j=0;j<n;++j)
			{
				if(!no[j])	ans++;
			}
		printf("%d\n",ans);
	}
	return 0;
}

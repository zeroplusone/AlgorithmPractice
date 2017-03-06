#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 80

struct list
{
	int num[4];
}l[MAX];

bool compare(int a,int b)
{
	int pa,pb,check1=0,check2=0;
	for(pa=3,pb=3;pa>=0 && pb>=0;)
	{
		if(l[a].num[pa]>=l[b].num[pb])
		{
			check1++;
			if(l[a].num[pa]>l[b].num[pb])
				check2++;
			pa--;	pb--;
		}
		else
		{
			/*for(int i=0;i<pb;++i)
			{
				if(l[a].num[pa]>l[b].num[i])
				{
					check2++;
					break;
				}
			}	*/	
			pb--;
		}
	}
	//printf("@%d %d\n",check1,check2);
	if(check1>=3 && check2>=1)
		return true;
	else
		return false;
}

int main()
{
	int t,n,ans;
	int in[4];
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d%d%d%d",&in[0],&in[1],&in[2],&in[3]);
			sort(in,in+4);
			for(int j=0;j<4;++j)
				l[i].num[j]=in[j];
		}
		int pass;
		for(int i=0;i<n;++i)
		{
			pass=0;
			for(int j=0;j<n;++j)
			{
				if(i!=j)
				{
					if(compare(i,j))
						pass++;
				}
			}
			if(pass==n-1)
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
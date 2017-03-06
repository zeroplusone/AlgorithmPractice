#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAXN 1000100
char in[MAXN];
int fail[MAXN];
int len;

void build_fail()
{
	int cur;
	cur=fail[0]=-1;
	for(int i=1;i<len;++i)
	{
		while(cur!=-1 && in[cur+1]!=in[i])
		{
			cur=fail[cur];
		}
		if(in[cur+1]==in[i])
			cur++;
		fail[i]=cur;
	}
}


int main()
{
	int T;
	int i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",in);
		len=strlen(in);
		build_fail();
		ans=fail[len-1]+1;
		if(ans>len/2)
			ans=len/2;
		printf("%d\n",ans);
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXN 20
char convert[11][MAXN]={"","","2","3","322","5","53","7","7222","7332"};
char ans[MAXN*4];
char in[MAXN];

int main()
{
	int n;
	int i,j,len,cnt;
//	int T;
//	scanf("%d",&T);
//	while(T--)
//	{
		while(scanf("%d",&n)!=EOF)
		{
			scanf("%s",in);
			cnt=0;
			for(i=0;i<n;++i)
			{
				len=strlen(convert[in[i]-'0']);	
				for(j=0;j<len;++j)	
					ans[cnt++]=convert[in[i]-'0'][j];
			}
			sort(ans,ans+cnt);
			for(i=cnt-1;i>=0;--i)
				printf("%c",ans[i]);
			printf("\n");			
		}	
//	}
	
}


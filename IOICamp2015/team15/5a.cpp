#include <stdio.h>
#include <string.h>

long long dp[30][50][1000];

long long cc[900][900];

void build()
{
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=1;
	for(int i=1; i<30; i++){
		for(int j=1; j<45; j++){
			for(int k=j; k<1000; k++){
				int num=0;
				for(int l=1; l<=j; l++){
					if(k-j>=0)
						if(dp[i-1][j-l][k-j]>=0)
							num+=dp[i-1][j-l][k-j];
				}
				dp[i][j][k]=num;
			}
		}
	}
}

int main()
{
	int cas;
	int n,k,s;
	long long ans;
	build();
	scanf("%d",&cas);
	while(cas--){
		scanf("%d %d %d",&n,&k,&s);
		long long ans=0;
		for(int i=1; i<=n; i++){
			if(dp[k][i][s]>0)
				ans+=dp[k][i][s];
		}
		printf("%lld\n",ans);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <bitset>


using namespace std;

int prime[10005];
int isp[10005];
int pcnt;

int p[10005];

void make_prime()
{
	pcnt=0;
	memset(isp,0,sizeof(isp));
	for(int i=2; i<1005; i++){
		if(isp[i]==0){
			prime[pcnt++]=i;
		}
		for(int j=0; j<pcnt && i*prime[j]<1005; j++){
			isp[i*prime[j]]=1;
			if(i%prime[j]==0){
				break;
			}
		}
	}
}

int main()
{
	int cas;
	int n,k;
	make_prime();
	
	scanf("%d",&cas);
	while(cas--){
		scanf("%d %d",&n,&k);
		int ans=0;
		for(int i=0; i<k; i++){
			scanf("%d",&p[i]);
		}
		sort(p,p+k);
		int har=0;
		for(int i=0; i<k; i++){
			har=i+1;
			if(p[i]>31){
				break;
			}
		}
		bitset<20> bit;
		bit.reset();
		bitset<1001> light;
		
		while(bit[har]==false){
			light.reset();
			for(int i=0; i<har; i++){
				if(bit[i]==true){
					for(int j=p[i]; j<=n; j+=p[i]){
						light.flip(j);
					}
				}
			}
			for(int i=har; i<k; i++){
				int sum=0;
				for(int j=p[i]; j<=n; j+=p[i]){
					if(light[j]==0){
						sum++;
					}
				}
				if(sum>(n/p[i])-sum){
					for(int j=p[i]; j<=n; j+=p[i]){
						light.flip(j);
					}
				}
			}
			if(ans<light.count()){
				ans=light.count();
			}
			for(int j=0; j<=har; j++){
				if(bit[j]==0){
					bit.flip(j);
					break;
				}else{
					bit.flip(j);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

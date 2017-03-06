#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;

#define MAXN 120
long long int price[MAXN*2];
long long int ans[MAXN*2];

int main(){
	int t, tNum;
	int n, ansnum;
	queue<long long int> err;
	scanf("%d", &tNum);
	for(t = 1; t <= tNum; ++t){
		printf("Case #%d:", t);
		scanf("%d", &n);
		while(!err.empty())	err.pop();
		ansnum = 0;
		for(int i = 0; i < 2*n ;++i){
			scanf("%lld", &price[i]);
			if(price[i]%3 == 0 && price[i]%4!=0){
				ans[ansnum++]=price[i];
				err.push(price[i]/3*4);
			} else if(price[i]%3 == 0 &&price[i]%4 == 0){
				if(err.empty()){
					ans[ansnum++]=price[i];
					err.push(price[i]/3*4);
				} else if(price[i]==err.front()){
					err.pop();
				} else{
					ans[ansnum++]=price[i];
					err.push(price[i]/3*4);
				}
			}else{
				err.pop();
			}
		}
		for(int i = 0; i < n; ++i){
			printf(" %lld",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
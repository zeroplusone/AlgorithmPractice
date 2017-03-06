#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;

#define MAXN 120
int price[MAXN*2];
int fourtime[MAXN*2];
int ans[MAXN];

int main(){
	int t, tNum;
	int n, ansnum, fournum;
	queue<int> err;
	scanf("%d", &tNum);
	for(t = 1; t <= tNum; ++t){
		printf("Case #%d:", t);
		scanf("%d", &n);
		while(!err.empty())	err.pop();
		ansnum = 0;
		fournum = 0;
		for(int i = 0; i < 2*n || ansnum == n;++i){
			scanf("%d", &price[i]);
			fourtime[i]=price[i]/3*4;
			printf("%d %d %d\n",price[i], fourtime[fournum],fournum);
			if(price[i] != fourtime[fournum]){
				ans[ansnum] = price[i];
				ansnum++;
				while(!err.empty() && fournum==err.front()){
					err.pop();
					fournum++;
				}
				err.push(i);
				
			}
		}
		for(int i = 0; i < n; ++i){
			printf(" %d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
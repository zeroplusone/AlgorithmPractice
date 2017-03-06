#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

#define MAXD 100000010
int dancer[MAXD];

int main(){
	int t, tNum;
	int d, k, n;
	int pre, init, tmp;
	int i, j;
	scanf("%d", &tNum);
	for(t = 1; t <= tNum; ++t){
		printf("Case #%d:", t);
		scanf("%d%d%d", &d, &k, &n);
		for(i = 0;i < d; ++i){
			dancer[i] = i + 1;
		}
		
		for(j=0;j<d;++j)
				printf("%d ",dancer[j]);
			printf("\n");
		
		for(i = 0; i < n; ++i){
			init = dancer[0] % 2 == 0? 1 : 0;
			if(init == 1){
				swap(dancer[0], dancer[d-1]);
			}

			for(j = init; j < d - init; j += 2){
				swap(dancer[j], dancer[j+1]);
			}
			
			for(j=0;j<d;++j)
				printf("%d ",dancer[j]);
			printf("\n");

		}
		pre = dancer[d-1];
		for(i = 0; i<d; ++i){
			if(dancer[i] == k){
				printf(" %d %d", dancer[(i+1)%d], pre);
			}
			pre = dancer[i];
		}

		printf("\n");
	}
	return 0;
}
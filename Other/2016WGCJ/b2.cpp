#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

#define MAXD 15
int dancer[MAXD];

int main(){
	int t, tNum;
	int d, k, n;
	int pre, init, init2, poi, i1, i2;
	int i, j;
	scanf("%d", &tNum);
	for(t = 1; t <= tNum; ++t){
		printf("Case #%d:", t);
		scanf("%d%d%d", &d, &k, &n);
		n = n % d;
		init = n;
		init2 = (1 - n + d) % d;
		if(k % 2!=0){
			i = (k-1)/2;
			poi = (init+i*2)%d;
			if((poi+d-1)%d >init2)
				i1 = ((poi+d-1)%d-init2)/2;
			else
				i1 = ((poi+d-1)%d+d-init2)/2;
			if((poi+1)%d >init2)
				i2 = ((poi+1)%d-init2)/2;
			else
				i2 = ((poi+1)%d+d-init2)/2;
			printf(" %d %d\n", ((i2+1) * 2)%d,((i1+1) * 2)%d);
		}else{
			i = k/2-1;
			poi = (init2+i*2)%d;
			if((poi+d-1)%d >init)
				i1 = ((poi+d-1)%d-init)/2;
			else
				i1 = ((poi+d-1)%d+d-init)/2;
			if((poi+1)%d >init)
				i2 = ((poi+1)%d-init)/2;
			else
				i2 = ((poi+1)%d+d-init)/2;
			printf(" %d %d\n", ((i2+1) * 2)%d,((i1+1) * 2)%d);
		}
		printf("%d %d %d\n",poi, i1, i2);
		/*
		for(i = 0; i< d/2; ++i){
			dancer[(init+i*2)%d] = i * 2 + 1;
			dancer[(init2+i*2)%d] = (i+1) * 2;
		}
*/
		
		printf("\n");
	}
	return 0;
}
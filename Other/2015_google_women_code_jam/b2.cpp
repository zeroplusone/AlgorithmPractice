#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

long long int ans, V, K;
long long int color[3];

long long int judge(){
	if(abs(color[0] - color[1]) <= V && abs(color[0] - color[2]) <= V && abs(color[1] - color[2]) <= V ){
		//printf("%lld %lld %lld\n", color[0], color[1], color[2]);
		return 1;
	}
	return 0;
}

void per(int index){
	if(index == 3){
		ans += judge();
		return;
	}
	for(int i = 0; i <= K; ++i){
		color[index] = i;
		per(index + 1);
	}
}

int main(){
	int t, tNum;
	

	scanf("%d", &tNum);
	for(t = 1; t <= tNum; ++t){
		printf("Case #%d: ", t);
		scanf("%lld %lld", &K, &V);

		ans = 0;
		per(0);
		printf("%lld\n", ans);
	}
	return 0;
}
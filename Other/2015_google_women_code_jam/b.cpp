#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
	int t, tNum;
	long long int V, K, ans;

	scanf("%d", &tNum);
	for(t = 1; t <= tNum; ++t){
		printf("Case #%d: ", t);
		scanf("%lld %lld", &K, &V);

		if(V == 0){
			ans = K + 1;
		} else if(K == V){
			ans = pow(K + 1, 3);
		} else{
			ans = (K - V + 1) * pow(V + 1, 3) - (K - V) * pow(V, 3); 
		}
		printf("%lld\n", ans);
	}
	return 0;
}
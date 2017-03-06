#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct node
{
	float value, no, w, p, a;
}list[10];
bool cmp(node a, node b){
	return a.value > b.value; 
}
bool CMP(node a, node b){
	return a.no < b.no;
}
int main()
{
	float W, w1, w2, w3, p1, p2, p3, ans = 0;
	float a1, a2, a3;
	while(scanf("%f %f %f %f %f %f %f", &W, &list[0].w, &list[1].w, &list[2].w, &list[0].p, &list[1].p, &list[2].p) != EOF){
		list[0].value = list[0].p/list[0].w;
		list[1].value = list[1].p/list[1].w;
		list[2].value = list[2].p/list[2].w;
		
		list[0].no = 1;
		list[1].no = 2;
		list[2].no = 3;
		sort(list, list+3, cmp);
		
		if(W <= list[0].w) {
			ans = list[0].value*W;
			list[0].a = W;
			list[1].a = list[2].a = 0;
			//printf("%.3f", ans);
			//continue;
		}
		else if(W <= list[0].w + list[1].w){
			ans = list[0].value*list[0].w;
			ans += (W-list[0].w)*list[1].value;
			list[0].a = list[0].w;
			list[1].a = (W-list[0].w);
			list[2].a = 0;
			//printf("%.3f", ans);
			//continue;
		}
		else{
			ans = list[0].value*list[0].w + list[1].value*list[1].w;
			ans += (W-list[0].w-list[1].w)*list[2].value;
			list[0].a = list[0].w;
			list[1].a = list[1].w;
			list[2].a = (W-list[0].w-list[1].w);
			//printf("%.3f", ans);
			//continue;
		}
		sort(list, list+3, CMP);
		if(ans == 0)
			printf("0\n");
		else
		printf("%.3f %.3f %.3f %.3f\n", list[0].a, list[1].a, list[2].a, ans);
	}
	return 0;
}
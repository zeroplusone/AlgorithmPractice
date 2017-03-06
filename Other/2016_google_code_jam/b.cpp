#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

#define MAXN 110

int main(){
	int t, tNum;
    char str[MAXN], pre;
    int len, i, ans;
	scanf("%d", &tNum);
	for(t = 1; t <= tNum; ++t){
		printf("Case #%d: ", t);
		getchar();
        scanf("%s", str);
        len = strlen(str);
        ans = 0;

        for(i=len-1; i>=0; --i){
            if(str[i] == '+')
                len--;
            else
                break;
        }
        
        pre = '?';
        for(i=0; i<len; ++i){
            if(pre != str[i]){
                ans++;
                pre = str[i];
            }
        }

		printf("%d\n", ans);
	}
	return 0;
}

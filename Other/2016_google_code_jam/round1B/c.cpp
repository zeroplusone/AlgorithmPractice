#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
using namespace std;
#define MAXN 1100
string f[MAXN],s[MAXN];

int main(){
	int t, tNum, n, i, ans;
    map<string,int> first,second;
	scanf("%d", &tNum);
	for(t = 1; t <= tNum; ++t){
		scanf("%d",&n);
        first.clear();
        second.clear();
        for(i=0;i<n;++i){
            cin>>f[i]>>s[i];
            first[f[i]]++;
            second[s[i]]++;
        }
        printf("Case #%d: ", t);

        ans=n;
        for(i=0;i<n;++i){
            if(fisrt[f[i]]==1 || second[s[i]]==1){
                ans--;
                first[f[i]]=-1;
                second[s[i]]=-1;
            }
        }
        for(i=0;i<n;++i){
            if(first[f[i]]!=-1 && second[s[i]]!=-1){
                if(first[f[i]]==-1 
            }
        }
        
		scanf("",);

		printf("\n", );
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main(){
	int t, tNum, len;
    string in;
    vector<char> ans;

	scanf("%d", &tNum);
	for(t = 1; t <= tNum; ++t){
		printf("Case #%d: ", t);
		cin>>in;
        ans.clear();
        len=in.length();
        ans.insert(ans.begin(),in[0]);
        for(int i=1;i<len;++i){
            if(in[i]>=ans[0])
                ans.insert(ans.begin(),in[i]);
            else
                ans.push_back(in[i]);
        }

        for(int i=0;i<len;++i)
            printf("%c",ans[i]);
        printf("\n");
	}
	return 0;
}

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int casenum;
    string str1, str2;
    bool ans;
    int i,j,k;
    scanf("%d",&casenum);

    for(cc=1;cc<=casenum;++cc)
    {
        printf("Case #%d: ",cc);
        ans=true;
        cin>>str1>>str2;
        for(i=0,j=0;i<str1.length() && j<str2.length();){
            if(str1[i]=='*' && str2[j]=='*'){

            }else if(str1[i]=='*' && str2[j]!='*'){
                for(k=1;i<=5;++k){
                    if
                }
            }else if(str1[i]!='*' && str2[j]=='*'){

            }else if(str1[i]==str2[i]){
                i++;
                j++;
                continue;
            }else{
                ans=false;
                break;
            }
        }
        if(ans)
            printf("TRUE");
        else
            print("FALSE");
    }
    return 0;
}

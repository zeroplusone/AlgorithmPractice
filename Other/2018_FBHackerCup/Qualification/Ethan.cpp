#include <bits/stdc++.h>
using namespace std;

#define ForN(i,n) for (i=0; i<n; i++)
#define For1N(i,n) for (i=1; i<=n; i++)
#define ForAB(i,a,b) for (i=a; i<=b; i++)
#define ForNR(i,n) for (i=(n)-1; i>=0; i--)
#define For1NR(i,n) for (i=n; i>0; i--)
#define ForABR(i,a,b) for (i=b; i>=a; i--)
#define ForBE(i,s) for (i=s.begin(); i!=s.end(); i++)

#define Fill(s,v) memset(s,v,sizeof(s))
#define Debug(x) cout << #x" = " << x <<endl;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

bool myContain(string A, string B){
    int i=0, j=0;
    while(1){
        cout<<i<<" "<<j<<endl;
        if(i>A.length()){
            return true;
        }
        if(j>B.length()){
            return false;
        }
        if(A[i]==B[j]){
            i++;
            j++;
            continue;
        }
        if(i==0){
            j++;
            continue;
        }
        i=0;
    }
}

int main()
{
    int T; scanf("%d", &T);
    string str, ans, sub1, sub2;
    int len, index;
    char cap;
    for(int tt = 1; tt <= T; tt++){
        cin>>str;
        printf("Case #%d: ", tt);
        len=str.length();
        if(len<=2){
            ans="Impossible";
        }else{
            cap=str[0];
            index=-1;
            for(int i=1;i<len;++i){
                if(str[i]==cap){
                    index=i;
                    break;
                }
            }
            if(index==-1){
                ans="Impossible";
            }else if(index==1){
                ans=cap+str;
            }else if(index==len-1){
                ans="Impossible";
            }else{
                sub1=str.substr(index+1, len-index-1);
                // sub1=str.substr(1,index-1);
                sub2=str.substr(1, len-index-1);
                if(sub1==sub2){
                    ans="Impossible";
                }else{
                    ans=str.substr(0, index)+str;
                }
            }
        }
        cout<<ans<<endl;
        // if(ans!="Impossible")
            // printf("%d",myContain(str,ans)?1:0);

    }
    return 0;
}

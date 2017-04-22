#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define Fill(s,v) memset(s,v,sizeof(s))
#define Debug(x) cout << #x" = " << x <<endl;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

struct ROOM{
    long long int lindex,rindex,index;
    long long int ls,rs,minlrs,maxlrs;
    bool operator<(const ROOM& r) const {
        if(minlrs==r.minlrs){
            if(maxlrs==r.maxlrs){
                return index>r.index;
            }else{
                return maxlrs<r.maxlrs;
            }
        }else{
            return minlrs<r.minlrs;
        }
    }
}tmp;

void cal(){
    tmp.index=tmp.lindex+(tmp.rindex-tmp.lindex)/2;
    tmp.ls=tmp.index-tmp.lindex-1;
    tmp.rs=tmp.rindex-tmp.index-1;
    tmp.minlrs=min(tmp.ls, tmp.rs);
    tmp.maxlrs=max(tmp.ls, tmp.rs);
}

void print(struct ROOM rr)
{
    cout<<"index: "<<rr.lindex<<" "<<rr.index<<" "<<rr.rindex<<endl;
    cout<<"lsrs: "<<rr.ls<<" "<<rr.rs<<" "<<rr.minlrs<<" "<<rr.maxlrs<<endl;
 
}

int main()
{
    long long int n,k,l,m,r;
    int T; scanf("%d", &T);
    vector<struct ROOM> rlist;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%lld%lld",&n,&k);
        rlist.clear();
        tmp.lindex=0; tmp.rindex=n+1;
        cal();
        // print(tmp);
        rlist.push_back(tmp);
        sort(rlist.begin(), rlist.end());
        for(int i=0;i<k-1;++i){
            tmp = rlist[rlist.size()-1];
            l=tmp.lindex; m=tmp.index; r=tmp.rindex;
            tmp.rindex=m;
            cal();
            if(tmp.rindex-tmp.lindex<=1)
                rlist.erase(rlist.begin()+rlist.size()-1);
            else
                rlist[rlist.size()-1]=tmp;
            tmp.lindex=m;
            tmp.rindex=r;
            cal();
            if(tmp.rindex-tmp.lindex>1)
                rlist.push_back(tmp);   
            sort(rlist.begin(), rlist.end());
            // if(rlist.size()>k){
            //     int len=rlist.size();
            //     for(int j=0;j<len-k;++j){
            //         rlist.erase(rlist.begin()+j);
            //     }
            // }
            // for(int j=0;j<rlist.size();++j){
            //     cout<<"==="<<j<<"==="<<endl;
            //     print(rlist[j]);
            //     // cout<<"index: "<<rlist[j].lindex<<" "<<rlist[j].index<<" "<<rlist[j].rindex<<endl;
            //     // cout<<"lsrs: "<<rlist[j].ls<<" "<<rlist[j].rs<<" "<<rlist[j].minlrs<<" "<<rlist[j].maxlrs<<endl;
            // }
        }
        printf("%lld %lld\n",rlist[rlist.size()-1].maxlrs,rlist[rlist.size()-1].minlrs);
    }


}
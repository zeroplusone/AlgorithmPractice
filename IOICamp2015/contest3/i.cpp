#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
double findSuitableDensity(vector <int> v, vector <int> w) {
    int n=v.size();
    int i,j;double d,tg,ans,kq=1E18;
    for(i=0;i<n;++i) {
        d=double(w[i])/double(v[i]);
        tg=0;
        for(j=0;j<n;++j) tg+=fabs(d*v[j]-w[j]);
        if(tg<kq||(tg==kq&&d<ans)){
            kq=tg;
            ans=d;
        }
    }
    return ans;
}
int main() {
    int i,x,n;
    scanf("%d",&n);
    vector <int> v,w;
    for(i=0;i<n;++i) {
        scanf("%d",&x);
        v.push_back(x);
    }
    for(i=0;i<n;++i) {
        scanf("%d",&x);
        w.push_back(x);
    }
    printf("%.9f\n",findSuitableDensity(v, w));
    return 0;
}

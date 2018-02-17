#include <bits/stdc++.h>
using namespace std;

#define INF 1023456789
typedef pair<int,int> ii;
typedef long long ll;

#define sq(x) ((x)*(x))

bool f(string a,string b,string c){
    int n=a.length();
    int pos=0;
    while(a[pos]==b[pos] && a[pos]==c[pos]){
        pos++;
    }
    if(a[pos]==c[pos])return false;
    if(a[pos]!=b[pos] && a[pos]!=c[pos] && b[pos]!=c[pos]){
        return true;
    }
    char x=a[pos];
    char y=c[pos];
    // x > y
    if(a[pos]==b[pos]){
        int pos2=pos+1;
        while(a[pos2]==b[pos2]){
            pos2++;
        }
        if(a[pos2]==y && b[pos2]==x)return false;
        return true;
    }
    else if(c[pos]==b[pos]){
        int pos2=pos+1;
        while(c[pos2]==b[pos2]){
            pos2++;
        }
        if(b[pos2]==y && c[pos2]==x)return false;
        return true;
    }
    assert(false);
}

int main(){
    freopen("hi.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int n;
        scanf("%d",&n);
        string x,y,z;
        cin>>x>>y>>z;
        string a=(f(y,x,z)||f(z,x,y))?"YES":"NO";
        string b=(f(x,y,z)||f(z,y,x))?"YES":"NO";
        string c=(f(y,z,x)||f(x,z,y))?"YES":"NO";
        printf("Case #%d: ",t);
        cout << a <<" "<<b<<" "<<c<<'\n';
    }
}

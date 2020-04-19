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

string ans;

struct RECORD{
    string path;
    long long int x;
    long long int y;
}record, nr;

int main()
{
    int T; scanf("%d", &T);
    long long int X, Y;

    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%lld%lld",&X, &Y);
        
        queue<RECORD> que;
        ans="";
        record.path="";
        record.x=0;
        record.y=0;

        que.push(record);
        if(abs(X)!=abs(Y)){
        while(ans=="") {
            record = que.front();
            que.pop();
            //cout<<record.x<<" "<<record.y<<" "<<record.path<<endl;
            if(record.path.length()>7 || record.x>1000000000 || record.x<-1000000000 || record.y>1000000000 || record.y<-1000000000) {
                break;
            }

            long long int step=pow(2, record.path.length());

            if(record.x+step==X && record.y==Y) {
                ans=record.path+"E";
                break;
            } else {
                nr.path=record.path+"E";
                nr.x=record.x+step;
                nr.y=record.y;
                que.push(nr);
            }

            if(record.x-step==X && record.y==Y) {
                ans=record.path+"W";
                break;
            } else {
                nr.path=record.path+"W";
                nr.x=record.x-step;
                nr.y=record.y;
                que.push(nr);
            }

            if(record.x==X && record.y+step==Y) {
                ans=record.path+"N";
                break;
            } else {
                nr.path=record.path+"N";
                nr.x=record.x;
                nr.y=record.y+step;
                que.push(nr);
            }

            if(record.x==X && record.y-step==Y) {
                ans=record.path+"S";
                break;
            } else {
                nr.path=record.path+"S";
                nr.x=record.x;
                nr.y=record.y-step;
                que.push(nr);
            }


        }
        }
        if(ans=="") {
            cout<<"IMPOSSIBLE"<<endl;
        } else {
            cout<<ans<<endl;
        }
    }

    return 0;
}
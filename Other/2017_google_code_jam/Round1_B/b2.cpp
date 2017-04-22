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

#define MAXN 1100
char seat[MAXN];
bool done;
int num[6];
vector<vector<int> > near;
char trans[6]={'R','Y','B','O','G','V'};
int N;
#define R 0
#define Y 1
#define B 2
#define O 3
#define G 4
#define V 5

struct coloring{
    int type;
    int num;
    bool operator<(const struct coloring &c)const{
        return c.num==num?c.type>type:c.num<num;
    }
}color[6];

int main()
{
    int T; scanf("%d", &T);
    double addtime=0;
    vector<int> v;
    near.clear();
    bool no;
    //R
    v.clear();
    v.push_back(Y); v.push_back(B); v.push_back(G);
    near.push_back(v);
    //Y
    v.clear();
    v.push_back(R); v.push_back(B); v.push_back(V);
    near.push_back(v);
    //B
    v.clear();
    v.push_back(R); v.push_back(Y); v.push_back(O);
    near.push_back(v);
    //O
    v.clear();
    v.push_back(B); 
    near.push_back(v);
    //G
    v.clear();
    v.push_back(R); 
    near.push_back(v);
    //V
    v.clear();
    v.push_back(Y); 
    near.push_back(v);

    for(int i=0;i<6;++i)
        color[i].type=i;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        Fill(num,0);
        scanf("%d%d%d%d%d%d%d",&N,&color[R].num,&color[O].num,&color[Y].num,&color[G].num,&color[B].num,&color[V].num);
        sort(color,color+6);
        no=false;
        for(int i=0;i<N;++i){
            cout<<color[0].type<<color[0].num<<endl;
            cout<<color[1].type<<color[1].num<<endl;
            cout<<color[2].type<<color[2].num<<endl<<endl;
            if(i==0 || seat[i-1]!=color[0].type){
                seat[i]=color[0].type;
                color[0].num--;
            }else if(color[1].num!=0){
                seat[i]=color[1].type;
                color[1].num--;
            }else{

                no=true;
                break;
            }
            cout<<trans[seat[i]]<<endl;
            sort(color,color+6);
        }
        if(no || seat[N-1]==seat[0] || color[0].num<0|| color[1].num<0|| color[2].num<0|| color[3].num<0|| color[4].num<0|| color[5].num<0){
            printf("IMPOSSIBLE\n");
        }else{
            for(int i=0;i<N;++i){
                printf("%c",trans[seat[i]]);
            }
            printf("\n");
        }
        
    }


}
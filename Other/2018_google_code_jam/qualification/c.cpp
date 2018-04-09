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

#define MAXN 1001

bool yard[MAXN][MAXN];

int dir[2][9]={{-1,-1,-1,0,0,0,1,1,1},{-1,0,1,-1,0,1,-1,0,1}};

bool isFull(int x, int y){
    for(int i=0;i<9;++i){
        if(!yard[x+dir[0][i]][y+dir[1][i]])
            return false;
    }
    return true;
}

int main()
{
    int t, a;
    int ix, iy;
    int index;
    int i;
    scanf("%d",&t);
    while(t--){
        memset(yard, false, sizeof(yard));
        scanf("%d",&a);
        if(a<=20){
            for(i=0;i<3;++i){
                index=3+3*i;
                do{
                    printf("3 %d\n",index);
                    fflush(stdout);
                    scanf("%d%d", &ix, &iy);
                    if(ix==0 && iy==0)
                        break;
                    yard[ix][iy]=true;
                }while(!isFull(3, index));
                if(ix==0 && iy==0)
                    break;
            }
        }else{
            for(i=0;i<25;++i){
                index=3+3*i;
                do{
                    printf("3 %d\n",index);
                    fflush(stdout);
                    scanf("%d%d", &ix, &iy);
                    if(ix==0 && iy==0)
                        break;
                    yard[ix][iy]=true;
                }while(!isFull(3, index));
                if(ix==0 && iy==0)
                    break;
            }
        }
    }    
    return 0;
}

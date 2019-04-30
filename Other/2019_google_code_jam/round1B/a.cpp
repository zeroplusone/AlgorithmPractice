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

#define MAXN 100100
int sumx[MAXN], sumy[MAXN];
int Q;

int lowbit(int in){
    return in&(-in);
}

void modify(int st, bool isX){
    if(isX){
        for(int i=st;i<=Q+1;i+=lowbit(i)){
            sumx[i]+=1;
        }
    }else{
        for (int i = st; i <= Q+1; i += lowbit(i))
        {
            sumy[i] += 1;
        }
    }
}

int main()
{
    int T; scanf("%d", &T);
    int P;
    int x, y;
    int val, ind;
    char dir;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        memset(sumx, 0, sizeof(sumx));
        memset(sumy, 0, sizeof(sumy));
        scanf("%d %d", &P, &Q);
        for(int i=0;i<P;++i){
            scanf("%d %d %c",&x, &y, &dir);
            switch (dir)
            {
            case 'W':
                for (int j = 1; j <= x; ++j)
                    modify(j, true);
                break;
            case 'E':
                for (int j = x + 2; j <= Q + 1; ++j)
                    modify(j, true);
                break;
            case 'S':
                for (int j = 1; j <= y; ++j)
                    modify(j, false);
                break;
            case 'N':
                for (int j = y + 2; j <= Q + 1; ++j)
                    modify(j, false);
                break;
            }
        }
        int ansx=0, ansy=0;
        int maxval=0;
        int last=0;
        for (int i = 1; i <= Q + 1; ++i)
        {
            val = sumx[i];
            ind = i-lowbit(i);
            while (ind != 0)
            {
                val += sumx[ind];
                ind -= lowbit(ind);
            }
            if (val-last > maxval)
            {
                ansx = i - 1;
                maxval = val-last;
            }
            last=val;
        }
        maxval=0;
        last=0;
        for(int i = 1; i <= Q + 1; ++i)
        {
            val = sumy[i];
            ind = i - lowbit(i);
            while (ind != 0)
            {
                val += sumy[ind];
                ind -= lowbit(ind);
            }
            if (val - last > maxval)
            {
                ansy = i - 1;
                maxval = val - last;
            }
            last = val;
        }

        printf("%d %d\n", ansx, ansy);
    }

    return 0;
}

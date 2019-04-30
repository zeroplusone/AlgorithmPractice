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

#define ForN(i, n) for (i = 0; i < n; i++)
#define For1N(i, n) for (i = 1; i <= n; i++)
#define ForAB(i, a, b) for (i = a; i <= b; i++)
#define ForNR(i, n) for (i = (n)-1; i >= 0; i--)
#define For1NR(i, n) for (i = n; i > 0; i--)
#define ForABR(i, a, b) for (i = b; i >= a; i--)
#define ForBE(i, s) for (i = s.begin(); i != s.end(); i++)

#define Fill(s, v) memset(s, v, sizeof(s))
#define Debug(x) cout << #x " = " << x << endl;

#define LL long long
#define LD long double
#define PR pair<int, int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

#define MAXN 255
int m[MAXN][MAXN];
int dir[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
}; 
int r,c, ans;

void print(){
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cout << m[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
}

void BFS(int firstx, int firsty)
{
    queue<pair<int, int > > que;
    que.push(mp(firstx, firsty));
    int nowx, nowy;
    pair<int,int> now;
    while(!que.empty()){
        now=que.front();
        que.pop();
        for(int i=0;i<4;++i){
            nowx=now.first+dir[i][0];
            nowy=now.second+dir[i][1];
            if(nowx>=0 && nowx<r && nowy>=0 && nowy<c){
                if (m[nowx][nowy] !=1 && (m[nowx][nowy] == 0 || m[nowx][nowy] > m[now.first][now.second]+1)){
                    m[nowx][nowy]=m[now.x][now.y]+1;
                    que.push(mp(nowx, nowy));
                    // print();
                }
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    string input;
    for (int tt = 1; tt <= T; tt++)
    {
        ans=0;
        memset(m, 0, sizeof(m));
        scanf("%d%d", &r, &c);
        for (int i = 0; i < r; ++i)
        {
            cin>>input;
            for(int j=0; j<c;++j){
                m[i][j]=input[j]-'0';
            }
        }

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if(m[i][j]==1){
                    BFS(i, j);
                }
            }
        }
        pair<int,int> maxp(0,0);
        int maxn=0;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(m[i][j]>maxn){
                    maxn=m[i][j];
                    maxp=mp(i,j);
                }
            }
        }
        m[maxp.x][maxp.y]=1;
        print();
        BFS(maxp.x, maxp.y);
        maxn=0;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (m[i][j] > maxn)
                {
                    maxn = m[i][j];
                }
            }
        }
        cout<<"===="<<endl;
        print();
        printf("%d\n", maxn-1);
    }
}
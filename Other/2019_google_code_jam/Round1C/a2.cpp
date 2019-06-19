#include<bits/stdc++.h>
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

#define MAXN 260
bool v[MAXN];
LL minCommon(int a, int b){
    LL ret = (LL)a *(LL) b;
    int tmp;
    if(b>a)
        swap(a, b);
    while(b!=0){
        tmp=a;
        a=b;
        b=tmp%b;
    }
    return ret / (LL) a;
}

int main()
{
    int T; scanf("%d", &T);
    int A, last;  string s[MAXN];
    LL maxIndex;
    string ans;
    bitset<3> result;
    memset(v,false,sizeof(v));
    int index;
    map<char, int> mapping;
    mapping['S']=2;
    mapping['R']=1;
    mapping['P']=0;
    int win;
    char now;
    bool isEnd;
    for(int tt = 1; tt <= T; tt++){
        printf("Case #%d: ", tt);
        scanf("%d", &A);
        ans=""; last=1;
        win=0;
        for(int i=0;i<A;++i){
            cin>>s[i];
            last=minCommon(s[i].length(), last);
        }
        index=0;
        while(index<500){
            result.reset();
            isEnd=true;
            for (int i = 0; i < A; ++i)
            {
                if(!v[i]){
                    result.set(mapping[s[i][index%s[i].length()]]);
                    isEnd=false;
                }
            }
            if(isEnd)   break;
            switch(result.to_ulong()){
                case 1: // paper
                    ans+="S";
                    win=1;
                    break;
                case 2: // rock
                    ans += "P";
                    win = 1;
                    break;
                case 3: // p r
                    ans+="P";
                    for (int i = 0; i < A; ++i)
                    {
                        if (!v[i] && s[i][index%s[i].length()]=='R')
                        {
                            v[i]=true;
                        }
                    }
                    break;
                case 4: // scissor
                    ans += "R";
                    win = 1;
                    break;
                case 5: // s p
                    ans += "S";
                    for (int i = 0; i < A; ++i)
                    {
                        if (!v[i] && s[i][index % s[i].length()] == 'P')
                        {
                            v[i] = true;
                        }
                    }
                    break;
                case 6:// s r
                    ans += "R";
                    for (int i = 0; i < A; ++i)
                    {
                        if (!v[i] && s[i][index % s[i].length()] == 'S')
                        {
                            v[i] = true;
                        }
                    }
                    break;
                case 7:
                    win=-1;
                    break;
            }
            
            if(win!=0)
                break;
            index++;
        }
        if(win>0){
            cout<<ans<<endl;
        }else{
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}
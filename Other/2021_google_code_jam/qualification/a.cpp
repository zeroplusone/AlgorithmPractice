#include <bits/stdc++.h>
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

int main()
{
    int T;
    scanf("%d", &T);
    int N, ans;
    for (int tt = 1; tt <= T; tt++)
    {
        ans = 0;
        scanf("%d", &N);
        vector<int> arr(N);
        for (int i = 0; i < N; ++i)
        {
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < N-1; ++i)
        {
            int minVal = arr[i];
            int ind = i;
            for (int j = i + 1; j < N; ++j)
            {
                if (arr[j] < arr[ind])
                {
                    minVal = arr[j];
                    ind = j;
                }
            }
            for(int k=0;k<(ind-i+1)/2;++k) {
                swap(arr[i+k], arr[ind-k]);
            }
            ans += ind - i + 1;
        }

        printf("Case #%d: ", tt);
        printf("%d\n", ans);
    }
}

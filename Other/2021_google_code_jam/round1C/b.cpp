// WA

#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define PR pair<int,int>

#define pb push_back
#define mp make_pair
#define x first
#define y second

int main() {
    int T;
    scanf("%d", &T);
    LL Y;
    for (int tt = 1; tt <= T; tt++) {
        printf("Case #%d: ", tt);
        cin >> Y;
        LL tmp = Y + 1;
        if (tmp <= 9) {
            cout << tmp << endl;
        } else {
            vector<LL> digit;
            while (tmp != 0) {
                digit.push_back(tmp % 10);
                tmp /= 10;
            }
            int len = digit.size();

            reverse(digit.begin(), digit.end());
            LL ans = static_cast<long long int>(1e20);
            LL now, sum;
            for (int i = 1; i < len; i++) {
                vector<LL> sec;
                for (int j = 0; i * j < len; ++j) {
                    now = 0;
                    for (int k = 0; k < i; ++k) {
                        if (i * j + k < len) {
                            now = now * 10 + digit[i * j + k];
                        }
                    }
                    sec.push_back(now);
//                cout<<now<<" ";
                }
//            cout<<endl;
                for (int j = 0; j < sec.size() - 1; ++j) {
                    if (sec[j + 1] <= sec[j] + 1) {
                        sec[j + 1] = sec[j] + 1;
                    } else {
                        for (int k = 0; k <= j; ++k) {
                            sec[k]++;
                        }
                        sec[j + 1] = sec[j] + 1;
                    }
                }
                sum = 0;
                for (int j = 0; j < sec.size(); ++j) {
                    tmp = sec[j];
                    int base = 0;
                    while (tmp != 0) {
                        base++;
                        tmp /= 10;
                    }
                    sum = sum * pow(10, base) + sec[j];
                    if (sum > Y) {
                        break;
                    }
                }
//            cout<<sum<<endl;
                ans = min(ans, sum);
            }
            cout << ans << endl;
        }

    }
    return 0;
}


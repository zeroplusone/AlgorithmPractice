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
    int N, M;
    for (int tt = 1; tt <= T; tt++) {
        cin >> N >> M;

        vector<LL> ans(M);
        auto cmp = [](pair<LL, LL> p1, pair<LL, LL> p2) {
            return p1.x==p2.x?p1.y>p2.y:p1.x<p2.x;
        };
        set<pair<LL, LL>, decltype(cmp)> v(cmp);
        LL L, R;
        for (int i = 0; i < N; ++i) {
            cin >> L >> R;
            v.insert(mp(L, R));
        }

        vector<LL> s(M);
        for (int i = 0; i < M; ++i) {
            cin >> s[i];
        }

        for (int i = 0; i < M; ++i) {
            auto it=v.lower_bound(mp(s[i], s[i]));
            if(it==v.end()) {
                it--;
                if(s[i]<=(*it).y) {
                    ans[i] = s[i];
                    if(s[i]-1>=(*it).x) {
                        v.insert(mp((*it).x, s[i]-1));
                    }
                    if(s[i]+1<=(*it).y) {
                        v.insert(mp(s[i]+1, (*it).y));
                    }
                    v.erase(it);
                } else {
                    ans[i] = (*it).y;
                    if ((*it).y - 1 >= (*it).x) {
                        v.insert(mp((*it).x, (*it).y - 1));
                    }
                    v.erase(it);
                }
            } else if(it==v.begin()) {
                ans[i] = (*it).x;
                if ((*it).x + 1 <= (*it).y) {
                    v.insert(mp((*it).x + 1, (*it).y));
                }
                v.erase(it);
            } else {
                auto right=it;
                it--;
                auto left=it;
                if(s[i]<=(*left).y) {
                    ans[i] = s[i];
                    if(s[i]-1>=(*left).x) {
                        v.insert(mp((*left).x, s[i]-1));
                    }
                    if(s[i]+1<=(*left).y) {
                        v.insert(mp(s[i]+1, (*left).y));
                    }
                    v.erase(left);
                } else {
                    if(abs(s[i]-(*left).y)<=abs(s[i]-(*right).x)) {
                        ans[i] = (*left).y;
                        if ((*left).y - 1 >= (*left).x) {
                            v.insert(mp((*left).x, (*left).y - 1));
                        }
                        v.erase(left);
                    } else {
                        ans[i] = (*right).x;
                        if ((*right).x + 1 <= (*right).y) {
                            v.insert(mp((*right).x + 1, (*right).y));
                        }
                        v.erase(right);
                    }
                }
            }
        }

        printf("Case #%d: ", tt);
        for (int i = 0; i < M; ++i) {
            cout << ans[i];
            if (i == M - 1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }

    return 0;
}

//====Large MLE====

//int main() {
//    int T;
//    scanf("%d", &T);
//    int N, M;
//    for (int tt = 1; tt <= T; tt++) {
//        cin >> N >> M;
//
//        vector<LL> ans(M);
//        set<LL> v;
//        LL L, R;
//        for (int i = 0; i < N; ++i) {
//            cin >> L >> R;
//            for (LL j = L ; j <=R; ++j) {
//                v.insert(j);
//            }
//        }
//
//        vector<LL> s(M);
//        for (int i = 0; i < M; ++i) {
//            cin >> s[i];
//        }
//
//        for (int i = 0; i < M; ++i) {
//            if(v.count(s[i])!=0) {
//                ans[i]=s[i];
//                v.erase(v.find(s[i]));
//            } else {
//                auto it=v.upper_bound(s[i]);
//                if(it==v.end()) {
//                    it--;
//                    ans[i]=*it;
//                    v.erase(it);
//                } else if(it==v.begin()) {
//                    ans[i]=*it;
//                    v.erase(it);
//                } else {
//                    auto right=it;
//                    it--;
//                    auto left=it;
//                    if(abs(s[i]-*left)<=abs(s[i]-*right)) {
//                        ans[i]=*left;
//                        v.erase(left);
//                    } else {
//                        ans[i]=*right;
//                        v.erase(right);
//                    }
//                }
//            }
//        }
//
//        printf("Case #%d: ", tt);
//        for (int i = 0; i < M; ++i) {
//            cout << ans[i];
//            if (i == M - 1) {
//                cout << endl;
//            } else {
//                cout << " ";
//            }
//        }
//    }
//
//    return 0;
//}

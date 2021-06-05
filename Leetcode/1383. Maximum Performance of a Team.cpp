class Solution {
public:
    struct eng{
        int s;
        int e;
        eng(int s, int e): s(s), e(e){};
    };
    
    static bool comparator(eng e1, eng e2) {
        return e1.e>e2.e;
    }

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<eng> engs;
        for(int i=0;i<n;++i) {
            engs.push_back(eng(speed[i], efficiency[i]));
        }        
        sort(engs.begin(), engs.end(), comparator);
        
        auto cmp = [](eng e1, eng e2) {
            return e1.s>e2.s;
        };
        priority_queue<eng, vector<eng>, decltype(cmp)> pq(cmp);

        long long int s_sum=0;

        long long int ans=0;
        for(int i=0;i<k;++i) {
            s_sum+=engs[i].s;
            pq.push(engs[i]);
            ans=max(ans, s_sum*engs[i].e);
        }
        
        for(int i=k;i<n;++i) {
            s_sum=s_sum+engs[i].s-pq.top().s;
            pq.pop();
            pq.push(engs[i]);
            ans=max(ans, s_sum*engs[i].e);
        }

        long long int mod=1e9+7;
        return ans%mod;
    }
};

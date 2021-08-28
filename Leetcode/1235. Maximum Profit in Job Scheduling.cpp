class Solution {
public:
    struct job{
        int st, en, profit;
        job(int st, int en, int profit):st(st), en(en), profit(profit){};
    };

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<job> jobs;
        for(int i=0;i<n;++i) {
            jobs.push_back(job(startTime[i], endTime[i], profit[i]));
        }
        jobs.push_back(job(1e9+1, 1e9+2, 0));
        sort(jobs.begin(), jobs.end(), [](job j1, job j2) {return j1.st==j2.st?j1.en>j2.en:j1.st<j2.st;});
        
        vector<int> dp(n+1, 0);
        dp[n]=jobs[n].profit;
        for(int i=n-1;i>=0;--i) {
            int l=i+1, r=n;
            while(l<r) {
                int mid=l+((r-l)>>1);
                if(jobs[mid].st>=jobs[i].en) {
                    r=mid;
                } else {
                    l=mid+1;
                }
            }
            dp[i]=max(jobs[i].profit+dp[r], dp[i+1]);
        }
        return dp[0];
    }
};

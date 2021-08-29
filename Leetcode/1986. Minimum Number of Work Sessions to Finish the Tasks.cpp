class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        sort(tasks.begin(), tasks.end());
        vector<int> bags(0);
        unordered_map<string, int> dp;
        return solve(0, tasks, bags, sessionTime, dp);
    }
    
    int solve(int now, vector<int>& tasks, vector<int>& bags, int& cap, unordered_map<string, int>& dp) {
        if(now==tasks.size()) {
            return bags.size();
        }
        
        string key=encode(now, bags);
        if(dp.count(key)!=0) {
            return dp[key];
        }
        
        bags.push_back(cap-tasks[now]);
        int ret=solve(now+1, tasks, bags, cap, dp);
        bags.pop_back();

        for(int i=0;i<bags.size();++i) {
            if(bags[i]>=tasks[now]) {
                bags[i]-=tasks[now];
                ret=min(ret, solve(now+1, tasks, bags, cap, dp));
                bags[i]+=tasks[now];
            }
        }
        dp[key]=ret;
        return ret;
    }
    
    
    string encode(int now, vector<int> bags) {
        string ret=to_string(now)+"#";
        sort(bags.begin(), bags.end());
        for(int i=0;i<bags.size();++i) {
            ret+=to_string(bags[i])+"#";
        }
        return ret;
    }

};

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target=="0000") {
            return 0;
        }
        unordered_set<string> inque;
        unordered_set<string> deadendset(deadends.begin(), deadends.end());

        queue<string> que;
        que.push("0000");
        inque.insert("0000");
        
        int ans=0;
        while(!que.empty()) {
            ans++;
            int n=que.size();
            for(int j=0;j<n;++j) {
                string now=que.front(); que.pop();
                vector<string> adj=get_adj(now, deadendset);
                for(int i=0;i<adj.size();++i) {
                    if(adj[i]==target) {
                        return ans;
                    }
                    if(inque.count(adj[i])==0) {
                        que.push(adj[i]);
                        inque.insert(adj[i]);
                    }
                }
            }
            
        }

        return -1;
    }
    
    vector<string> get_adj(string now, unordered_set<string>& deadendset) {
        vector<string> ret(0);
        if(deadendset.count(now)==0) {
            for(int i=0;i<4;++i) {
                string adj=now;
                adj[i]='0'+((adj[i]-'0'+1)%10);
                if(deadendset.count(adj)==0) {
                    ret.push_back(adj);
                }
            }

            for(int i=0;i<4;++i) {
                string adj=now;
                adj[i]='0'+((adj[i]-'0'-1+10)%10);
                if(deadendset.count(adj)==0) {
                    ret.push_back(adj);
                }
            }
        }
        return ret;
    }

};

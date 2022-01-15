class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        unordered_map<int, vector<int>> m;
        for(int i=0;i<arr.size();++i) {
            m[arr[i]].push_back(i);
        }
        
        int step=0;
        vector<int> cur{0};
        unordered_set<int> v;
        while(!cur.empty()) {
            vector<int> next;

            for(int i=0;i<cur.size();++i) {
                int now=cur[i];
                if(now==arr.size()-1) {
                    return step;
                }
                
                vector<int> samev=m[arr[now]];
                for(int j=0;j<samev.size();++j) {
                    if(v.count(samev[j])==0) {
                        next.push_back(samev[j]);
                        v.insert(samev[j]);
                    }
                }
                
                m[arr[now]].clear();
                
                if(now-1>=0 && v.count(now-1)==0) {
                    next.push_back(now-1);
                    v.insert(now-1);
                }
                if(now+1<arr.size() && v.count(now+1)==0) {
                    next.push_back(now+1);
                    v.insert(now+1);
                }
            }
            cur=next;
            step++;
        }
        return step;
    }
};

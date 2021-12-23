class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<pair<int, int>> degree(numCourses);
        for(int i=0;i<numCourses;++i) {
            degree[i]=make_pair(0, i);
        }
        vector<bool> v(numCourses, false);
        
        unordered_map<int, vector<int>> m;
        for(int i=0;i<prerequisites.size();++i) {    
            m[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i=0;i<numCourses;++i) {
            if(!v[i]) {
                if(!DFS(0, i, m, v, degree, numCourses)) {
                    return vector<int>(0);
                }
            }
        }
        sort(degree.begin(), degree.end());
        vector<int> ans(numCourses);
        for(int i=0;i<degree.size();++i) {
            ans[i]=degree[i].second;
        }
        return ans;
    }
    
    bool DFS(int d, int now, unordered_map<int, vector<int>>& m, vector<bool>& v, vector<pair<int, int>>& degree, int& c) {
        
        if(d>c) {
            return false;
        }
        v[now]=true;
        degree[now].first=max(degree[now].first, d);

        bool ret=true;
        for(int i=0;i<m[now].size()&&ret;++i) {
            ret&=DFS(d+1, m[now][i], m, v, degree, c);    
        }
        return ret;
    }
};

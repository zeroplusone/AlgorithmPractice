class Solution {
public:

    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        unordered_map<int, int> st, en;
        for(int i=0;i<updates.size();++i) {
            st[updates[i][0]]+=updates[i][2];
            en[updates[i][1]]+=updates[i][2];
        }
        int cnt=0;
        vector<int> ans(length, 0);
        for(int i=0;i<length;++i) {
            cnt+=st[i];
            ans[i]=cnt;
            cnt-=en[i];   
        }
        return ans;
    }
};

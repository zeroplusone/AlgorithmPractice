class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans=0;
        unordered_set<char> s;
        backtracking(0, s, arr, ans);
        return ans;
    }
    
    void backtracking(int now, unordered_set<char> s, vector<string>& arr, int& ans) {
        int sz=s.size();
        ans=max(ans, sz);
    
        if(now==arr.size()) {
            return;
        }
        
        
        unordered_set<char> news(s);
        int i=0;
        for(;i<arr[now].length();++i) {
            if(news.count(arr[now][i])!=0) {
                break;
            } else {
                news.insert(arr[now][i]);
            }
        }
        backtracking(now+1, s, arr, ans);
        if(i==arr[now].length()) {
            backtracking(now+1, news, arr, ans);    
        }
    }
};

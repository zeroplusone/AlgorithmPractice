class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> v(n, false);
        
        return DFS(start, arr, v);
    }
    
    bool DFS(int now, vector<int>& arr, vector<bool>& v) {
        if(now<0 || now>=arr.size()) {
            return false;
        } else if(arr[now]==0) {
            return true;
        } else if(v[now]) {
            return false;
        }
        
        v[now]=true;
        return DFS(now+arr[now], arr, v) || DFS(now-arr[now], arr, v);
        
    }
};

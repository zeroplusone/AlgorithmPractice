class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n=arr.size();
        map<int, int> cnt;
        
        for(int i=0;i<n;++i) {
            if(arr[i]!=0) {
                cnt[arr[i]]++;    
            }
        } 
        
        for(auto& it:cnt) {
            if(it.second==0) {
                continue;
            }
            if(it.first<0 && (it.first*(-1))%2==1) {
                return false;
            }
            
            int match=it.first<0?it.first/2:it.first*2;
            while(it.second!=0) {
                if(cnt[match]!=0) {
                    it.second--;
                    cnt[match]--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

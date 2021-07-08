class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int l=0, r=min(nums1.size(), nums2.size());
        string s1="", s2="";
        for(int i=0;i<nums1.size();++i) {
            s1+=toStr(nums1[i]);
        }
        for(int i=0;i<nums2.size();++i) {
            s2+=toStr(nums2[i]);
        }
        while(l<r) {
            int mid=(l+r+1)>>1;
            if(canbe(s1, s2, mid)) {
                l=mid;
            } else {
                r=mid-1;
            }
        }
        return r;
    }
    
    bool canbe(string& s1, string& s2, int len) {
        unordered_set<string> set1;
        
        for(int i=0;i<=s1.length()/3-len;++i) {
            set1.insert(s1.substr(i*3, len*3));
        }
        for(int i=0;i<=s2.length()/3-len;++i) {
            if(set1.count(s2.substr(i*3, len*3))) {
                return true;
            }
        }
        
        return false;
    }
    
    string toStr(int num) {
        return to_string(1000+num).substr(1,3);
    }
};

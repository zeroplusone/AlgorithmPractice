class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int n=sweetness.size();
        int l=1e9, r=0;
        for(int i=0;i<n;++i) {
            l=min(l, sweetness[i]);
            sweetness[i]=i==0?sweetness[i]:sweetness[i-1]+sweetness[i];
        }
        r=sweetness[n-1];
        
        while(l<r) {
            int mid=(l+r+1)>>1;
            if(canbe(mid, sweetness, k)) {
                l=mid;
            } else {
                r=mid-1;
            }
        }
        return r;
    }
    
    bool canbe(int mid, vector<int>& s, int k) {
        int cut=0, last=0;
        for(int i=0;i<s.size()&&cut<=k;++i) {
            if(s[i]-last>=mid) {
                cut++;
                last=s[i];
            }
        }
        return cut>k;
    }
};

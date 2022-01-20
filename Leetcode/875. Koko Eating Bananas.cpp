class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(), piles.end());

        while(l<r) {
            int mid=(l+r)>>1;
            if(canbe(piles, mid, h)) {
                r=mid;
            } else {
                l=mid+1;
            }
        }
        return r;
    }
    
    bool canbe(vector<int>& piles, int& k, int& h) {
        int cnt=0;
        for(int i=piles.size()-1;i>=0;--i) {
            cnt+=(piles[i]+k-1)/k;
            if(cnt>h) {
                return false;
            }
        }
        return cnt<=h;
    }
};

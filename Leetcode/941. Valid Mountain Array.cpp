class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) {
            return false;
        }
        
        int diff=0;
        for(int i=1;i<arr.size();++i) {
            int now=arr[i]-arr[i-1];
            if(now==0) {
                return false;
            } else if(now<0 && diff>0) {
                diff=now;
            }else if((now>0&&diff>=0) || (now<0&&diff<0)) {
                diff=now;
            } else {
                return false;
            }
        }
        return diff<0;
    }
};

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n=arr.size();
        int one=0;
        string str="";
        for(int i=0;i<n;++i) {
            if(arr[i]==1) {
                one++;
            }
            str+=to_string(arr[i]);
        }
        
        if(one==0) {
            return vector<int>{0, 2};
        }
        if(one%3!=0) {
            return vector<int>{-1, -1};
        }
        one/=3;

        vector<int> ans(2,0);
        vector<string> nums(3);
        int j;
        for(j=n-1;one!=0;--j){
            if(arr[j]==1) {
                one--;
            }
        }
        nums[2]=str.substr(j+1, n-(j+1));
        
        int i=0;
        while(arr[i]==0) {
            i++;
        }
        ans[0]=i+nums[2].length()-1;
        nums[0]=str.substr(i, nums[2].length());
    
        i=ans[0]+1;
        while(arr[i]==0) {
            i++;
        }
        ans[1]=i+nums[2].length();
        nums[1]=str.substr(i, nums[2].length());


        if(ans[1]<=j+1 && nums[0]==nums[1] && nums[1]==nums[2]) {
            return ans;
        } else {
            return vector<int>{-1, -1};
        }
    }
};

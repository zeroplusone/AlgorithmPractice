class Solution {
public:
    vector<int> original, arr;

    Solution(vector<int>& nums) {
        arr=nums;     
        original = vector<int>(nums);
        srand (time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        arr=original;
        original=vector<int>(original);
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int offset, tmp, mod=arr.size();
        for(int i=0;i<arr.size()-1;++i, mod--) {
            offset=rand()%mod;
            tmp=arr[i+offset];
            arr[i+offset]=arr[i];
            arr[i]=tmp;
        }
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

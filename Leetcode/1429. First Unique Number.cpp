class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for(int i=0;i<nums.size();++i) {
            add(nums[i]);
        }
    }
    
    int showFirstUnique() {
        while(!que.empty()) {
            if(m[que.front()]>1) {
                que.pop();
            } else {
                break;
            }
        }
        return que.empty()?-1:que.front();
    }
    
    void add(int value) {
        if(m.count(value)==0) {
            que.push(value);
        }
        m[value]++;
    }
    
    queue<int> que;
    unordered_map<int, int> m;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */

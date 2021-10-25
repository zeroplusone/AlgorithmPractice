class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        sta.push_back(val);
        if(dp.size()==0) {
            dp.push_back(val);
        } else {
            dp.push_back(min(dp[dp.size()-1], val));
        }
    }
    
    void pop() {
        sta.pop_back();
        dp.pop_back();
    }
    
    int top() {
        return sta[sta.size()-1];
    }
    
    int getMin() {
        return dp[dp.size()-1];
    }
    
    vector<int> dp;
    vector<int> sta;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

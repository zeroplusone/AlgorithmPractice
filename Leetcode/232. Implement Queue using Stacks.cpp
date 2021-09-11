class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        sta1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ret=peek();
        sta2.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if(sta2.empty()) {
            while(!sta1.empty()) {
                sta2.push(sta1.top());
                sta1.pop();
            }    
        }
        return sta2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return sta1.empty() && sta2.empty();
    }
    
    stack<int> sta1, sta2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

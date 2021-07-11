class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty()) {
            left.push(num);
        } else if(right.empty()) {
            if(left.top()>num) {
                right.push(left.top());
                left.pop();
                left.push(num);
            } else {
                right.push(num);    
            }
        } else {
            if(left.size()==right.size()) {
                if(num<=right.top()) {
                    left.push(num);
                } else {
                    left.push(right.top());
                    right.pop();
                    right.push(num);
                }
            } else {
                if(num>=left.top()) {
                    right.push(num);
                } else {
                    right.push(left.top());
                    left.pop();
                    left.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()) {
            return (left.top()+right.top())/2.0;
        } else {
            return left.top();
        }
    }
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

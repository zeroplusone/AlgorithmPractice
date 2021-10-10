class StockPrice {
public:
    StockPrice() {
        latest=make_pair(0, -1);
    }
    
    void update(int timestamp, int price) {
        r[timestamp]=price;
        pair<int, int> p=make_pair(price, timestamp);
        if(timestamp>=latest.second) {
            latest=p;
        }
        maxq.push(p);
        minq.push(p);
    }
    
    int current() {
        return latest.first;
    }
    
    int maximum() {
        while(r[maxq.top().second]!=maxq.top().first) {
            maxq.pop();
        }
        return maxq.top().first;
    }
    
    int minimum() {
        while(r[minq.top().second]!=minq.top().first) {
            minq.pop();
        }
        return minq.top().first;
    }
    // price, time
    priority_queue<pair<int, int>> maxq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minq;
    unordered_map<int, int> r;
    pair<int, int> latest;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

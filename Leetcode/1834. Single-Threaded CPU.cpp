class Solution {
public:
        
    struct T {
        int enqueueTime;
        int processingTime;
        int index;
        T(int e, int p, int i):enqueueTime(e), processingTime(p), index(i){};
    };

    static bool myCmp(T t1, T t2) {
        if(t1.enqueueTime!=t2.enqueueTime) {
            return t1.enqueueTime<t2.enqueueTime;
        } else if(t1.processingTime!=t2.processingTime) {
            return t1.processingTime<t2.processingTime;
        } else {
            return t1.index<t2.index;
        }
    }
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<T> ttasks;
        for(int i=0;i<tasks.size();++i) {
            ttasks.push_back(T(tasks[i][0], tasks[i][1], i)); 
        }
        
        sort(ttasks.begin(), ttasks.end(), myCmp);
        auto cmp = [](T t1, T t2) {
            if(t1.processingTime!=t2.processingTime) {
                return t1.processingTime>t2.processingTime;
            } else {
                return t1.index>t2.index;
            }
        };
        priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);
        
        vector<int> ans;
        
        long long now=0;
        for(int i=0;i<ttasks.size();) {
            if(pq.empty() && ttasks[i].enqueueTime>now) {
                now=ttasks[i].enqueueTime;
            }
            while(i<ttasks.size() && ttasks[i].enqueueTime<=now) {
                T newTask = T(ttasks[i].enqueueTime, ttasks[i].processingTime, ttasks[i].index);    
                pq.push(newTask);
                i++;
            } 
            T t=pq.top();   pq.pop();
            now=now+t.processingTime;
            ans.push_back(t.index);
        }
        while(!pq.empty()) {
            T t=pq.top();   pq.pop();
            ans.push_back(t.index);
        }

        return ans;
    }

};

class Solution {
public:
    struct server{
        int index;
        int weight;
        int freeTime;
        server(int index, int weight):index(index), weight(weight), freeTime(0) {};
    };
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int> ans(tasks.size());
        auto freeCmp = [](server s1, server s2) {return s1.weight==s2.weight?s1.index>s2.index:s1.weight>s2.weight;};
        priority_queue<server, vector<server>, decltype(freeCmp)> free(freeCmp);
        auto busyCmp = [](server s1, server s2) {return s1.freeTime>s2.freeTime;};
        priority_queue<server, vector<server>, decltype(busyCmp)> busy(busyCmp);

        for(int i=0;i<servers.size();++i) {
            free.push(server(i, servers[i]));
        }

        int time=0;
        for(int i=0;i<tasks.size();++i) {
            if(free.empty()) {
                time=busy.top().freeTime;
            } else {
                time=max(time, i);
            }
            while(!busy.empty() && busy.top().freeTime==time) {
                free.push(busy.top());
                busy.pop();
            }
            
            server s=free.top();
            ans[i]=s.index;

            s.freeTime=time+tasks[i];
            free.pop();
            busy.push(s);
        }
        return ans;                                                                         
    }
};

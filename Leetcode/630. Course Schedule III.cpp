class Solution {
public:
    static bool comparator(vector<int> a, vector<int> b) {
        return a[1]==b[1]?a[0]<b[0]:a[1]<b[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comparator);
        int currentTotalTime = 0;
        priority_queue<int> pq;
        for(auto course: courses) {
            if(currentTotalTime+course[0]<=course[1]) {
                currentTotalTime+=course[0];
                pq.push(course[0]);
            } else if(!pq.empty()){
                int max = pq.top();
                if(max>course[0] && currentTotalTime-max+course[0]<=course[1]) {
                    pq.pop();
                    currentTotalTime = currentTotalTime-max+course[0];
                    pq.push(course[0]);
                }
            }
        }
        return pq.size();
    }
};

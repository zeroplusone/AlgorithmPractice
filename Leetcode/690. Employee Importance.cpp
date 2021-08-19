/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        queue<int> que;
        unordered_map<int, int> index;
        for(int i=0;i<employees.size();++i) {
            index[employees[i]->id]=i;
        }
        
        int ans=0;
        que.push(id);
        while(!que.empty()) {
            Employee* now=employees[index[que.front()]];
            que.pop();
            ans+=now->importance;
            for(int i=0;i<now->subordinates.size();++i) {
                que.push(now->subordinates[i]);
            }
        }
        return ans;
    }
};

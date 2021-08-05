class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        string src, dst;
        for(int i=0;i<equations.size();++i) {
            src=equations[i][0];
            dst=equations[i][1];

            graph[src][dst]=values[i];
            graph[dst][src]=1.0/values[i];    
        }
        
        vector<double> ans(queries.size());
        for(int i=0;i<queries.size();++i){
            unordered_set<string> v;
            ans[i]=DFS(queries[i][0], queries[i][1], graph, v);
        }
        return ans;
    }
    
    double DFS(string src, string dst, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& v) {
        if(graph.count(src)!=0) {
            if(src==dst) {
                return 1;
            }
            if(graph[src].count(dst)!=0) {
                return graph[src][dst];
            }

            v.insert(src);
            for(auto child: graph[src]) {
                if(v.count(child.first)==0) {
                    double cval=DFS(child.first, dst, graph, v);
                    if(cval!=-1) {
                        return child.second*cval;
                    }    
                }
            }
            v.erase(v.find(src));
        }
        
        return -1;
            
    }
};

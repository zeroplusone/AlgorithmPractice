class Solution {
public:

    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        vector<int> nodev(n, -1);
        unordered_map<int, unordered_map<int, int>> graph;
        int totalCnt=0;
        for(int i=0;i<edges.size();++i) {
            totalCnt+=edges[i][2];
            graph[edges[i][0]][edges[i][1]]=edges[i][2];
            graph[edges[i][1]][edges[i][0]]=edges[i][2];
        }  
        
        // BFS 
        queue<pair<int, int>> que;
        que.push(make_pair(0, maxMoves));
        int nodecnt=0;
        int edgecnt=0;
        while(!que.empty()) {
            int now=que.front().first;
            int moves=que.front().second;
            que.pop();
            if(moves>=0 && nodev[now]<moves) {
                nodecnt+=nodev[now]==-1?1:0;
                nodev[now]=moves; 
                for(auto g: graph[now]) {
                    // first: dst, second: cnt
                    edgecnt-=min(g.second, v[now][g.first]+v[g.first][now]);
                    if(moves>=g.second+1) {
                        v[now][g.first]=g.second;
                        que.push(make_pair(g.first, moves-g.second-1));
                    } else {
                        v[now][g.first]=max(v[now][g.first], moves);
                    }
                    edgecnt+=min(g.second, v[now][g.first]+v[g.first][now]);
                }
            }
            
            if(nodecnt==n && edgecnt==totalCnt) {
                break;
            }
            
        }
        return nodecnt+edgecnt;
    }
};

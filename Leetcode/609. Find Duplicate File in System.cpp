class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> file_to_path;
        for(int i=0;i<paths.size();++i) {
            string path="";
            
            int j=0;
            while(paths[i][j]!=' ') {
                path+=paths[i][j];
                j++;
            }

            j++;
            while(j<paths[i].length()) {
                string file="";
                string content="";

                while(paths[i][j]!='(') {
                    file+=paths[i][j];
                    j++;
                }
                j++;
                while(paths[i][j]!=')') {
                    content+=paths[i][j];
                    j++;
                }
                j++;
                j++;
                file_to_path[content].push_back(path+"/"+file);
            }
            
        }
        vector<vector<string>> ans;
        for(auto m: file_to_path) {
            if(m.second.size()>1) {
                ans.push_back(m.second);
            }
        }
        return ans;
    }
};

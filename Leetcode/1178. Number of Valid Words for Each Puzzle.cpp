class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n=words.size();
        int m=puzzles.size();
        vector<int> ans(m, 0);
        
        unordered_map<long long int, int> cnts;
        for(int i=0;i<n;++i) {
            long long int bitmask=0;
            for(int j=0;j<words[i].length();++j) {
                int c=1<<(words[i][j]-'a');
                bitmask|=c;
            }
            cnts[bitmask]++;
        }
        
        for(int i=0;i<m;++i) {
            long long int p=0;
            for(int j=1;j<puzzles[i].length();++j) {
                int c=1<<(puzzles[i][j]-'a');
                p|=c;
            }
            
            int first=1<<(puzzles[i][0]-'a');
            ans[i]=cnts[first];
            for(int submask=p;submask>0;submask=(submask-1)&p) {
                ans[i]+=cnts[submask|first];
            }
        }
        return ans;
    }
};

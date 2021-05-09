class Solution {
public:
    struct Log{
        int year;
        int is_birth;
        Log(int year, int is_birth): year(year), is_birth(is_birth) {};
    };
    
    static bool comparator(Log a, Log b) {
        return a.year==b.year?a.is_birth<b.is_birth:a.year<b.year;
    }
    
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<Log> years;
        for(auto log: logs) {
            years.push_back(Log(log[0], 1));
            years.push_back(Log(log[1], 0));
        }
        sort(years.begin(), years.end(), comparator);
        
        int popu=0, max_popu=0;
        int ans=0;
        for(auto l: years) {
            if(l.is_birth==1) {
                popu++;
                if(popu>max_popu) {
                    max_popu = popu;
                    ans = l.year;
                }
            } else {
                popu--;
            }
        } 
        return ans;
    }
};

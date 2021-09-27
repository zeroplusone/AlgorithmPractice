class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        
        for(int i=0;i<emails.size();++i) {
            string email="";
            bool plus=false;
            int j=0;
            for(;j<emails[i].length();++j) {
                if(emails[i][j]=='@') {
                    email+='@';
                    break;
                } else if(plus) {
                    continue;    
                } if(emails[i][j]=='.') {
                    continue;
                } else if(emails[i][j]=='+') {
                    plus=true;
                } else {
                    email+=emails[i][j];
                }
            }
            
            for(;j<emails[i].length();++j) {
                email+=emails[i][j];
            }
            s.insert(email);
        }
        
        return s.size();
    }
};

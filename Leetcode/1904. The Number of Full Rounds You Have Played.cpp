class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int sh = (startTime[0]-'0')*10+(startTime[1]-'0');
        int sm = (startTime[3]-'0')*10+(startTime[4]-'0');
        
        int fh = (finishTime[0]-'0')*10+(finishTime[1]-'0');
        int fm = (finishTime[3]-'0')*10+(finishTime[4]-'0');
        
        if(sh>fh || sh==fh&&sm>fm ) {
            fh+=24;
        }
        sm=sm==0?0:(sm-1)/15+1;
        fm=fm/15;

        if(fm<sm) {
            fh-=1;
            fm+=4;
        }
        int round=fm-sm;
        round+=(fh-sh)*4;
        return round;
        
    }
};

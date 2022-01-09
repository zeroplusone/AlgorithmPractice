class Solution {
public:
    bool isRobotBounded(string instructions) {
        int angle = 0;
        int x=0, y=0;
        vector<vector<int>> dir {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        for(int i=0;i<instructions.length();++i) {
            if(instructions[i]=='L') {
                angle=(angle+3)%4;
            } else if(instructions[i]=='R') {
                angle=(angle+1)%4;
            } else if(instructions[i]=='G') {
                x+=dir[angle][0];
                y+=dir[angle][1];
            }
        }
        return angle!=0 || (x==0&&y==0);
    }
};

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:

    vector<int> diffx=vector<int>{0, -1, 0, 1};
    vector<int> diffy=vector<int>{1, 0, -1, 0};
    void cleanRoom(Robot& robot) {
        unordered_map<int, unordered_map<int, int>> v;
        DFS(0, 0, 0, robot, v);
    }
    
    void DFS(int x, int y, int dir, Robot& robot, unordered_map<int, unordered_map<int, int>>& v) {
        v[x][y]=true;
        robot.clean();
        
        int newx, newy, newdir;
        // 0 up, 1 left, 2 down, 3 right
        for(int i=3;i>=0;--i) {
            robot.turnRight();
            newx=x+diffx[(i+dir)%4];
            newy=y+diffy[(i+dir)%4];
            newdir=(dir+i)%4;
            if(!v[newx][newy] && robot.move()) {
                DFS(newx, newy, newdir, robot, v);
            }
        }

        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

};

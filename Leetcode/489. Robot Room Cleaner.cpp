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
    void cleanRoom(Robot& robot) {
        unordered_set<string> v;
        DFS(0, 0, 0, robot, v);
    }
    
    void DFS(int x, int y, int dir, Robot& robot, unordered_set<string>& v) {
        v.insert(hash(x, y));
        robot.clean();
        
        int newx, newy, newdir;
        // 0 up, 1 left, 2 down, 3 right
        robot.turnRight();
        newx=calx(x, dir, 3);
        newy=caly(y, dir, 3);
        newdir=caldir(dir, 3);
        if(v.count(hash(newx, newy))==0 && robot.move()) {
            DFS(newx, newy, newdir, robot, v);
        }
        
        robot.turnLeft();
        newx=calx(x, dir, 0);
        newy=caly(y, dir, 0);
        newdir=caldir(dir, 0);
        if(v.count(hash(newx, newy))==0 && robot.move()) {
            DFS(newx, newy, newdir, robot, v);
        }
        
        robot.turnLeft();
        newx=calx(x, dir, 1);
        newy=caly(y, dir, 1);
        newdir=caldir(dir, 1);
        if(v.count(hash(newx, newy))==0 && robot.move()) {
            DFS(newx, newy, newdir, robot, v);
        }
        
        robot.turnLeft();
        newx=calx(x, dir, 2);
        newy=caly(y, dir, 2);
        newdir=caldir(dir, 2);
        if(v.count(hash(newx, newy))==0 && robot.move()) {
            DFS(newx, newy, newdir, robot, v);
        }

        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    int caldir(int dir, int turn) {
        // 0 up, 1 left, 2 down, 3 right
        switch(dir){ // face
            // move
            case 0:
                if(turn==0) {
                    return 0;
                } else if(turn==1) {
                    return 1;
                } else if(turn==2) {
                    return 2;
                } else if(turn==3) {
                    return 3;
                }
            case 1:
                if(turn==0) {
                    return 1;
                } else if(turn==1) {
                    return 2;
                } else if(turn==2) {
                    return 3;
                } else if(turn==3) {
                    return 0;
                }
            case 2:
                if(turn==0) {
                    return 2;
                } else if(turn==1) {
                    return 3;
                } else if(turn==2) {
                    return 0;
                } else if(turn==3) {
                    return 1;
                }
            case 3:
                if(turn==0) {
                    return 3;
                } else if(turn==1) {
                    return 0;
                } else if(turn==2) {
                    return 1;
                } else if(turn==3) {
                    return 2;
                }
        }
        return dir;
    }
    
    int calx(int x, int dir, int turn) {
        // 0 up, 1 left, 2 down, 3 right
        switch(dir){ // face
            // move
            case 0:
                if(turn==0) {
                    return x;
                } else if(turn==1) {
                    return x-1;
                } else if(turn==2) {
                    return x;
                } else if(turn==3) {
                    return x+1;
                }
            case 1:
                if(turn==0) {
                    return x-1;
                } else if(turn==1) {
                    return x;
                } else if(turn==2) {
                    return x+1;
                } else if(turn==3) {
                    return x;
                }
            case 2:
                if(turn==0) {
                    return x;
                } else if(turn==1) {
                    return x+1;
                } else if(turn==2) {
                    return x;
                } else if(turn==3) {
                    return x-1;
                }
            case 3:
                if(turn==0) {
                    return x+1;
                } else if(turn==1) {
                    return x;
                } else if(turn==2) {
                    return x-1;
                } else if(turn==3) {
                    return x;
                }
        }
        return x;
    }
    
    int caly(int y, int dir, int turn) {
        // 0 up, 1 left, 2 down, 3 right
        switch(dir){ // face
            // move
            case 0:
                if(turn==0) {
                    return y+1;
                } else if(turn==1) {
                    return y;
                } else if(turn==2) {
                    return y-1;
                } else if(turn==3) {
                    return y;
                }
            case 1:
                if(turn==0) {
                    return y;
                } else if(turn==1) {
                    return y-1;
                } else if(turn==2) {
                    return y;
                } else if(turn==3) {
                    return y+1;
                }
            case 2:
                if(turn==0) {
                    return y-1;
                } else if(turn==1) {
                    return y;
                } else if(turn==2) {
                    return y+1;
                } else if(turn==3) {
                    return y;
                }
            case 3:
                if(turn==0) {
                    return y;
                } else if(turn==1) {
                    return y+1;
                } else if(turn==2) {
                    return y;
                } else if(turn==3) {
                    return y-1;
                }
        }
        return y;
    }
    
    string hash(int x, int y) {
        return to_string(x) + "#" + to_string(y);
    }
};

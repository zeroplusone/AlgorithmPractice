/*********************
problem: 836. Rectangle Overlap
https://leetcode.com/contest/weekly-contest-85/problems/rectangle-overlap/
**********************/

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool overlap=true;
        if(rec1[0]<=rec2[0]){
            if(rec2[0]<rec1[2])
                overlap=true;
            else
                overlap=false;
        }else{
            if(rec1[0]<rec2[2])
                overlap=true;
            else
                overlap=false;
        }
        if(overlap){
            if(rec1[1]<=rec2[1]){
                if(rec2[1]<rec1[3])
                    overlap=true;
                else
                    overlap=false;
            }else{
                if(rec1[1]<rec2[3])
                    overlap=true;
                else
                    overlap=false;
            }
        }
        return overlap;
    }
};
class Solution {
public:
    bool isRobotBounded(string instructions) {

        int angle = 0;
        int x = 0, y = 0;

        for (char& i : instructions) {

            if (i == 'L') { angle++;
                if (angle == 4) angle = 0;
            } 
            
            else if (i == 'R') { angle--;
                if (angle == -1) angle = 3;
            } 
            
            else {
                if (angle == 0) y++;
                else if (angle == 1) x--;
                else if (angle == 2) y--;
                else x++;

            }
        }

        if ((x != 0 || y != 0) && angle == 0) return false;
        
        else return true;
    }
};
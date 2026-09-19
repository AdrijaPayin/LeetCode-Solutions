class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        int X = max(x1, min(xCenter, x2));
        int Y = max(y1, min(yCenter, y2));

        int x = xCenter - X;
        int y = yCenter - Y;

        return (x * x) + (y * y) <= radius * radius;
    }
};
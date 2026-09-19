class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX = clamp(xCenter, x1, x2);
        int closestY = clamp(yCenter, y1, y2);
        int dx = closestX - xCenter;
        int dy = closestY - yCenter;
        dx *= dx;
        dy *= dy;
        radius *= radius;
        if(dx + dy <= radius) return true;
        return false;
    }
};
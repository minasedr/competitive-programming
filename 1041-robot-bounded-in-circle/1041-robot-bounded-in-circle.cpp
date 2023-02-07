class Solution {
public:
    bool isRobotBounded(string instructions) {
        int posx = 0, posy = 0;
        int dx = 0, dy = 1;
        
        for (char ch: instructions) {
            if (ch == 'L') {
                swap(dx, dy);
                dx *= -1;
            } else if (ch == 'R') {
                swap(dx, dy);
                dy *= -1;
            } else {
                posx += dx;
                posy += dy;
            }
        }
        
        return (!posx and !posy) or (dx or dy != 1);
    }
};
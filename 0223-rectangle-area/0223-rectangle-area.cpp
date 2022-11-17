class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int dx = max(0, min(ax2, bx2) - max(ax1, bx1));
        int dy = max(0, min(ay2, by2) - max(ay1, by1));
        int area_one = abs(ax2 - ax1) * abs(ay2 - ay1);
        int area_two = abs(bx2 - bx1) * abs(by2 - by1);
        return area_one + area_two - dx * dy;
    }
};
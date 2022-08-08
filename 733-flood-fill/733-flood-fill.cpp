class Solution {
public:
    bool vis[55][55] {false};
    void ff(vector<vector<int>>& im, int s, int d, int x, int c) {
        int n = im.size(), m = im[0].size();
        if (s < 0 || s >= n || d < 0 || d >= m || im[s][d] != x || vis[s][d])
            return;
        vis[s][d] = true;
        im[s][d]  = c;
        ff(im, s + 1, d, x, c);
        ff(im, s - 1, d, x, c);
        ff(im, s, d + 1, x, c);
        ff(im, s, d - 1, x, c);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        ff(image, sr, sc, image[sr][sc], color);
        return image;
    }
};
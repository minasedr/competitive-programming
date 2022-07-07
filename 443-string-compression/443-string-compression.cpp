class Solution {
public:
    int compress(vector<char>& chars) {
        int beg = 0, end = 0, n = chars.size();
        string res;
        while (end < n) {
            while (end < n && chars[beg] == chars[end])
                end++;
            int len = end - beg;
            res += chars[beg];
            if (len > 1)
                res += to_string(len);
            beg = end;
        }
        chars.clear();
        for (auto x: res)
            chars.push_back(x);
        return chars.size();
    }
};
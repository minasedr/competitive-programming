class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int cur = 0, sum = 0;
        reverse(s.begin(), s.end());
        
        for (auto c: s)
            sum += (roman[c] < cur ? -roman[c] : cur = roman[c]);
        
        return sum;
    }
};
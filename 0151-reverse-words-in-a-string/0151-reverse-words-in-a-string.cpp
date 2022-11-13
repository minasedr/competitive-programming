class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        string cur = "";
        for (auto n: s) {
            if (n == ' ') {
                arr.push_back(cur);
                cur = "";
            } else
                cur += n;
        }
        arr.push_back(cur);
        reverse(arr.begin(), arr.end());
        string ans = "";
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] != "")
            ans += arr[i] + " ";
        }
        return ans.substr(0, ans.size() - 1);
    }
};
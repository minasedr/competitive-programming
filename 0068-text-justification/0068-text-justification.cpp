class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        function<string(int, int)> alignLeft;
        alignLeft = [&](int low, int high) {
            string line;
            for(int i = low; i <= high; i++)
                line += words[i] + " ";
            line.pop_back();
            line += string(maxWidth - line.size(), ' ');
            return line;
        };
        
        function<string(int, int, int)> justifyLine;
        justifyLine = [&] (int low, int high, int extraSpaces) {
            string line;
            int n = high - low + 1, slots = n - 1;
            int space = slots > 0 ? extraSpaces / slots : -1;
            
            for(int i = 0; i < n - 1; i++) {
                line += words[low + i] + " " + string(space, ' ');
                slots--;
                extraSpaces -= space;

                if (extraSpaces > slots * space) {
                    line += " ";
                    extraSpaces--;
                }
            }
            line += words[high] + string(extraSpaces, ' ');
            return line;
        };
        
        vector<string> ans;
        for(int i = 0; i < words.size(); i++) {
            int curWidth = 0;
            int j = i;
            while (j < words.size() and (curWidth + words[j].size() <= maxWidth))
                curWidth += words[j++].size() + 1;
            if (j < words.size())
                ans.push_back(justifyLine(i, j - 1, maxWidth - curWidth + 1));
            else
                ans.push_back(alignLeft(i, j - 1));
            i = j - 1;
        }
        return ans;
    }
};
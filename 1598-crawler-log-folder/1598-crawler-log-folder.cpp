class Solution {
public:
    int minOperations(vector<string>& logs) {
        int folder = 0;
        
        for (auto log: logs) {
            if (log == "../")
                folder--;
            folder = max(0, folder);
            if (log[0] != '.')
                folder++;
        }
        
        return folder;
    }
};
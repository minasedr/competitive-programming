class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int beg = 0, end = n-1, ans = 0;
        
        while (beg <= end) {
            if (people[beg] + people[end] <= limit)
                beg++;
            end--, ans++;
        }
        return ans;
    }
};
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char> change{'A', 'C', 'G', 'T'};
        unordered_set<string> geneBank(bank.begin(), bank.end());
        set<string> vis;
        function<bool(string, string)> dist;
        dist = [&](string a, string b) {
            int n = a.size(), d = 0;
            for (int i = 0; i < n; i++)
                if (a[i] != b[i])
                    d++;
            return (d == 1 ? true: false);
        };
        function<int()> bfs;
        bfs = [&]() {
            queue<pair<string, int>> q;
            q.push({startGene, 0});
            vis.insert(startGene);
            
            while (!q.empty()) {
                auto [word, cnt] = q.front();
                q.pop();
                if (word == endGene)
                    return cnt;
                
                for (auto w: bank) {
                    if (vis.count(w))
                        continue;
                    if (dist(word, w)) {
                        q.push({w, cnt + 1});
                        vis.insert(w);
                    }
                }
            }
            return -1;
        };
        return bfs();
        
    }
};
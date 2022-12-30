class OrderedStream {
public:
    int n;
    int idx = 1;
    vector<string> mp;
    OrderedStream(int n) {
        mp.resize(n + 1, "");
        this->n = n;
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> cur;
        mp[idKey] = value;
        
        for (int i = 1; i <= n; i++) {
            if (mp[i] == "")
                break;
            if (i < idKey)
                continue;
            cur.push_back(mp[i]);
        }
        return cur;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
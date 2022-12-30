class OrderedStream {
public:
    int n, idx;
    vector<string> mp;
    OrderedStream(int n) {
        idx = 1;
        mp.resize(n + 1, "");
        this->n = n;
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> cur;
        mp[idKey] = value;
        if (idx == idKey)
            while (idx <= n and mp[idx] != "")
                cur.push_back(mp[idx++]);
            
        return cur;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
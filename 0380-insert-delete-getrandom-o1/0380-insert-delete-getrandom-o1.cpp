class RandomizedSet {
public:
    map<int, int> mp;
    vector<int> cur;
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if (mp.count(val))
            return false;
        mp[val] = cur.size();
        cur.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!mp.count(val))
            return false;
        int idx = mp[val];
        swap(cur[idx], cur.back());
        mp[cur[idx]] = idx;
        mp.erase(val);
        cur.pop_back();
        return true;
    }
    
    int getRandom() {
        int idx = rand() % cur.size();
        return cur[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
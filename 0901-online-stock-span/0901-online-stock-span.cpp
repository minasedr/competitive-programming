class StockSpanner {
public:
    stack<array<int, 2>> st;
    StockSpanner() {}
    
    int next(int price) {
        int cnt = 0;
        while (!st.empty() && st.top()[1] <= price) {
            cnt += st.top()[0];
            st.pop();
        }
        st.push({cnt + 1, price});
        return cnt + 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
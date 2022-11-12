class MedianFinder {
public:
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<>> minpq;
    
    MedianFinder() {}
    
    void addNum(int num) {
        maxpq.push(num);
        if (maxpq.size() > minpq.size() + 1) {
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        while (!maxpq.empty() && !minpq.empty() && maxpq.top() > minpq.top()) {
            int mx = maxpq.top();
            int mn = minpq.top();
            maxpq.pop();
            minpq.pop();
            maxpq.push(mn);
            minpq.push(mx);
        }
    }
    
    double findMedian() {
        int n = maxpq.size() + minpq.size();
        if (n % 2 == 0) {
            int left = maxpq.top();
            int right = minpq.top();
            return (left + right) / 2.0;
        } else
            return maxpq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
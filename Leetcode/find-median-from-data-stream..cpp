class MedianFinder {
public:
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;
    int count = 0;

    MedianFinder() {}

    void addNum(int num) {
        if (mx.empty() || num <= mx.top())
            mx.push(num);
        else
            mn.push(num);

        if (mx.size() > mn.size() + 1) {
            mn.push(mx.top());
            mx.pop();
        } else if (mn.size() > mx.size()) {
            mx.push(mn.top());
            mn.pop();
        }

        count = mx.size() + mn.size();
    }
    double findMedian() {
        if (count % 2 != 0)
            return mx.top();
        else {
            double b = mn.top();
            double c = mx.top();
            return (b + c) / 2.0;
        }
    }
};
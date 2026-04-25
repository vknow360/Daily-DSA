class Solution {
public:
    vector<int> reducePairs(vector<int>& arr) {
        stack<int> s;

        for (int i : arr) {
            bool push = true;

            while (!s.empty() && i * s.top() < 0 && push) {
                int e = s.top();

                if (abs(i) > abs(e)) {
                    s.pop();
                } 
                else if (abs(i) == abs(e)) {
                    s.pop();
                    push = false;
                } 
                else {
                    push = false;
                }
            }

            if (push) {
                s.push(i);
            }
        }

        vector<int> res;
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

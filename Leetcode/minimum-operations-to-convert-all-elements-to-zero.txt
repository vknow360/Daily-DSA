class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int ops = 0;

        for (int e : nums) {
            while (!st.empty() && st.top() > e)
                st.pop();

            if (st.empty() || e > st.top()) {
                if (e > 0) ops++;
                st.push(e);
            }
        }

        return ops;
    }
};

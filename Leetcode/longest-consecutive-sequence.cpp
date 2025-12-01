class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_set<int> st;
        for(int i : nums) {
            st.insert(i);
        }
        
        int mxlen = 1;
        for(auto& x : st) {
            if(!st.count(x-1)) {
                int y = x+1;
                while(st.count(y)) {
                    y++;
                }
                mxlen = max(mxlen, y-x);
            }
        }

        return mxlen;
    }
};
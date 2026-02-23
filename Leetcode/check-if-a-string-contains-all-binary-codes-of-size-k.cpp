class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_set<string> st;
        int left = 0;
        while(left < n-k+1) {
            st.insert(s.substr(left, k));
            left++;
        }

        return st.size() == (int)pow(2,k);
    }
};

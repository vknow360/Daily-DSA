class Solution {
public:
    void helper(int n, vector<string>& ans, string s, int o, int c) {
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        } else {
            if(o < n){
                helper(n, ans, s+'(', o+1, c);
            }
            if(c < o){
                helper(n, ans, s+')', o, c+1);
            }
        }
    }
    vector<string> generateParenthesis(int n) { 
        vector<string> ans; 
        helper(n, ans, "", 0, 0);
        return ans;
    }
};
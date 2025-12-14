class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans;
        int balance = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                balance += 1;
                if(balance > 1) ans.push_back(s[i]);
            }else {
                balance -= 1;
                if(balance > 0) ans.push_back(s[i]);
            }
        }

        return ans;
    }
};

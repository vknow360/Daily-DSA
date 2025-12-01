class Solution {
public:
    string lexSmallest(string s) {
        string ans = s;
        for(int i = 1; i <= s.size(); i++){
            string a = s;
            string b = s;
            reverse(a.begin(), a.begin()+i);
            reverse(b.rbegin(), b.rbegin()+i);
            ans = min(ans, min(a,b));
        }
        return ans;
    }
};
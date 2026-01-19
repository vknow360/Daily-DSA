class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        int n = s.size();
        if(k==n) return "0";
        
        string ans;
        int i = 0;
        while(i < n) {
            while(!ans.empty() && ans.back() > s[i] && k > 0) {
                ans.pop_back();
                k--;
            }
            ans.push_back(s[i]);
            i++;
        }
        
        while(k>0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }
        
        int j = 0;
        while(j < ans.size() && ans[j] == '0') {
            j++;
        }
        ans = ans.substr(j, ans.size());
        if(ans.empty()) return "0";
        return ans;
    }
};

class Solution {
  public:
    void helper(int n, vector<string> &ans, string s, int i){
        if(i==n) {
            ans.push_back(s);
            return;
        }
        helper(n, ans, s+"0", i+1);
        helper(n, ans, s+"1", i+1);
    }
    vector<string> binstr(int n) {
        // code here
        vector<string> ans;
        helper(n, ans, "" ,0);
        return ans;
    }
};
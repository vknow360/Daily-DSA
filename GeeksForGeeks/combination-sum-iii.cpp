class Solution {
  public:
    void helper(int n, int k, int start, set<int> &s, vector<vector<int>> &ans){
    if(n == 0 && k == 0){
        ans.push_back(vector<int>(s.begin(), s.end()));
        return;
    }
    if(n <= 0 || k <= 0) return;

    for(int i = start; i <= 9; i++){
        if(!s.count(i)){
            s.insert(i);
            helper(n - i, k - 1, i + 1, s, ans);
            s.erase(i);
        }
    }
}

    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>> ans;
        if(n < k || n > 45) return ans;
        set<int> s;
        helper(n, k, 1 ,s, ans);
        return ans;
    }
};
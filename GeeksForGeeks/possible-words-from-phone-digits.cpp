class Solution {
  public:
    vector<vector<string>> mp = {
    {""},
    {""},
    {"a", "b", "c"},
    {"d", "e", "f"},
    {"g", "h", "i"},
    {"j", "k", "l"},
    {"m", "n", "o"},
    {"p", "q", "r", "s"},
    {"t", "u", "v"},
    {"w", "x", "y", "z"}
    };
    void helper(vector<string> &ans, vector<int> &arr, int i, string s){
        if(i >= arr.size()){
            ans.push_back(s);
            return;
        }
        int key = arr[i];
        if(key < 2){
            helper(ans, arr, i+1, s);
        }else{
            for(string c : mp[key]){
                helper(ans, arr, i+1, s+c);
            }
        }
        
    }
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        vector<string> ans;
        helper(ans, arr, 0, "");
        
        return ans;
    }
};
class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        vector<int> ans;
        for(int e : arr) {
            int val = abs(e);
            if(arr[val-1] < 0) ans.push_back(val);
            else {
                arr[val-1] *= -1;
            }
        }
        return ans;
    }
};

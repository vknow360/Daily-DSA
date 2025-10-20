class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
        vector<int> catlan_nums = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862};
        vector<int> ans;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int num = arr[i];
            int sm = 0;
            int lg = 0;
            for(int i = 0; i < n; i++){
                if(arr[i] < num) sm++;
                if(arr[i] > num) lg++;
            }
            ans.push_back(catlan_nums[lg] * catlan_nums[sm]);
        }
        return ans;
    }
};
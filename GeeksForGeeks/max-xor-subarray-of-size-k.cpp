class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < k; i++) {
            sum ^= arr[i];
        }
        int ans = sum; 
        for(int i = k; i < n; i++) {
            sum ^= arr[i-k];
            sum ^= arr[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};

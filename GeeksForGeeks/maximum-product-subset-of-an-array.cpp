class Solution {
  public:
    int findMaxProduct(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n==1) return arr[0];
        
        int MOD = 1e9 + 7;
    
        int neg = 0;
        int zero = 0;
        int minNegIdx = -1, minNeg = INT_MIN;
        int idx = 0;
        for(int i : arr) {
            if(i < 0) {
                neg++;
                if(i > minNeg) {
                    minNegIdx = idx;
                    minNeg = i;
                }
            }
            if(i == 0) zero++;
            idx++;
        }
        
        if(zero == n || (neg == 1 && zero == n-1)) return 0;
        bool skipNeg = (neg & 1);
        long long ans = 1;
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) continue;
            if(skipNeg && i == minNegIdx) continue;
            
            ans = (((ans * arr[i]) % MOD) + MOD) % MOD;
        }
        return ans;
    }
};

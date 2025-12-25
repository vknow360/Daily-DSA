class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ans = 0;
        
        vector<int> prefEven(n, 0);
        vector<int> prefOdd(n, 0);
        prefEven[0] = arr[0];
        for(int i = 1; i < n; i++) {
            prefEven[i] = prefEven[i-1];
            prefOdd[i] = prefOdd[i-1];
            if(i%2 == 0) {
                prefEven[i] += arr[i];
            }else {
                prefOdd[i] += arr[i];
            }
        }
        
        if(prefEven.back()-prefEven[0] == prefOdd.back()-prefOdd[0]) ans++;
        for(int i = 1; i < n; i++) {
            int lftE = prefEven[i-1];
            int lftO = prefOdd[i-1];
            int rghtE = prefOdd.back()-prefOdd[i];
            int rghtO = prefEven.back()-prefEven[i];
            if(lftE+rghtE == lftO+rghtO) ans++;
        }
        
        return ans;
    }
};

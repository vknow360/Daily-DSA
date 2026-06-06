class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
        int ans = 0;
        
        vector<int> dx = {2, 2, -2, -2, 1, -1, 1, -1};
        vector<int> dy = {1, -1, 1, -1, 2, 2, -2, -2};
        
        int total = n*m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int count = 1;
                for(int k = 0; k < 8; k++) {
                    int x = i+dx[k], y = j+dy[k];
                    if(x >= 0 && x < n && y >= 0 && y < m) count++;
                }
                ans += (total - count);
            }
        }
        return ans;
    }
};

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n = mat.size(), m = mat[0].size();
        
        int lo = mat[0][0], hi = mat[n-1][m-1];
        int ans = 0;
        while(lo <= hi) {
            int mid = lo+(hi-lo)/2;
            int count = 0;
            int i = 0, j = m-1;
            while(i < n && j >= 0) {
                if(mat[i][j] <= mid) {
                    count += j+1;
                    i++;
                }else {
                    j--;
                }
            }
            
            if(count >= k) {
                ans = mid;
                hi = mid-1;
            }else {
                lo = mid+1;
            }
        }
        
        return ans;
        
    }
};

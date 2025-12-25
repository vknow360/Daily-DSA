class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<int> res;
        
        int lo = 0, hi = m-1;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            int idx = 0;
            for(int i = 0; i < n; i++) {
                if(mat[i][mid] > mat[idx][mid]) {
                    idx = i;
                }
            }
            int val = mat[idx][mid];
            int left = (mid>0) ? mat[idx][mid-1] : INT_MIN;
            int right = (mid<m-1) ? mat[idx][mid+1] : INT_MIN;
            
            if(val >= left && val >= right) {
                res = {idx, mid};
                break;
            }else if(left > val) {
                hi = mid-1;
            }else if(right > val){
                lo = mid+1;
            }
        }
        return res;
    }
};

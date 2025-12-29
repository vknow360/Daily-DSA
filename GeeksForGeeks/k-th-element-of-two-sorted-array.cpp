class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int m = a.size(), n = b.size();
        int i = 0, j = 0;
        while(i < m && j < n && i+j+1< k) {
            if(a[i] <= b[j]) i++;
            else j++;
        }
        while(i<m && i+j+1 < k) {
            i++;
        }
        while(j<n && i+j+1 < k) {
            j++;
        }
        if(i<m && j<n) {
            if(a[i] <= b[j]) return a[i];
            return b[j];   
        }else if(i<m) return a[i];
        
        return b[j];
    }
};

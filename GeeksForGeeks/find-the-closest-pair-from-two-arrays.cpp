class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        int n = arr1.size(), m = arr2.size();
        
        int i = n-1, j = 0;
        
        int minDiff = INT_MAX;
        int p1, p2;
        
        while(i >= 0 && j < m) {
            int sum = arr1[i] + arr2[j];
            int diff = sum - x;
            
            if(abs(diff) < minDiff) {
                minDiff = abs(diff);
                p1 = arr1[i];
                p2 = arr2[j];
            }
            
            if(diff > 0) i--;
            else j++;
        }
        
        return {p1, p2};
    }
};

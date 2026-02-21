class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        
        vector<int> freq(n+1, 0);
        for(int i : citations) freq[min(n, i)]++;
        for(int i = n-1; i >= 0; i--) {
            freq[i] += freq[i+1];
        }
        
        int ans = 0;
        
        for(int i = 1; i <= n; i++) {
            if(freq[i] >= i) {
                ans = i;
            }else break;
        }
        
        return ans;
    }
};

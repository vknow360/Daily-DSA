class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int n = s.size();
        int ans = 0;
        
        vector<int> freq(26, 0);
        int i = 0;
        int j = 0;
        while(j < n) {
            char c = s[j];
            freq[c-'A']++;
            
            int mx = *max_element(freq.begin(), freq.end());
            if(j-i+1 - mx > k) {
                freq[s[i] - 'A']--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};

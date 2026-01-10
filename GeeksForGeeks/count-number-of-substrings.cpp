class Solution {
  public:
    int solve(string& s, int k) {
        if (k < 0) return 0;

        int n = s.size();
        vector<int> freq(26, 0);

        int left = 0;
        int distinct = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            int r = s[right] - 'a';
            if (freq[r] == 0) distinct++;
            freq[r]++;

            while (distinct > k) {
                int l = s[left] - 'a';
                freq[l]--;
                if (freq[l] == 0) distinct--;
                left++;
            }

            ans += (right - left + 1);
        }

        return ans;
    }

    int countSubstr(string& s, int k) {
        return solve(s, k) - solve(s, k - 1);
    }
};

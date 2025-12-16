class Solution {
public:
    int minF(vector<int>& freq) {
        int ans = 501;
        for (int f : freq) {
            if (f == 0)
                continue;
            ans = min(ans, f);
        }
        return ans;
    }
    int maxF(vector<int>& freq) {
        int ans = 0;
        for (int f : freq) {
            if (f == 0)
                continue;
            ans = max(ans, f);
        }
        return ans;
    }
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j]-'a']++;
                int mn = minF(freq);
                int mx = maxF(freq);
                if(mn != mx) ans += mx-mn;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            freq[s[i]]++;
            if(freq.size() == (i+1)%3) ans++;
        }

        return ans;
    }
};

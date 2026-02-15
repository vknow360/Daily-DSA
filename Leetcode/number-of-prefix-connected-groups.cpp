class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n = words.size();
        int ans = 0;

        unordered_map<string, int> freq;

        for(string s : words) {
            if(s.size() < k) continue;
            string pref = s.substr(0, k);
            freq[pref]++;
        }

        for(auto& [k, v] : freq) {
            if(v >= 2) {
                ans++;
            }
        }

        return ans;
    }
};

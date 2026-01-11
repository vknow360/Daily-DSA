class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n = words.size();

        unordered_map<string, int> mp;
        
        for(string& s : words) {
            int len = s.size();

            if(len == 1) {
                mp["*"]++;
                continue;
            }

            string key;
            for(int i = 1; i < len; i++) {
                int d = (s[i]-s[i-1] + 26) % 26;
                key += to_string(d);
                key += "*";
            }
            mp[key]++;
        }

        long long ans = 0LL;

        for(auto& [k, v] : mp) {
            ans += (1LL*v*(v-1))/2;
        }

        return ans;
    }
};

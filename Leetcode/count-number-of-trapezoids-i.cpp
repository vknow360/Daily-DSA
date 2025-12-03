class Solution {
public:
    long long getLines(long long n) {
        if (n < 2) {
            return 0;
        }
        long long result = (long long)n * (n - 1) / 2;
        return result;
    }
    int countTrapezoids(vector<vector<int>>& points) {
        const int MOD = 1000000007;

        auto comp = [&](auto& v1, auto& v2) {
            return v1[1] < v2[1];
        };

        //sort(points.begin(), points.end(), comp);

        unordered_map<int, int> hzn;

        for (auto& vec : points) {
            hzn[vec[1]]++;
        }

        vector<long long> pref;
        for (auto& [k, v] : hzn) {
            pref.push_back(v);
        }

        //sort(pref.begin(), pref.end());
        //reverse(pref.begin(), pref.end());

        for (int i = 0; i < pref.size(); i++) {
            pref[i] = getLines(pref[i]);
        }

        long long prefix = 0;
        long long ans = 0;
        for(int i = 0; i < pref.size(); i++){
            ans += pref[i]*prefix;
            prefix += pref[i];
        }

        return ans % MOD;
    }
};
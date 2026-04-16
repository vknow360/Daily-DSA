class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> res;
        for (int i : queries) {
            int e = nums[i];
            if (mp[e].size() == 1) {
                res.push_back(-1);
            } else {
                auto& vec = mp[e];
                auto it = lower_bound(vec.begin(), vec.end(), i);
                int pos = it - vec.begin();
                int prev = (pos - 1 + vec.size()) % vec.size();
                int next = (pos + 1) % vec.size();
                int d1 = min(abs(i - vec[prev]), n - abs(i - vec[prev]));
                int d2 = min(abs(i - vec[next]), n - abs(i - vec[next]));

                res.push_back(min(d1, d2));
            }
        }
        return res;
    }
};

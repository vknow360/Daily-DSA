class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        vector<int> ans;

        int i = 0, j = k - 1;
        while (j < n) {

            priority_queue<pair<int, int>> pq;

            unordered_map<int, int> mp;
            for (int l = i; l <= j; l++) {
                mp[nums[l]]++;
            }

            int sum = 0;

            if (mp.size() < x) {
                for (auto [k, v] : mp) {
                    sum += k * v;
                }
            } else {
                for (const auto [k, v] : mp) {
                    pq.push({v, k});
                }
                
                int len = pq.size();

                while (pq.size() > len-x) {
                    auto p = pq.top();
                    sum += p.first * p.second;
                    pq.pop();
                }
            }
            ans.push_back(sum);
            i++;
            j++;
        }
        return ans;
    }
};
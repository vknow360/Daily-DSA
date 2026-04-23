class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            int e = nums[i];
            mp[e].push_back(i);
        }

        vector<long long> ans(n);

        for(auto& [key, vec] : mp) {
            long long sum = 0;
            for(int i : vec) sum += i;

            long long leftSum = 0;
            int k = vec.size();

            for(int i = 0; i < k; i++) {
                long long rightSum = sum - leftSum - vec[i];

                long long left = 1LL * vec[i] * i - leftSum;
                long long right = rightSum - 1LL * vec[i] * (k-i-1);

                ans[vec[i]] = left+right;

                leftSum += vec[i];
            }
        }
        return ans;
    }
};

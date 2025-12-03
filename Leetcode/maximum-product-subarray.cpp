class Solution {
public:
    long long solve(vector<int>& nums) {
        if (nums.empty())
            return 0;

        if(nums.size() == 1) return nums[0];    

        long long arrPdt = 1;
        vector<long long> prefPdt;
        long long lastPdt = 1;
        for (int i = 0; i < nums.size(); i++) {
            prefPdt.push_back(lastPdt * nums[i]);
            lastPdt = prefPdt[i];
            arrPdt *= nums[i];
        }

        int negCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            negCount += (nums[i] < 0 ? 1 : 0);
        }

        long long ans = max(arrPdt, 0LL); // take complete array pdt

        // check neg count
        if (negCount % 2 != 0) {
            // try removing first neg from prefix
            int j = 0;
            while (j < nums.size() && nums[j] > 0)
                j++;
            long long old = prefPdt[j];
            ans = max(ans, prefPdt.back() / old);

            // try removing last neg from suffix
            int k = nums.size() - 1;
            while (k >= 0 && nums[k] >= 0)
                k--;
            long long next = prefPdt[max(0, k - 1)];

            ans = max(ans, next);
        }
        return ans;
    }
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        long long ans = 0;
        vector<int> vec;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                ans = max(ans, solve(vec));
                vec.clear();
            } else {
                vec.push_back(nums[i]);
            }
        }
        ans = max(ans, solve(vec));

        return ans;
    }
};
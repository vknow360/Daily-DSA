class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mxE = *max_element(nums.begin(), nums.end());
        map<int,int> events;
        unordered_map<int,int> mp;
        for(int i : nums){
            mp[i]++;
            events[max(i-k, 0)]++;
            events[min(i+k, mxE + k) + 1]--;

            events[i] += 0;
        }

        int mxFreq = 1;
        int cumSum = 0;
        for(auto& p : events){
            int i = p.first;
            p.second += cumSum;

            int conversion = p.second - mp[i];
            mxFreq = max(mxFreq, min(numOperations, conversion) + mp[i]);
            cumSum = p.second;
        }
        return mxFreq;
    }
};
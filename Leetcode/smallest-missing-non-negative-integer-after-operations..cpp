class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> freq(value, 0);
        for(int i : nums){
            freq[((i % value + value) % value)]++;
        }

        int mex = 0;
        while(freq[mex%value] > 0){
            freq[mex%value]--;
            mex++;
        }
        return mex;
    }
};
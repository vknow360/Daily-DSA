class Solution {
public:
    int reverse(int n){
        int rev = 0;
        while(n > 0){
            rev = rev*10 + n%10;
            n /= 10;
        }
        return rev;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        for(int i : nums){
            s.insert(reverse(i));
        }
        return s.size();
    }
};
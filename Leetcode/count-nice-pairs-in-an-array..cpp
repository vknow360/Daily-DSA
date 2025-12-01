class Solution {
public:
    int rev(int num){
        int rev = 0;
        while(num > 0){
            rev = rev*10 + num%10;
            num /= 10;
        }
        return rev;
    }
    int countNicePairs(vector<int>& nums) {
        long long count = 0;
        unordered_map<int, int> freq;
        for(int i : nums){
            int reverse = rev(i);
            count += freq[(i - reverse)];
            freq[(i - reverse)]++;
        }
        return (count % 1000000007);
    }
};
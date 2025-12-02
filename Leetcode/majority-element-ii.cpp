class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = nums[0];
        int count1 = 0;
        int i = 0;
        while(i < nums.size()-1 && nums[i] != candidate1) i++;

        int candidate2 = nums[i];
        int count2 = 0;

        for(int e : nums){
            if(e == candidate1) count1++;
            else if(e == candidate2) {
                count2++;
            }else if(count1 == 0){
                candidate1 = e;
                count1 = 1;
            }else if(count2 == 0){
                candidate2 = e;
                count2 = 1;
            }else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for(int e : nums){
            if(e == candidate1) count1++;
            else if(e == candidate2) count2++;
        }

        int majority = nums.size()/3;
        vector<int> ans;
        if(count1 > majority) ans.push_back(candidate1);

        if(count2 > majority) ans.push_back(candidate2);

        return ans;
    }
};
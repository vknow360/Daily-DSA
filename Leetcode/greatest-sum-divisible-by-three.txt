class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> one;
        vector<int> two;
        for (int i : nums) {
            sum += i;

            if (i % 3 == 1)
                one.push_back(i);
            else if (i % 3 == 2)
                two.push_back(i);
        }

        sort(one.begin(), one.end());
        sort(two.begin(), two.end());

        if (sum % 3 == 1) {
            int mnOne = one.size() > 0 ? one[0] : INT_MAX;
            int mnTwo = two.size() > 1 ? two[0] + two[1] : INT_MAX;
            sum -= min(mnOne, mnTwo);
        } else if (sum % 3 == 2) {
            int mnTwo = two.size() > 0 ? two[0] : INT_MAX;
            int mnOne = one.size() > 1 ? one[0] + one[1] : INT_MAX;
            sum -= min(mnOne, mnTwo);
        }
        return sum;
    }
};
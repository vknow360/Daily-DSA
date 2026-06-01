class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());
        int ans = 0;
        int i = n-1, count = 0;
        while(i >= 0) {
            if(count < 2) {
                ans += cost[i];
                count++;
            }else {
                count = 0;
            }
            i--;
        }
        return ans;
    }
};

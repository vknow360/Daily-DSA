class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = colors.size();
        int total = neededTime[0];
        int mxE = neededTime[0];
        for (int i = 1; i < n; i++) {
            char color = colors[i];
            if (colors[i] == colors[i - 1]) {
                total += neededTime[i];
                mxE = max(mxE, neededTime[i]);
                continue;
            }
            if (mxE != INT_MIN) {
                ans += total - mxE;
                total = neededTime[i];
                mxE = neededTime[i];
            }
        }
        if (mxE != INT_MIN) {
            ans += total - mxE;
        }
        return ans;
    }
};
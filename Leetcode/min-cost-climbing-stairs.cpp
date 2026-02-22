class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int a = 0; // n
        int b = 0; // n+1
        int c;
        
        for(int i = n-1; i >= 0; i--) { // backwards transition
            c = cost[i] + min(a, b);
            b = a;
            a = c;
        }

        return min(a, b); // start from 0th or 1st stair
    }
};

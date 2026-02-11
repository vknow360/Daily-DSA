class Solution {
  public:
    int findCost(vector<int>& heights, vector<int>& cost, int H) {
        int ans = 0;
        for(int i = 0; i < heights.size(); i++) {
            int diff = abs(H - heights[i]);
            ans += diff*cost[i];
        }
        return ans;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int n = heights.size();
        int total = 0;
        vector<pair<int,int>> vp;
        for(int i = 0; i < n; i++) {
            vp.push_back({heights[i], cost[i]});
            total += cost[i];
        }
        
        sort(vp.begin(), vp.end());
        int H = 0;
        int cumCost = 0;
        for(auto& p : vp) {
            cumCost += p.second;
            if(2*cumCost >= total) {
                H = p.first;
                break;
            }
        }

        int ans = findCost(heights, cost, H);
        
        return ans;
    }
};

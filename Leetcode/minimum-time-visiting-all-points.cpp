class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();

        int ans = 0;
        for(int i = 1; i < n; i++) {
            auto p1 = points[i-1];
            auto p2 = points[i];
            
            int dx = abs(p1[0] - p2[0]);
            int dy = abs(p1[1] - p2[1]);

            ans += max(dx, dy);
        }
        return ans;
    }
};

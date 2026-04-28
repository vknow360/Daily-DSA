class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> v;
        for(auto& vec : grid) {
            for(int i : vec) v.push_back(i);
        }
        sort(v.begin(), v.end());
        int med = v[v.size()/2];

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int d = abs(grid[i][j] - med);
                if(d % x != 0) return -1;
                ans += (d/x);
            }
        }
        return ans;
    }
};

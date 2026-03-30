class Solution {
  public:
    
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size();
        
        vector<vector<int>> gp;
        for(int i = 0; i < n; i++) {
            auto& p1 = houses[i];
            for(int j = i+1; j < n; j++) {
                auto& p2 = houses[j];
                int dist = abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
                gp.push_back({dist, i, j});
            }
        }
        sort(gp.begin(), gp.end());
        
        vector<int> rank(n, 0), parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        
        auto find = [&](int x){
            int tmp = x;
            while(parent[tmp] != tmp) {
                tmp = parent[tmp];
            }
            return parent[x] = parent[tmp];
        };
        
        auto Union = [&](int x, int y) {
            int pX = find(x), pY = find(y);
            int rankX = rank[pX], rankY = rank[pY];
            
            if(rankX < rankY) {
                parent[pX] = pY;
                rank[pY]++;
            }else if(rankX > rankY) {
                parent[pY] = pX;
                rank[pX]++;
            }else {
                parent[pX] = pY;
            }
        };
        
        int ans = 0;
        for(int i = 0; i < gp.size(); i++) {
            auto& vec = gp[i];
            int dist = vec[0], x = vec[1], y = vec[2];
            
            if(find(x) != find(y)) {
                Union(x, y);
                ans += dist;
            }
        }
        return ans;
    }
};

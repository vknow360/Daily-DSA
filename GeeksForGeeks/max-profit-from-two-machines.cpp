class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size();
        
        vector<tuple<int, int, int>> vp;
        for(int i = 0; i < n; i++) {
            int diff = a[i] - b[i];
            vp.push_back({abs(diff), i, (diff >= 0 ? 1 : 2)});
        }
        
        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());
        
        int profit = 0;

        for(auto& [prof, task, mach] : vp) {

            if(mach == 1) {
                if(x > 0) {
                    profit += a[task];
                    x--;
                } else if(y > 0) {
                    profit += b[task];
                    y--;
                }
            }
            
            if(mach == 2) {
                if(y > 0) {
                    profit += b[task];
                    y--;
                } else if(x > 0) {
                    profit += a[task];
                    x--;
                }
            }
            
        }
        
        return profit;
    }
};

class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
        int n = s.size();
        vector<int> avl(n+1, 0);
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                avl[max(0, i-x)] += 1;
                avl[min(n, i+x+1)] -= 1;
            }
        }
        for(int i = 1; i < n; i++) avl[i] += avl[i-1];
        
        for(int i = 0; i < n; i++) {
            if(avl[i] == 0) return false;
        }
        return true;
    }
};

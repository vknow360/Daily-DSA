class Solution {
  public:
    bool canAttend(
        vector<vector<int>> &arr) {
        // Code Here
        int n = arr.size();
        
        int mx = 0;
        for(auto& vec : arr) {
            mx = max(mx, vec[1]);
        }
        
        vector<int> line(mx+1, 0);
        for(auto& vec : arr) {
            int st = vec[0];
            int end = vec[1];
            line[st]++;
            line[end]--;
        }
        for(int i = 1; i < line.size();
        i++) {
            line[i] += line[i-1];
        }
        
        for(int vl : line) {
            if(vl >1) return false;
        }
        return true;
    }
};

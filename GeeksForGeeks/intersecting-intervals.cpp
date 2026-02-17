class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int mx = 0;
        for(auto& vec : arr) mx = max(mx, vec[1]);
        
        vector<int> line(mx + 2, 0);
        for(auto& vec : arr) {
            int st = vec[0], end = vec[1];
            line[st]++;
            line[end+1]--;
        }
        
        for(int i = 1; i < line.size(); i++) {
            line[i] += line[i-1];
        }
        
        return *max_element(line.begin(), line.end());
    }
};

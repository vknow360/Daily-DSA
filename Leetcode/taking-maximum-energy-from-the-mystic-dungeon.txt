class Solution {
public:
    
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int mx = INT_MIN;
        queue<int> q;
        for(int i = n-1; i >= n-k; i--){
            q.push(energy[i]);
            mx = max(energy[i], mx);
        }
        for(int i = n-1-k; i >= 0; i--){
            int tp = q.front();
            q.pop();
            mx = max(mx, energy[i]+tp);
            q.push(energy[i]+tp);
        }
        
        return mx;
    }
};
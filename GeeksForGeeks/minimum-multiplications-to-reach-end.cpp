class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        vector<bool> vis(1000, false);
        vis[start] = true;
        
        queue<int> q;
        q.push(start);
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            
            while(sz--) {
                int num = q.front(); q.pop();
                if(num == end) return level;
                for(int i : arr) {
                    int mod = (num*i) % 1000;
                    if(!vis[mod]) {
                        q.push(mod);
                        vis[mod] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};

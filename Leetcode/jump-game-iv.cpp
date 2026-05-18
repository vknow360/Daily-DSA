class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                int idx = q.front(); q.pop();
                if(idx == n-1) return level;

                if(idx+1 < n && !vis[idx+1]) {
                    q.push(idx+1);
                    vis[idx+1] = true;
                }
                if(idx-1 >= 0 && !vis[idx-1]) {
                    q.push(idx-1);
                    vis[idx-1] = true;
                }

                for(int j : mp[arr[idx]]) {
                    if(j == idx || vis[j]) continue;
                    q.push(j);
                    vis[j] = true;
                }
                mp[arr[idx]].clear();
            }
            level++;
        }
        return -1;
    }
};

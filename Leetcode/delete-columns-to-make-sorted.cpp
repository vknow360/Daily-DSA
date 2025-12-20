class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        int ans = 0;

        for(int i = 0; i < m; i++) {
            int j = 1;
            while(j < n && strs[j][i] >= strs[j-1][i]) j++;
            if(j < n) ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int count = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                count++;
            }else if(i+1 == n || s[i+1] == '1'){
                ans += count;
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev = 0;
        for(const auto& s : bank){
            int cnt = count(s.begin(), s.end(), '1');
            if(cnt == 0) continue;
            if(prev == 0) prev = cnt;
            else {
                ans += prev*cnt;
                prev = cnt;
            }
        }

        return ans;
    }
};
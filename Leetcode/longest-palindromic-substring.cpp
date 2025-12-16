class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans;
        ans.push_back(s[0]);
        for(int i = 0; i < n; i++) {
            // try odd length substring with s[i] as center
            int left = i-1, right = i+1;
            while(left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            if(right - left - 1 > ans.size()) {
                ans = s.substr(left+1, right - left - 1);
            }

            //try even length substring
            left = i, right = i+1;
            while(left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            if(right - left - 1 > ans.size()) {
                ans = s.substr(left+1, right - left - 1);
            }
        }
        return ans;
    }
};

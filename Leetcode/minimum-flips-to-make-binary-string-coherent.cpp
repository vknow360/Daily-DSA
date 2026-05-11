class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int ones = 0, zeroes = 0;
        for(char c : s) {
            if(c == '1') ones++;
            else zeroes++;
        }

        int c1 = zeroes;
        int c2 = max(0, ones-1);

        int m = 0;
        for(int i = 1; i < n-1; i++) {
            if(s[i] == '1') m++;
        }
        int c3 = m + (s[0] == '0') + (s[n-1] == '0');
        return min({c1, c2, c3});
    }
};

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        int inc = 0;
        for(int i = 0; i < n; i++) {
            // expected char
            char exp = '0' + (i%2);
            if(s[i] != exp) inc++;
        }

        return min(inc, n - inc);
    }
};

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int seenZero = false;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1' && seenZero) return false;
            else if(s[i] == '0') {
                seenZero = true;
            }
        }
        return true;
    }
};

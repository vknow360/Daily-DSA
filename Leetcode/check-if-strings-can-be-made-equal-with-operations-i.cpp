class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<int> s1E(26,0), s1O(26,0), s2E(26,0), s2O(26,0);
        for(int i = 0; i < 4; i++) {
            if(i%2 == 0) {
                s1E[s1[i] - 'a']++;
                s2E[s2[i] - 'a']++;
            }else {
                s1O[s1[i] - 'a']++;
                s2O[s2[i] - 'a']++;
            }
        }
        return s1E == s2E && s1O == s2O;
    }
};

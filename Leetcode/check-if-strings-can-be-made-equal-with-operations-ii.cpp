class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> s1e(26, 0), s1o(26,0), s2e(26, 0), s2o(26, 0);
        for(int i = 0; i < s1.size(); i++) {
            if(i%2 == 0) {
                s1e[s1[i]-'a']++;
                s2e[s2[i]-'a']++;
            }else {
                s1o[s1[i]-'a']++;
                s2o[s2[i]-'a']++;
            }
        }
        return s1e == s2e && s1o == s2o;
    }
};

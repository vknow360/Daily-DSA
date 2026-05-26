class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> low(26, false), up(26, false);
        for(char c : word) {
            if(islower(c)) low[c-'a'] = true;
            else up[c-'A'] = true;
        }
        int count = 0;
        for(int i = 0; i < 26; i++) {
            if(low[i] && up[i]) count++;
        }
        return count;
    }
};

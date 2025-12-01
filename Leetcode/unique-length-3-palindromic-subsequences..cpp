class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        
        vector<int> start(26, -1);
        vector<int> end(26, -1);
        int i = 0;
        for(char c : s){
            if(start[c-'a'] == -1) start[c-'a'] = i;

            end[c-'a'] = i;
            i++;
        }

        int ans = 0;
        
        for(int i = 0; i < 26; i++){
            if(start[i] != -1 && end[i] != -1){
                unordered_set<char> st;
                for(int j = start[i]+1; j < end[i]; j++){
                    st.insert(s[j]);
                }
                ans += st.size();
            }
        }
        return ans;
    }
};
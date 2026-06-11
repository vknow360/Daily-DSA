class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int n = s.size();

        int cl = count(s.begin(), s.end(), ')');
        int op = 0;
        for(int i = 0; i < n; i++) {
            if(op == cl) return i;
            
            if(s[i] == '(') op++;
            else cl--;
        }
        return n;
    }
};

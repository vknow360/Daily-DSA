class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> df(n + 1, 0);

        for (auto& sh : shifts) {
            int v = (sh[2] == 1) ? 1 : -1;
            df[sh[0]] += v;
            df[sh[1] + 1] -= v;
        }

        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur = (cur + df[i]) % 26;
            if (cur < 0) cur += 26;
            s[i] = char('a' + (s[i] - 'a' + cur) % 26);
        }

        return s;
    }
};

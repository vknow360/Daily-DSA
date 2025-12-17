class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int k = 0;
        while (i < n) {
            int j = i;
            while (j < n && chars[j] == chars[i]) {
                j++;
            }
            int cnt = j - i;
            chars[k++] = chars[i];
            if (cnt > 1) {
                string s;
                while (cnt > 0) {
                    int d = cnt % 10;
                    s.push_back(d + '0');
                    cnt /= 10;
                }
                while(!s.empty()) {
                    chars[k++] = s.back();
                    s.pop_back();
                }
            }
            i = j;
        }
        chars.resize(k);
        return chars.size();
    }
};

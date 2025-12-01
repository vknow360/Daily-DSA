class Solution {
public:
    bool hasSameDigits(string str) {
        while (str.size() > 2) {
            string s;
            for (int i = 0; i < str.size() - 1; i++) {
                s.push_back(((str[i] - '0') + (str[i + 1] - '0')) % 10);
            }
            str = s;
        }
        return str[0] == str[1];
    }
};
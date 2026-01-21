class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = s.size() - 1;
        while (j >= 0 && s[j] == ' ') j--;
        int end = j;
        while (j >= 0 && s[j] != ' ') j--;

        return end - j;
    }
};

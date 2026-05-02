class Solution {
public:
    bool isValid(int n) {
        bool foundValid = false;
        while(n>0) {
            int d = n%10;
            if(d == 3 || d == 4 || d == 7) {
                return false;
            }else if(d == 2 || d == 5 || d == 6 || d == 9) foundValid = true;
            n /= 10;
        }
        return foundValid;
    }
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(isValid(i)) cnt++;
        }
        return cnt;
    }
};

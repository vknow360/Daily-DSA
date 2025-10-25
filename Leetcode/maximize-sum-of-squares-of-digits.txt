class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        for(int i = 0; i < num; i++){
            if(sum > 9 * num) return "";
            int d = min(9, sum);
            ans.push_back('0' + d);
            sum -= d;
        }
        return ans;
    }
};
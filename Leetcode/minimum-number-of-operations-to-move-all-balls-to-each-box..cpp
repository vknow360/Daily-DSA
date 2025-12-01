class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> ans(n, 0);
        int ballsToLeft = 0, movesToLeft = 0;

        for (int i = 0; i < n; i++) {
            ans[i] += movesToLeft;
            if (boxes[i] == '1')
                ballsToLeft++;
            movesToLeft += ballsToLeft;
        }
        int ballsToRight = 0, movesToRight = 0;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] += movesToRight;
            if (boxes[i] == '1')
                ballsToRight++;
            movesToRight += ballsToRight;
        }

        return ans;
    }
};
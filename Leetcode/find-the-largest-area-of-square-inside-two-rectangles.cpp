class Solution {
public:
    struct Rectangle {
        long long left;
        long long bottom;
        long long right;
        long long top;
    };

    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {

        int n = bottomLeft.size();
        long long ans = 0;

        auto getIntersectingArea = [&](const Rectangle& A, const Rectangle& B) {
            int left = max(A.left, B.left);
            int right = min(A.right, B.right);
            int bottom = max(A.bottom, B.bottom);
            int top = min(A.top, B.top);

            long long width = right - left;
            long long height = top - bottom;

            if (width <= 0 || height <= 0)
                return 0LL;

            long long side = side = min(width, height);
            return 1LL * side * side;
        };

        for (int i = 0; i < n; i++) {
            Rectangle A{bottomLeft[i][0], bottomLeft[i][1], topRight[i][0],
                        topRight[i][1]};

            for (int j = i + 1; j < n; j++) {
                Rectangle B{bottomLeft[j][0], bottomLeft[j][1], topRight[j][0],
                            topRight[j][1]};

                ans = max(ans, getIntersectingArea(A, B));
            }
        }

        return ans;
    }
};

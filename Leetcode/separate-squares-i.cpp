class Solution {
public:
    bool isPossible(vector<vector<int>>& squares, double& total, double& yC) {
        double bArea = 0;

        for(auto& vec : squares) {
            int x = vec[0], y = vec[1], l = vec[2];
            if(y <= yC) {
                bArea += min(1.0*l, yC-y)*l;
            }
        }

        return bArea*2 >= total;
    }
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();

        double totalArea = 0;
        for(auto& vec : squares) {
            totalArea += 1.0 * vec[2] * vec[2];
        }

        double lo = 0.0;
        double hi = INT_MIN;
        for(auto& vec : squares) {
            hi = max(1.0 * (vec[1]+vec[2]), hi);
        }

        double ans = 0.0;

        while(hi - lo > 0.00001) {
            double y = lo + (hi-lo)/2;
            if(isPossible(squares, totalArea, y)) {
                ans = y;
                hi = y;
            }else lo = y;
        }

        return ans;
    }
};

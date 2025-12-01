class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        auto comp = [&](auto& a, auto& b){
            if(a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        };
        sort(intervals.begin(), intervals.end(), comp);
        
        int ans = 0;
        int p1 = INT_MIN, p2 = INT_MIN;

        for (auto& vec : intervals) {
            int count = 0;
            if(p1 >= vec[0] && p1 <= vec[1]) count++;
            if(p2 >= vec[0] && p1 <= vec[1]) count++;
            if (count == 0) {
                p1 = vec.back();
                p2 = vec.back()-1;
                ans += 2;
            }else if(count == 1){
                p2 = p1;
                p1 = vec.back();
                ans += 1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int bitCount(int n) {
        int cnt = 0;
        while(n > 0) {
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();

        auto cmp = [&](int a, int b) {
            return make_pair(bitCount(a), a) < make_pair(bitCount(b), b);
        };

        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};

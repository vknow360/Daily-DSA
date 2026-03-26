class Solution {
public:
    int minimumSum(int num) {
        vector<int> ds;
        int tmp = num;
        while(tmp > 0) {
            ds.push_back(tmp%10);
            tmp /= 10;
        }
        sort(ds.begin(), ds.end());
        int n1 = ds[0]*10 + ds[2];
        int n2 = ds[1]*10 + ds[3];
        return n1+n2;
    }
};

class Solution {
  public:
    long long smallestpositive(vector<long long> array, int n) {
        // code here
        sort(array.begin(), array.end());
        long long ans = 0;
        for(long long e : array) {
            if(e <= ans+1) ans += e;
            else break;
        }
        return ans+1;
    }
};

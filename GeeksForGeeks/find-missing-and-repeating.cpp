class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        long long expectedSum = (1LL*n*(n+1))/2;
        long long expectedSquareSum = (1LL*n*(n+1)*(2*n + 1))/6;
        
        long long actualSum = 0;
        long long actualSquareSum = 0;
        
        for(long long i : arr){
            actualSum += i;
            actualSquareSum += i*i;
        }
        
        long long x = (actualSum - expectedSum);
        long long y = (actualSquareSum - expectedSquareSum);
        
        int repeating = (x + y/x)/2;
        int missing = repeating - x;
        
        return {repeating, missing};
    }
};
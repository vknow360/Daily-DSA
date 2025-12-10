class Solution {
  public:
    bool isPossible(vector<int> &arr, int k, int pages) {
        int n = arr.size();
        int currPages = 0;
        int students = 1;
        for(int p : arr) {
            if(p > pages) return false;
            if(currPages+p <= pages) {
                currPages += p;
            }else {
                students++;
                currPages = p;
            }
        }
        return students <= k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n) return -1;
        else if(k==n) return *max_element(arr.begin(), arr.end());
        
        int sum = 0;
        for(int p : arr) sum += p;
        
        int lo = *max_element(arr.begin(), arr.end()), hi = sum;
        int ans = hi;
        while(lo <= hi) {
            int pages = lo + (hi-lo)/2;
            if(isPossible(arr,k, pages)) {
                ans = min(ans, pages);
                hi = pages - 1;
            }else {
                lo = pages + 1;
            }
        }
        
        return ans;
    }
};

class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, int tm) {
        int currT = 0;
        int painters = 1;
        for(int t : arr) {
            if(t > tm) return false;
            if(currT + t <= tm) currT += t;
            else {
                painters++;
                currT = t;
            }
        }
        return painters <= k;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int sum = 0;
        for(int i : arr) sum += i;
        
        if(k==1) return sum;
        else if(k==n) return *max_element(arr.begin(), arr.end());
        
        int lo = *max_element(arr.begin(), arr.end()), hi = sum;
        int ans = sum;
        
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(isPossible(arr, k, mid)) {
                ans = mid;
                hi = mid - 1;
            }else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};

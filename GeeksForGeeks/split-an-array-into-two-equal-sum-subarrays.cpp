class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        if(sum % 2 != 0) return false;
        sum /= 2;
        
        int pref = 0;
        for(int i = 0; i < n; i++) {
            pref += arr[i];
            
            if(pref == sum) return true;
        }
        return false;
    }
};

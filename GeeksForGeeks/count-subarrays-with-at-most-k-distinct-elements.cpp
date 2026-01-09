class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int ans = 0;
        
        int left = 0, right = 0;
        unordered_map<int,int> freq;
        while(right<n) {
            freq[arr[right]]++;
            
            while(freq.size() > k) {
                freq[arr[left]]--;
                if(freq[arr[left]] == 0) freq.erase(arr[left]);
                left++;
            }
            
            ans += right-left+1;
            right++;
        }
        return ans;
    }
};

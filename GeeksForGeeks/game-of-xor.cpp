class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        if(arr.size() % 2 == 0) return 0;
        
        int ans = arr[0];
        for(int i = 2; i < arr.size(); i += 2){
            ans ^= arr[i];
        }
        return ans;
    }
};
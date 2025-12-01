// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        vector<int> ans;
        int mxSum = 0;
        int sum = 0;
        vector<int> curr;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] < 0) {
                curr = {};
                sum = 0;
            }else {
                sum += arr[i];
                curr.push_back(arr[i]);
                if(arr[i] == 0 && sum >= mxSum){
                    ans = curr;
                    mxSum = sum;
                    continue;
                }
            }
            
            if(sum > mxSum){
                ans = curr;
                mxSum = sum;
            }
        }
        
        if(ans.empty()) return {-1};
        return ans;
    }
};
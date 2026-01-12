class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        vector<int> ans;
        
        deque<int> dq;
        for(int i = 0; i < k; i++) {
            while(!dq.empty() && arr[i] > arr[dq.back()]) dq.pop_back();
            
            dq.push_back(i);
        }
        
        ans.push_back(arr[dq.front()]);
        
        for(int i = k; i < n; i++) {
            if(i-k >= dq.front()) {
                dq.pop_front();
            }
            
            while(!dq.empty() && arr[i] > arr[dq.back()]) dq.pop_back();
            
            dq.push_back(i);
            ans.push_back(arr[dq.front()]);
        }
        
        return ans;
    }
};

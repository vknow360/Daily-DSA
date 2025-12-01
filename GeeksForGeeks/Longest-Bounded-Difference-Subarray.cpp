class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        deque<int> mx;
        deque<int> mn;
        int l = 0, len = 0, start = 0;
        for(int r = 0; r < n; r++){
            while(!mx.empty() && arr[mx.back()] < arr[r]) {
                mx.pop_back();
            }
            mx.push_back(r);
            
            while(!mn.empty() && arr[mn.back()] > arr[r]) {
                mn.pop_back();
            }
            mn.push_back(r);
            
            while(arr[mx.front()] - arr[mn.front()] > x){
                if(mx.front() == l) mx.pop_front();
                if(mn.front() == l) mn.pop_front();
                l++;
            }
            
            if (r - l + 1 > len) {
                len = r - l + 1;
                start = l;
            }
        }
        return vector<int>(arr.begin()+start, arr.begin()+start+len);
    }
};
class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<>> pq;
        vector<int> v(arr.size());
        
        for(int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
            if(pq.size() < k) v[i] = -1;
            else {
                while(pq.size() > k) pq.pop();
                v[i] = pq.top();
            }
        }
        return v;
    }
};

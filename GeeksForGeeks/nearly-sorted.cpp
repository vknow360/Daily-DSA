class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> v;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < n; i++){
            q.push(arr[i]);
            if(q.size() > k){
                v.push_back(q.top());
                q.pop();
            }
        }
        
        while(!q.empty()){
            v.push_back(q.top());
            q.pop();
        }
        int i = 0;
        for(int x : v) arr[i++] = x;
    }
};
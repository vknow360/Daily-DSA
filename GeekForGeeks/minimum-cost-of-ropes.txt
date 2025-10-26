class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i : arr) pq.push(i);
        
        int ops = 0;
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            
            ops += a+b;
            pq.push(a+b);
        }
        return ops;
    }
};
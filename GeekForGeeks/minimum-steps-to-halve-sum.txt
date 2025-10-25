class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here

        double sum = 0.0;
        for(int i : arr) sum += i;
        
        double tg = sum/2.0;
        
        priority_queue<double> pq;
        for(int i : arr){
            pq.push(1.0 * i);
        }
        
        int ops = 0;
        
        while(sum > tg){
            double tp = pq.top();
            pq.pop();
            double hf = tp/2.0;
            sum -= hf;
            pq.push(hf);
            ops++;
        }
        
        return ops;
    }
};
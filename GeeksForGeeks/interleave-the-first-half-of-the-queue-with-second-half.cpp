class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n = q.size();
        queue<int> fs;
        for(int i = 0; i < n/2; i++) {
            fs.push(q.front());
            q.pop();
        }
        
        int i = 0;
        while(i < n && !fs.empty()) {
            if(i%2==0) {
                q.push(fs.front());
                fs.pop();
            }else {
                q.push(q.front());
                q.pop();
            }
            i++;
        }
        
        while(i < n) {
            q.push(q.front());
            q.pop();
            i++;
        }   
    }
};

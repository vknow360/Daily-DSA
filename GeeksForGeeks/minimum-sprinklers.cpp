class Solution {
  public:
    typedef pair<int,int> P;
    int minMen(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<P> intervals;
        for(int i = 0; i < n; i++) {
            if(arr[i] == -1) continue;
            int st = max(0, i- arr[i]);
            int end = min(n-1, i+arr[i]);
            intervals.push_back({st, end});
        }
        
        sort(intervals.begin(), intervals.end());
        
        int currentEnd = -1;
        int workers = 0;
        int i = 0;
        
        while(currentEnd < n-1) {
            int farthestReach = -1;
            while(i < intervals.size() && intervals[i].first <= currentEnd+1) {
                if(intervals[i].second >= currentEnd+1) {
                    farthestReach = max(farthestReach, intervals[i].second);
                }
                
                i++;
            }
            
            if(-1 == farthestReach) return -1;
            
            workers++;
            currentEnd = farthestReach;
        }
        
        return workers;
    }
};

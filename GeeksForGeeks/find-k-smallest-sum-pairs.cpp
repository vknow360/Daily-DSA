class Solution {
    public: vector < vector < int >> kSmallestPair(vector < int > & arr1, vector < int > & arr2, int k) {
        // code here
        
        if(arr1.size() == 0 || arr2.size() == 0 || k == 0) return vector < vector < int >>();

        priority_queue < vector < long long > > pq;
        int n = arr1.size();
        int m = arr2.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long long sum = (arr1[i] + arr2[j]);
                if(pq.size() == k){
                    if(sum < pq.top()[0]){
                        pq.pop();
                        pq.push({sum, arr1[i], arr2[j]});
                    }else break;
                }else{
                    pq.push({sum, arr1[i], arr2[j]});
                }
            }
        }
        
        vector < vector < int >> ans;
        
        while (pq.size() > 0) {
            if(ans.size() >= k) break;
            vector < long long > e = pq.top();
            ans.push_back({
                e[1],
                e[2]
            });
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
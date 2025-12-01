class Solution {
public:
    int n;
    vector<int> memo = vector<int>(50001, -1);
    int getNextIndex(vector<vector<int>>& arr, int i, int curr){
        int lo = i, hi = n-1;
        int result = n;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int endTime = arr[mid][0];
            if(endTime >= curr){
                result = mid;
                hi = mid-1;
            }else {
                lo = mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>& arr, int i){
        if(i >= n){
            return 0;
        }
        if(memo[i] != -1) return memo[i];

        int taken = arr[i][2] + solve(arr, getNextIndex(arr, i+1, arr[i][1]));
        int notTaken = solve(arr, i+1);
        return memo[i] = max(taken, notTaken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();

        vector<vector<int>> arr(n, vector<int>(3, 0));
        for(int i = 0; i < n; i++){
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        auto comp = [&](auto& vec1, auto& vec2) -> bool {
            return vec1[0] < vec2[0];
        };
        sort(arr.begin(), arr.end(), comp);

        return solve(arr, 0);
    }
};
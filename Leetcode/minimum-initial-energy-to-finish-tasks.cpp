class Solution {
public:
    int isPossible(vector<vector<int>>& tasks, int energy) {
        for(auto& task : tasks) {
            int a = task[0], m = task[1];
            if(energy < m) return false;
            energy -= a;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [&](auto& a, auto& b) {
            return a[1]-a[0] > b[1]-b[0];
        });

        int lo = tasks[0][1], hi = accumulate(tasks.begin(), tasks.end(), 0, [&](int acc, auto& vec) {
            return acc + vec[1];
        });
        int ans = hi;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(isPossible(tasks, mid)) {
                ans = mid;
                hi = mid - 1;
            }else lo = mid + 1;
        }
        return ans;
    }
};

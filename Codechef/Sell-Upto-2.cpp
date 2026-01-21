#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> dp;

long long solve(vector<int>& a, int n, int day, int watches) {
    if(day == n) return 0;
    
    if(dp[day][watches] != -1) return dp[day][watches];
    
    int curr = watches+1;
    
    long long mx = 1LL * solve(a, n, day+1, curr);
    
    if(curr >= 1) {
        mx = max(mx, 1LL* a[day] + solve(a, n, day+1, curr-1));
    }
    
    if(curr >= 2) {
        mx = max(mx, 2LL*a[day] + solve(a, n, day+1, curr-2));
    }
    
    return dp[day][watches] = mx;
}

int main() {
    // your code goes here
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        dp = vector<vector<long long>>(101, vector<long long>(101, -1LL));

        vector <int> a(n);
        for (auto & x: a) cin >> x;

        
        
        cout << solve(a, n, 0, 0) << endl;
    }
}

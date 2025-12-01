#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector < int > v(n);
        for (auto & x: v) cin >> x;

        vector < int > count = {
            0,
            0,
            0
        };
        for (int i: v) count[i - 1]++;

        int ans = max(0, count[1] - 1) + ((count[0] > 0 && count[2] > 0) ? min(count[0], count[2]) : 0);
        cout << ans << endl;
    }
}
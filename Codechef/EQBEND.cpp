#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(auto& x : v) cin >> x;
        
        if(v[0] == v.back()) {
            cout << 0 << endl;
            continue;
        }
        
        vector<int> first(101, -1), last(101, -1);
        for(int i = 0; i < n; i++) {
            last[v[i]] = i;
            if(first[v[i]] == -1) first[v[i]] = i;
        }
        
        int ans = INT_MAX;
        for(int i = 1; i <= 100; i++) {
            if(first[i] < last[i]) {
                ans = min(ans, first[i] + n - 1 - last[i]);
            }
        }
        
        cout << (ans == INT_MAX ? -1 : ans) << endl;
    }
}

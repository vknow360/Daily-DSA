#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n), b(n);
        for(auto& x : a) cin >> x;
        for(auto& x : b) cin >> x;
        
        int total = 0;
        for(int i : a) total += i;
        
        int mn = INT_MAX;
        for(int i = 0; i < n; i++) {
            mn = min(a[i]-b[i], mn);
        }
        
        cout << (total-mn) << endl;
    }
}

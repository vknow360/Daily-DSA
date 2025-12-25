#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    
	    vector<int> a(n), c(n);
	    for(auto& x : a) cin >> x;
	    for(auto& x : c) cin >> x;
	    
	    int mn = c[0];
	    for(int i = 1; i < n; i++) {
	        if(c[i] >= mn) {
	            c[i] = mn;
	        }else {
	            mn = c[i];
	        }
	    }
	    
	    int ans = 0;
	    
	    for(int i = 0; i < n; i++) {
	        ans += a[i]*c[i];
	    }
	    
	    cout << ans << endl;
	}
}
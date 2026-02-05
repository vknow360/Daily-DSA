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
        
        int ans = 0;
        int cnt = v[0] > 0 ? 1 : 0;
        for(int i = 1; i < n; i++) {
            if(v[i] > 0) {
                cnt++;
            }else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        ans = max(ans, cnt);
        cout << ans << endl;
        
    }
}

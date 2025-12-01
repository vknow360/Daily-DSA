#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    
    cout << (v[0]==1 ? "YES" : "NO") << endl;
}

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--) solve();
}

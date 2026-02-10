#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, w;
    cin >> n >> w;
    
    int blocks = (n/w) * (w-1);
    blocks += n%w;
    
    cout << blocks << endl;
}


int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--) solve();
}

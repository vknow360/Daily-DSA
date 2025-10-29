#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    bool containsOne = false;

    vector<long long> arr(n);
    for(auto& x : arr) {
        cin >> x;
        if(!containsOne && x == 1){
            containsOne = true;
        }
    }

    long long gd = arr[0];
    
    for (int i = 1; i < n; i++) {
        gd = gcd(gd, arr[i]);
    }

    if (containsOne) {
        cout << 2 << endl;
    } else {
        for (long long i = 2; ; i++) {
            if (gcd(i, gd) == 1) {
                cout << i << endl;
                break;
            }
        }
    }
}

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) solve();

}
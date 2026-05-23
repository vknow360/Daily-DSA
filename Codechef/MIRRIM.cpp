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
        
        bool poss = true;
        int i = (n/2)-1, j = n/2;
        int x = v[i], y = v[j];
        while(i>=0 && j<n) {
            if(x - v[i] != v[j] - y) {
                poss = false;
                break;
            }
            i--;
            j++;
        }
        cout << (poss ? "Yes" : "No") << endl;
    }
}

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
        
        unordered_set<int> s;
        for(int e : v) {
            s.insert(abs(e));
        }
        
        if(s.size() == 1) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
}

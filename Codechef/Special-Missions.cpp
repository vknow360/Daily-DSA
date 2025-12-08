#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--) {
        int n,c;
        cin >> n >> c;
        vector<int> prof(n);
        for(auto& x : prof) cin >> x;
        
        string s;
        cin >> s;
        
        int special = 0;
        int normal = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') normal += prof[i];
            else special += prof[i];
        }
        
        if(normal >= c && special > c) {
            cout << (normal+special-c) << endl;
        }else {
            cout << (normal) << endl;
        }
    }
}

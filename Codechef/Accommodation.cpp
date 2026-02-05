#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    
    while(t--) {
        int b,g,x,y,n;
        cin >> b >> g >> x >> y >> n;
        
        if(x+y > n) {
            cout << -1 << endl;
        }else {
            int rb = floor(1.0*b / x);
            int rg = floor(1.0*g / y);
            int mn = min(rb, rg);
            int req = ceil(((1.0*b)+g)/n);
            
            if(req > mn) {
                cout << -1 << endl;
            }else {
                cout << req << endl;
            }
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int x,y,z;
        cin >> x >> y >> z;
        
        int l = x-y;
        int r = x+y;
        
        int left = max(x-z, l);
        int right = min(x+z, r);
        if(left > right) {
            cout << 0 << endl;
        }else {
            int res = right - left + 1;
            if(x >= left && x <= right){
                cout << res-1 << endl;
            }else {
                cout << res << endl;
            }
        }
    }
}

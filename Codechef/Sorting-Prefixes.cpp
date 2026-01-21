#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for(auto& x : a) cin >> x;
        
        int idx = -1;
        for(int i = n-1; i >= 0; i--) {
           if(a[i] != i+1) {
               idx = i;
               break;
           } 
        } 
        
        if(idx != -1) {
            cout << *min_element(a.begin()+idx, a.end()) << endl; 
        }else {
            cout << 0 << endl;
        }
        
    }
}

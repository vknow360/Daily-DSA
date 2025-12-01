#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    
    while(t--){
        int n,k;
        cin >> n >> k;
        
        if(k >= ((n+1)/2)){
            cout << (n-k) << endl;
        }else if(k==1){
            cout << 1 << endl;
        }else if(n==k){
            cout << 0 << endl;
        }else{
            cout << (k-2 + (n - (n-2 + 1)) + 1) << endl;
        }
    }
}

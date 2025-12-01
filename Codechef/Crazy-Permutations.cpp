#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vector<int> A(n), B(n);
        
        for(auto& x : A) cin >> x;
        
        for(auto& x : B) cin >> x;
        
        if(A == B){
            cout << "YES" << endl;
        } else {
            bool poss = true;
            
            for(int i = 0; i < n-1; i++){
                if((A[i] < A[i+1] && B[i] > B[i+1])
                ||
                (A[i] > A[i+1] && B[i] < B[i+1])) {
                    poss = false;
                    break;
                }
            }
            
            if(poss) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}

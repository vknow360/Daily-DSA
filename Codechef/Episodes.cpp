#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        
        int total = n*k;
        
        int hrs = total/60;
        int mins = total%60;
        
        cout << hrs << " " << mins << endl;
    }
}

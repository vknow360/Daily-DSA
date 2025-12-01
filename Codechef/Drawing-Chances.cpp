#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    string s;
	    cin >> s;
	    
	    int alice = 0, bob = 0;
	    
	    for(int i = 0; i < m; i++){
	        if(s[i]=='0') bob++;
	        else alice++;
	    }
	    
	    int rem = n-m;
	    int diff = abs(alice-bob);
	    bool possible = false;
	    if(diff <= rem && (rem-diff) % 2 == 0){
	        possible = true;
	    }
	    cout << ((possible) ? "Yes" : "No") << endl;
	}

}

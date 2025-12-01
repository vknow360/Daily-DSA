#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    if(n==2){
	        cout << "0 0" << endl;
	    }else if(n==3){
	        cout << "1 1" << endl;
	    }
	    else{
	        
	        int mx = 0;
	        for(int i = 1; i < (n-1); i++){
	            mx += i;
	        }
	        
	        cout << (n-2) << " " << mx << endl;
	    }
	}

}

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    
	    vector<int> v(n);
	    
	    int z = 0;
	    int count = 0;
	    
	    int last = -1;
	    
	    while(true){
	        if(last + 2 > n-1) {
	            break;
	        }
	        v[last+2]= 1;
	        
	        last += 2;
	        
	        int lcount = 0;
	        for(int i = 1; i < n; i++){
	            if(v[i] == 0 && v[i-1] == 0) lcount++;
	        }
	        z += lcount;
	        count = lcount;
	    }
	    
	    cout << z << endl;
	}

}

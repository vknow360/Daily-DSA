#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n,x;
	    cin >> n >> x;
	    
	    vector<int> v(n);
	    for(auto& x : v) cin >> x;
	    
	    vector<int> count = {0, 0, 0};
	    for(int i : v){
	        if(i < x) count[0]++;
	        else if(i==x) count[1]++;
	        else count[2]++;
	    }
	    
	    if(count[0] == 0 || count[2] == 0){
	        cout << "YES" << endl;
	    }else if(count[0] > 0 && count[2] > 0 && count[1] != 0){
	        cout << "YES" << endl;
	    }else {
	        cout << "NO" << endl;
	    }
	}

}

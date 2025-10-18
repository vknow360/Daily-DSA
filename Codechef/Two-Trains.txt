#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> d(n-1);
	    for(auto& x : d) cin >> x;
	    
	    sort(d.begin(), d.end());
	    int total = 0;
	    for(int i : d){
	        total += i;
	    }
	    cout << total + d[n-2] << endl;
	}

}

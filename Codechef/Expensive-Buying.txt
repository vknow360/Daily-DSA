#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    vector<int> cost(n);
	    for( auto &x : cost) cin >> x;
	    sort(cost.begin(), cost.end());
	    int sum = 0;
	    for(int i = n-k; i < n; i++){
	        sum += cost[i];
	    }
	    cout << sum << endl;
	}

}

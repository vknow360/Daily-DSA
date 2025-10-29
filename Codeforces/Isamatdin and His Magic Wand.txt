#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    
    vector<int> arr;
    int even = 0;
    
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a%2 == 0) even++;
        
        arr.push_back(a);
    }
    
    if(even > 0 && even < n){
        sort(arr.begin(), arr.end());
    }
    
    for(int i : arr) cout << i << " ";
    cout << endl;
    
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) solve();

}

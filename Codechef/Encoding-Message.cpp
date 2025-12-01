#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    string s;
	    cin >> s;
	    
	    int len = n%2==0 ? n : n-1;
	    for(int i = 0; i < len-1; i+=2){
	        swap(s[i], s[i+1]);
	    }
	    for(int i = 0; i < n; i++){
	        cout << (char)((('z' - s[i]) % 26) + 'a');
	    }
	    
	    cout << endl;
	}

}

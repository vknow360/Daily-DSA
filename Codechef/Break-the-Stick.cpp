#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n,x;
	    cin >> n >> x;
	    if(x%2==0 && n%2 !=0){
	        cout << "NO" << endl;
	    }else if(x%2==0 && n%2 ==0){
	        cout << "YES" << endl;
	    }else {
	        cout << "YES" << endl;
	    }
	}

}

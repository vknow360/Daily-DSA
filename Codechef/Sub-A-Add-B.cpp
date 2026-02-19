#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--) {
        int n,a, b;
        cin >> n >> a >> b;
        int diff = a-b;
        while(n >= a) {
            n -= diff;
        }
        
        cout << n << endl;
    }
}

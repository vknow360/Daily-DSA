#include <bits/stdc++.h>

using namespace std;

int main() {
    // your code goes here

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (x == 0) {
            cout << (2 * y) / 3 << endl;
        } else if (y == 0) {
            cout << (1 * x) / 3 << endl;
        }else {
            int sum = 0;
            int count = min(y, (x+y)/ 3);
            sum += count;
            sum += (x+y)/3;
            cout << sum << endl;
        }
    }
}
#include <bits/stdc++.h>

using namespace std;


int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        vector <int> v(11);
        for(auto& x : v) cin >> x;
        
        int k;
        cin >> k;
        
        map<int,int> mp;
        int bl = 2048;
        for(int mask = 0; mask < bl; mask++){
            if(__builtin_popcount(mask) == k){
                int sum = 0;
                for(int i = 0; i < 11; i++){
                    if((mask & (1 << i)) > 0){
                        sum += v[i];
                    }
                }
                mp[sum]++;
            }
        }
        
        auto maxElement = mp.rbegin();
        cout << maxElement->second << endl;
    }
    return 0;
}
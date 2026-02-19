#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> v(n);
        for(auto& x : v) cin >> x;
        
        unordered_map<int, int> freq;
        for(int i : v) {
            freq[i]++;
        }
        
        set<pair<int, int>> vp;
        for(auto& [k, vl] : freq) {
            if(k == v[0]) continue;
            vp.insert({vl, k});
        }
        int distinct = vp.size() + 1;
        for(auto it = vp.begin(); it != vp.end(); it = next(it)) {
            auto p = *it;
            if(p.first <= k) {
                distinct--;
                k -= p.first;
            }else break;
        }
        
        cout << max(1, distinct) << endl;
    }
}   

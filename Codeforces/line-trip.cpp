#include <bits/stdc++.h>
using namespace std;


void solve(){
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        
        vector<int> v;
        v.push_back(0);
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            v.push_back(a);
        }
        v.push_back(x);
        
        n = v.size();
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(i == n-1){
                ans = max(2*(v[i]-v[i-1]), ans);
            }else{
                ans = max((v[i]-v[i-1]), ans);   
            }
        }
        cout << ans << endl;
    }
}

int main() {
    solve();

    return 0;
}
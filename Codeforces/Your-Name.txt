#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    string t;
    cin >> t;
    
    vector<int> freq(26, 0);
    for(int i = 0; i < n; i++){
        freq[s[i]-'a']++;
        freq[t[i]-'a']--;
    }
    
    bool poss = true;
    for(int i : freq) {
        if(i){
            poss = false;
            break;
        }
    }
    cout << ((poss) ? "YES" : "NO") << endl;
    
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) solve();

}

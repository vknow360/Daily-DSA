#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int cop = 0;
    int count = 0;
    for(int i = 0; i < n;i++){
        if(s[i] == '.' && i + 1 < n && s[i + 1] == '.' && i + 2 < n && s[i + 2] == '.'){
            cop = 2;
            break;
        }
        if(s[i] == '.') count++;
    }
    if(cop != 2) cop = count;
    cout << cop << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}
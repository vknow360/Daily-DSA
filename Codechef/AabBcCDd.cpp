#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        vector<int> freq(26, 0);
        for(char c : s) {
            freq[tolower(c) - 'a']++;
        }
        sort(freq.begin(), freq.end());
        cout << freq.back()+freq[24] << endl;
    }
}

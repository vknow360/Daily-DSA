#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<vector<int>> dp(26, vector<int>());
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            dp[c - 'a'].push_back(i);
        }

        int totalE = (n + 1) / 2;
        int totalO = n / 2;

        bool canRearrange = true;

        for (int i = 0; i < 26; i++)
        {
            int freq = dp[i].size();

            if (freq > 2)
            {
                canRearrange = false;
                break;
            }
        }

        if (canRearrange)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
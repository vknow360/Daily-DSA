#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;

    unordered_set<int> st(arr.begin(), arr.end());
    arr = vector<int>(st.begin(), st.end());
    sort(arr.begin(), arr.end());

    int mx = 1;
    int cnt = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - arr[i - 1] == 1)
            cnt++;
        else
        {
            mx = max(mx, cnt);
            cnt = 1;
        }
    }
    mx = max(mx, cnt);

    cout << mx << endl;
}

int main()
{
    // your code goes here
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
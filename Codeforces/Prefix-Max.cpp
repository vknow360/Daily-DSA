#include <bits/stdc++.h>

using namespace std;

long long getVal(vector<int> &arr)
{
    long long ans = arr[0];
    int m = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        m = max(arr[i], m);
        ans += m;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;

    long long ans = getVal(arr);
    for (int i = 1; i < n; i++)
    {
        swap(arr[0], arr[i]);
        ans = max(ans, getVal(arr));
        swap(arr[0], arr[i]);
    }
    cout << ans << endl;
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
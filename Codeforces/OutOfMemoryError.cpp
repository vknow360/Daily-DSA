#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    long long h;
    cin >> n >> m >> h;

    vector<long long> arr(n), cur(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cur[i] = arr[i];
    }

    vector<int> chng;
    vector<bool> mod(n, false);

    while (m--)
    {
        int b;
        long long c;
        cin >> b >> c;
        b--;

        cur[b] += c;

        if (cur[b] > h)
        {
            for (int idx : chng)
            {
                cur[idx] = arr[idx];
                mod[idx] = false;
            }
            chng.clear();

            cur[b] = arr[b];
            mod[b] = false;
        }
        else
        {
            if (!mod[b])
            {
                mod[b] = true;
                chng.push_back(b);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << cur[i] << " ";
    }
    cout << endl;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

bool hasOdd(int n)
{
    while (n > 0)
    {
        int d = n % 10;
        n /= 10;

        if (d % 2 != 0)
        {
            return true;
        }
    }
    return false;
}

int findLargest(int n)
{
    int mx = 0;
    while (n > 0)
    {
        int d = n % 10;
        n /= 10;

        mx = max(mx, d);
    }
    return mx;
}

int main()
{
    // your code goes here

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (n % 2 != 0)
        {
            cout << 0 << endl;
            continue;
        }

        if (n < 10)
        {
            cout << -1 << endl;
        }
        else
        {
            int count = 0;
            while (n > 0 && !hasOdd(n))
            {
                n -= findLargest(n);
                count++;
            }

            if (n == 0)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << (count + 1) << endl;
            }
        }
    }
}
class Solution
{
public:
    int maxCapacity(vector<int> &costs, vector<int> &capacity, int budget)
    {
        int n = costs.size();
        int ans = 0;

        vector<pair<int, int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp.push_back({costs[i], capacity[i]});
        }

        sort(mp.begin(), mp.end());

        vector<int> pref(n, 0);
        pref[0] = mp[0].second;
        for (int i = 1; i < n; i++)
        {
            pref[i] = max(pref[i - 1], mp[i].second);
        }

        for (int i = 0; i < n; i++)
        {
            if (mp[i].first >= budget)
                continue;

            ans = max(ans, mp[i].second);

            int lo = 0;
            int hi = i - 1;
            int idx = -1;
            int rem = budget - mp[i].first - 1;

            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (mp[mid].first <= rem)
                {
                    idx = mid;
                    lo = mid + 1;
                }
                else
                    hi = mid - 1;
            }

            if (idx != -1)
            {
                ans = max(ans, mp[i].second + pref[idx]);
            }
        }

        return ans;
    }
};
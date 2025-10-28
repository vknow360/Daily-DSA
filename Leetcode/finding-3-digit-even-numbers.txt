class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int i : digits)
            freq[i]++;

        unordered_set<int> s(digits.begin(), digits.end());

        vector<int> ans;
        for (int i : s) {
            if (i == 0)
                continue;
            for (int j : s) {
                for (int k : s) {
                    if (k % 2 == 1)
                        continue;
                        
                    if ((i == j && freq[i] < 2) || (i == k && freq[i] < 2) ||
                        (j == k && freq[j] < 2) ||
                        (i == j && j == k && freq[i] < 3))
                        continue;

                    ans.push_back(100 * i + 10 * j + k);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
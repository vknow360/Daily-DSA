class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        // unordered_set<int> s;

        // for(int i = 1; i <= n; i++) {
        //     s.insert(i*i);
        // }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; i * i + j * j <= n * n; j++) {
                int k = sqrt(i * i + j * j);
                if (k * k == i * i + j * j && k <= n)
                    ans += 2;
            }
        }
        return ans;
    }
};
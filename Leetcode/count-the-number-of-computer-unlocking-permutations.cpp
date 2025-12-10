class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int MOD = 1000000007;

        long long ans = 1;

        for(int i = 1; i < complexity.size(); i++) {
            if(complexity[i] <= complexity[0]) return 0;

            ans = (ans*i)%MOD;
        }
        return ans;
    }
};

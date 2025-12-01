class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if (num == 0)
            return "0";

        string ans = "";
        bool neg = (num < 0) ^ (den < 0);

        long long n = llabs(num);
        long long d = llabs(den);

        if (neg)
            ans += "-";

        long long q = n / d;
        long long r = n % d;
        ans += to_string(q);
        if (r == 0)
            return ans;
        ans += ".";
        unordered_map<long long, int> rmp;
        while (r != 0) {
            if (rmp.find(r) != rmp.end()) {
                ans.insert(rmp[r], "(");
                ans += ")";
                break;
            }
            rmp[r] = ans.size();

            r *= 10;
            q = r / d;
            r %= d;

            ans += to_string(q);
        }

        return ans;
    }
};
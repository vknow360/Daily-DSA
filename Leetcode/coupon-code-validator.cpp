class Solution {
public:
    unordered_set<string> st = {"electronics", "grocery", "pharmacy", "restaurant"};
    bool isValidCode(string& s){
        for(char c : s) {
            if(!isalnum(c) && c!='_') return false;
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = isActive.size();

        vector<pair<string, string>> vp;
        vp.reserve(n);
        for(int i = 0; i < n; i++) {
            if(isActive[i] && st.contains(businessLine[i]) && !code[i].empty() && isValidCode(code[i])) {
                vp.push_back({businessLine[i], code[i]});
            }
        }

        sort(vp.begin(), vp.end());
        vector<string> ans;
        for(auto& p : vp) {
            ans.push_back(p.second);
        }
        return ans;
    }
};

class Solution {
public:
    bool change(string& s, string& t) {
        int d = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) {
                d++;
            }
            if(d > 2) return false;
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        unordered_map<int, vector<string>> mp;
        for(string& s : dictionary) {
            mp[s.size()].push_back(s);
        }

        vector<string> res;
        for(int i = 0; i < n; i++) {
            string& q = queries[i];
            for(string& s : mp[q.size()]) {
                if(change(q, s)) {
                    res.push_back(q);
                    break;
                }
            }
        }
        return res;
    }
};

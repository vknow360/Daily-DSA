//bfs
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> st;
        queue<string> q;
        string ans = s;

        q.push(s);
        st.insert(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            ans = min(ans, cur);

            string add = cur;
            for (int i = 1; i < add.size(); i += 2) {
                add[i] = (add[i] - '0' + a) % 10 + '0';
            }
            if (!st.count(add)) {
                st.insert(add);
                q.push(add);
            }
            string rot = cur.substr(cur.size() - b) + cur.substr(0, cur.size() - b);
            if (!st.count(rot)) {
                st.insert(rot);
                q.push(rot);
            }
        }

        return ans;
    }
};


//dfs
class Solution {
public:
    void dfs(string s, int a, int b, unordered_set<string> &st ,string &sms) {
        if (!sms.size() || s < sms) sms = s;

        int n = s.size();
        string add = s;
        for (int i = 1; i < n; i += 2) {
            int c = add[i] - '0';
            add[i] = '0' + (c + a) % 10;
        }
        if(!st.count(add)){
            st.insert(add);
            dfs(add, a, b, st, sms);
        }
        
        s = s.substr(s.size() - b) + s.substr(0, s.size() - b);
        if(!st.count(s)){
            st.insert(s);
            dfs(s, a, b, st, sms);
        }
    }
    string findLexSmallestString(string s, int a, int b) {
        string ans = "";
        unordered_set<string> st;
        st.insert(s);
        dfs(s, a, b, st, ans);
        return ans;
    }
};
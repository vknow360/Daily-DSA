class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;
        for(char c : s) mp[c]++;

        for(const auto [k, v] : mp){
            pq.push({v, k});
        }

        string ans = "";
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            for(int i = 0; i < p.first; i++){
                ans.push_back(p.second);
            }

        }

        return ans;
    }
};
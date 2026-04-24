class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        unordered_map<char, int> mp;
        for(char c : moves) mp[c]++;

        return mp['_'] + abs(mp['L'] - mp['R']);
    }
};

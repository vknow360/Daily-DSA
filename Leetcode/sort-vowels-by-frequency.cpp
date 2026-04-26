class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        unordered_map<char, int> mp, freq;
        vector<int> vowelIdx;

        for(int i = 0; i < n; i++) {
            char c = s[i];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowelIdx.push_back(i);
                if(mp.find(c) == mp.end()) mp[c] = i;
                freq[c]++;
            }
        }
        vector<char> v;
        for(auto& [k, vo] : mp) v.push_back(k);
        sort(v.begin(), v.end(), [&](char& a, char& b) {
            if(freq[a] == freq[b]) return mp[a] < mp[b];
            return freq[a] > freq[b];
        });
        vector<char> vowels;
        for(char c : v) {
            for(int i = 0; i < freq[c]; i++) vowels.push_back(c);
        }

        int idx = 0;
        for(int x : vowelIdx) {
            s[x] = vowels[idx++];
        }
        return s;
    }
};

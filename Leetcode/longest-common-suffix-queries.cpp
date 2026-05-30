class Solution {
public:
    class TrieNode {
        public:
            int bestIdx = 0, bestLen = INT_MAX;
            int child[26];
            TrieNode() {
                for(auto& t : child) t = -1;
            }
    };
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();

        vector<TrieNode> trie;
        trie.reserve(wordsContainer.size() + 1);
        trie.emplace_back();

        for(int i = 0; i < n; i++) {
            int curr = 0;

            const string& s = wordsContainer[i];
            int len = s.size();
            if(trie[curr].bestLen > len) {
                trie[curr].bestIdx = i;
                trie[curr].bestLen = len;
            }

            for(int j = len-1; j >= 0; j--) {
                int charIdx = s[j] - 'a';
                
                if(trie[curr].child[charIdx] == -1) {
                    trie[curr].child[charIdx] = trie.size();
                    trie.emplace_back();
                }

                curr = trie[curr].child[charIdx];
                
                if(trie[curr].bestLen > len) {
                    trie[curr].bestIdx = i;
                    trie[curr].bestLen = len;
                }
            }
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());

        for(const string& q : wordsQuery) {
            int sz = q.size();
            int curr = 0;
            for(int j = sz-1; j >= 0; j--) {
                int cIdx = q[j] - 'a';
                if(trie[curr].child[cIdx] == -1) break;

                curr = trie[curr].child[cIdx];
            }
            ans.push_back(trie[curr].bestIdx);
        }
        return ans;
    }
};

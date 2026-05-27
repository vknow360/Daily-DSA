class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<int> state(26, 0);
        int count = 0;
        for (char c : word) {
            if ('a' <= c && c <= 'z') {
                int idx = c-'a';
                if(state[idx] == 3) continue;
                else if(state[idx] == 0) state[idx] = 1;
                else if(state[idx] == 2) {
                    state[idx] = 3;
                    count--;
                }
            } else {
                int idx = c-'A';
                if(state[idx] == 3) continue;
                else if(state[idx] == 1) {
                    state[idx] = 2;
                    count++;
                }else if(state[idx] == 0) state[idx] = 3;
            }
        }
        return count;
    }
};

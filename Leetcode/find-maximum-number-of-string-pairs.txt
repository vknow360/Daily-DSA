class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        //unordered_set<string> pairs;
        int count = 0;
        sort(words.begin(), words.end());
        for(int i = 0; i < words.size(); i++){
            for(int j = i+1; j < words.size(); j++){
                if(words[i][0] == words[j][1] && words[i][1] == words[j][0]){
                    //pairs.insert(words[i] + words[j]);
                    count++;
                }
            }
        }
        return count;
    }
};
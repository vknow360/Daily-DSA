class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, counter = 0;

        for(string s : events) {
            if(s == "W") counter++;
            else if(s == "WD") score++;
            else if(s == "NB") score++;
            else score += s[0] - '0';

            if(counter == 10) break;
        }
        return {score, counter};
    }
};

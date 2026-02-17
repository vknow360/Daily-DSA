class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        unordered_set<string> ans;
        string curr;
        for(int i = 0; i < turnedOn; i++) curr.push_back('1');
        for(int i = turnedOn; i < 10; i++) curr.push_back('0');
        reverse(curr.begin(), curr.end());
        do {
            int hr = 0;
            for(int i = 3; i >= 0; i--) {
                int tm = i;
                if(curr[i] == '1') hr += (int)pow(2, tm);
            }
            if(hr < 0 || hr > 11) continue;

            int min = 0;
            for(int i = 9; i >= 4; i--) {
                int tm = i-4;
                if(curr[i] == '1') min += (int)pow(2, tm);
            }
            if(min < 0 || min > 59) continue;
            string cTime = "";
            cTime += to_string(hr);
            cTime += ":";
            if(min < 10) cTime += "0";
            cTime += to_string(min);
            ans.insert(cTime);
        }while(next_permutation(curr.begin(), curr.end()));
        return vector<string>(ans.begin(), ans.end());
    }
};

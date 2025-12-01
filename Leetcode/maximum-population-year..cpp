class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> mp;

        for(vector<int> log : logs){
            mp[log[0]]++;
            mp[log[1]]--;
        }

        int mxPop = 0, year = 0;
        int cnt = 0;
        for(auto& [y, p] : mp){
            cnt += p;
            if(cnt > mxPop){
                mxPop = cnt;
                year = y;
            }
        }
        return year;
    }
};
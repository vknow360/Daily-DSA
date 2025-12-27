class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> rooms(n, 0);

        priority_queue<int, vector<int>, greater<int>> free;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> busy;

        for (int i = 0; i < n; i++) free.push(i);

        long long currTime = 0;
        int i = 0;

        while (i < meetings.size()) {
            long long st = meetings[i][0];
            long long end = meetings[i][1];

            currTime = max(currTime, st);

            while (!busy.empty() && busy.top().first <= currTime) {
                free.push(busy.top().second);
                busy.pop();
            }

            if (!free.empty()) {
                int rm = free.top(); free.pop();
                busy.push({currTime + (end - st), rm});
                rooms[rm]++;
                i++;
            } else {
                currTime = busy.top().first;
            }
        }

        return max_element(rooms.begin(), rooms.end()) - rooms.begin();
    }
};

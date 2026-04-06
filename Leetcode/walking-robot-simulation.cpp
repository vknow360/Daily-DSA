class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();

        unordered_set<int> obs;
        for (auto& vec : obstacles) {
            obs.insert(vec[0] + 60001 * vec[1]);
        }
        int x = 0, y = 0;
        int key = 0;
        int dir = 0;

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        vector<int> dKey = {60001, +1, -60001, -1};

        int ans = 0;
        for (int c : commands) {
            if (c == -2) {
                dir = (dir - 1 + 4) % 4;
            } else if (c == -1) {
                dir = (dir + 1 + 4) % 4;
            } else {
                int steps = c;
                while (steps > 0) {
                    int newX = x + dx[dir];
                    int newY = y + dy[dir];
                    int nxtKey = key + dKey[dir];
                    if (obs.find(nxtKey) == obs.end()) {
                        x = newX;
                        y = newY;
                        key = nxtKey;
                        steps--;
                    } else
                        break;
                }
            }
            ans = max(ans, x * x + y * y);
        }
        return ans;
    }
};

class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        
        auto encode = [](int x, int y, int z) {
            return x * 100 + y * 10 + z;
        };

        int n = points.size();
        unordered_set<int> st;
        vector<array<int,3>> allPts;

        for (auto& vec : points) {
            st.insert(encode(vec[0], vec[1], vec[2]));
            allPts.push_back({vec[0], vec[1], vec[2]});
        }

        int tgt = encode(target[0], target[1], target[2]);
        if (st.count(tgt)) return 0;

        int k = 0;

        while (true) {
            k++;

            vector<array<int,3>> nw;
            int sz = allPts.size();

            for (int i = 0; i < sz; i++) {
                for (int j = i + 1; j < sz; j++) {
                    int mx = (allPts[i][0] + allPts[j][0]) / 2;
                    int my = (allPts[i][1] + allPts[j][1]) / 2;
                    int mz = (allPts[i][2] + allPts[j][2]) / 2;

                    int pt = encode(mx, my, mz);
                    if (st.count(pt) == 0) {
                        st.insert(pt);
                        nw.push_back({mx, my, mz});
                    }
                }
            }

            if (nw.empty()) return -1;

            for (auto& p : nw) allPts.push_back(p);

            if (st.count(tgt)) return k;
        }

        return -1;
    }
};

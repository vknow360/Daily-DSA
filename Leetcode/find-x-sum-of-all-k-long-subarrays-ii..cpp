class Solution {
public:
    bool compare(auto p1, auto p2) {
        if (p1.first != p2.first)
            return p1.first > p2.first;
        return p1.second > p2.second;
    }
    
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        vector<long long> ans;

        int i = 0, j = k - 1;

        unordered_map<int, int> mp;

        for (int l = i; l <= j; l++) {
            mp[nums[l]]++;
        }

        set<pair<int, int>> main;
        set<pair<int, int>> sec;

        long long sum = 0;

        auto balance = [&](void) {
            while (main.size() < x && !sec.empty()) {
                auto it = prev(sec.end());
                auto p = *it;
                sec.erase(p);
                main.insert(p);
                sum += (1LL * p.first * p.second);
            }
        };

        auto update = [&](auto p) {
            if (main.size() < x) {
                if (!sec.empty()) {
                    auto it = prev(sec.end());
                    auto se = *it;
                    if (compare(p, se)) {
                        main.insert(p);
                        sum += (1LL * p.first * p.second);
                    } else {
                        sec.erase(se);
                        main.insert(se);
                        sec.insert(p);
                        sum += (1LL * se.first * se.second);
                    }
                }else if(p.first > 0){
                    main.insert(p);
                    sum += (1LL * p.first * p.second);
                }
                return;
            }

            auto fr = *(main.begin());
            if (compare(fr, p)) {
                if (p.first > 0)
                    sec.insert(p);
            } else {
                sec.insert(fr);
                sum -= (1LL * fr.first * fr.second);
                main.erase(fr);
                main.insert(p);
                sum += (1LL * p.first * p.second);
            }
        };

        for (const auto p : mp) {
            pair<int, int> newP = {p.second, p.first};
            if (main.size() < x) {
                main.insert(newP);
                sum += 1LL * newP.first * newP.second;
            } else {
                update(newP);
            }
        }

        balance();

        while (j < n) {
            if (i > 0) {
                int out = nums[i - 1];
                int in = nums[j];

                pair<int, int> oldOut = {mp[out], out};
                if (main.find(oldOut) != main.end()) {
                    main.erase(oldOut);
                    sum -= (1LL * oldOut.first * oldOut.second);
                } else {
                    sec.erase(oldOut);
                }

                mp[out]--;
                if (mp[out] > 0) {
                    pair<int, int> oldUpdated = {mp[out], out};
                    update(oldUpdated);
                }
                balance();

                pair<int, int> newIn = {mp[in], in};
                if (main.find(newIn) != main.end()) {
                    main.erase(newIn);
                    sum -= (1LL * newIn.first * newIn.second);
                } else {
                    sec.erase(newIn);
                }
                mp[in]++;
                pair<int, int> newUpdated = {mp[in], in};
                update(newUpdated);

                balance();
            }
            ans.push_back(sum);
            i++;
            j++;
        }
        return ans;
    }
};
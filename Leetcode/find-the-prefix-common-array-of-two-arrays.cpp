class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> seen(n+1, 0);
        vector<int> count(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int eA = A[i], eB = B[i];
            seen[eA]++;
            seen[eB]++;
            if(eA == eB) cnt++;
            else {
                cnt += seen[eA] == 2;
                cnt += seen[eB] == 2;
            }
            count[i] = cnt;
        }
        return count;
    }
};

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<int>());
        int sum = 0;
        for(int a : apple) sum += a;

        int i = 0;
        int cnt = 0;
        while(sum > 0) {
            cnt++;
            sum -= capacity[i++];
        } 
        return cnt;
    }
};

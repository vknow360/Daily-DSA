class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int totalYes = 0;
        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y') {
                totalYes++;
            }
        }

        int yes = 0, no = 0;

        int ans = 0;
        int mnPn = INT_MAX;
        // penalty for closing shop at 0th hr
        mnPn = min(totalYes, mnPn);
        for(int i = 1; i < n; i++) {
            if(customers[i-1] == 'Y') yes++;
            else no++;
            int pn = (totalYes-yes) + no;
            if(pn < mnPn) {
                mnPn = pn;
                ans = i;
            }
        }
        // penalty for closing shop at nth hr
        if(no < mnPn) {
            ans = n;
        }

        return ans;
    }
};

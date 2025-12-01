class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        int n = prices.size();
        int cost = prices[0];
        for(int i = 1; i < n; i++){
            if(prices[i] < cost) { // loss hoga, do not sell, instead purchase
                cost = prices[i];
            }else { // calculate profit
                profit = max(profit, prices[i] - cost);
            }
        }

        return profit;
    }
};
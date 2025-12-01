class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if(numExchange > numBottles) return numBottles;
        
        return numBottles + (numBottles-1)/(numExchange-1);
    }
};
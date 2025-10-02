class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int full = numBottles;
        int drank = 0;
        int empty = 0;
        while((full+empty) >= numExchange){
            empty += full;
            drank += full;
            full = 0;
            while(empty >= numExchange){
                full++;
                empty -= numExchange;
                numExchange++;
            }
        }
        drank += full;
        return drank;
    }
};
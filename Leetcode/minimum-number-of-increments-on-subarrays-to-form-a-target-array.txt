class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ops = 0;
        int prev = 0;
        for(int i = 0; i < target.size(); i++){
            int curr = target[i];
            if(min(prev, curr) < 0 && max(prev, curr) > 0){ // sign change
                ops += abs(curr);
            }else if(abs(curr) > abs(prev)){
                ops += (curr-prev);
            }
            prev = curr;
        }
        return ops;
    }
};
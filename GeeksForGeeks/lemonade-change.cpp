class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int five = 0;
        int ten = 0;
        int twenty = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] == 5) five++;
            else if(arr[i] == 10){
                if(five > 0) {
                    ten++;
                    five--;
                }else return false;
            }else {
                twenty++;
                if(ten > 0 && five > 0) {
                    ten--;
                    five--;
                }else if(five > 2) {
                    five -= 3;
                }else return false;
            }
        }
        
        return true;
    }
};

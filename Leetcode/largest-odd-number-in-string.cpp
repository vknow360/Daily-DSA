class Solution {
public:
    string largestOddNumber(string num) {
        int j = -1;
        int i = 0;
        for(char c : num) {
            if((c-'0')%2 != 0){
                j = i;
            }
            i++;
        }
        if(j==-1) return "";
        return num.substr(0, j+1);
    }
};

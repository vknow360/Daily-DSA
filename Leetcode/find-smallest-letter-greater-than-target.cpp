class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back() <= target) return letters[0];

        int lo = 0, hi = letters.size()-1;
        while(lo < hi) {
            int mid = lo + (hi-lo)/2;
            if(letters[mid] > target) hi = mid;
            else lo = mid+1;
        }
        return letters[hi];
    }
};

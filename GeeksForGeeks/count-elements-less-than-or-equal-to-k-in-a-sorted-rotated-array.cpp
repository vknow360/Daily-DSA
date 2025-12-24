class Solution {
    public:
    int pivotIdx(vector<int>& arr) {
        int lo = 0, hi = arr.size()-1;
        
        while(lo < hi) {
            int mid = lo + (hi-lo)/2;
            if(arr[mid] >= arr[hi]) lo = mid+1;
            else hi = mid;
        }
        return lo;
    }
    
    int BS(vector<int>& arr, int lo, int hi, int x) {
        int start = lo;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] <= x)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return lo - start;
    }

    int countLessEqual(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int pivot = pivotIdx(arr);
        int count = 0;
        count += BS(arr, 0, pivot-1, x);
        count += BS(arr, pivot, n-1, x);
        return count;
    }
};

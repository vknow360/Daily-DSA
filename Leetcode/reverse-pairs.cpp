class Solution {
public:
    int merge(vector<int>& arr, int l, int mid, int r) {
        vector<long long> left(arr.begin() + l, arr.begin() + mid + 1);
        vector<long long> right(arr.begin() + mid + 1, arr.begin() + r + 1);

        int count = 0;

        int m = 0;
        for( int i = 0; i < left.size(); i++) {
            while(m < right.size() && left[i] > 2* right[m]) {
                m++;
            }
            count += (m);
        }

        int i = 0, j = 0, k = l;

        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }

        while (i < left.size()) {
            arr[k++] = left[i++];
        }

        while (j < right.size()) {
            arr[k++] = right[j++];
        }

        return count;
    }

    int mergeSort(vector<int>& arr, int lo, int hi) {
        int count = 0;
        if(lo < hi) {
            int mid = lo + (hi-lo)/2;
            count += mergeSort(arr, lo, mid);
            count += mergeSort(arr, mid+1, hi);
            count += merge(arr, lo, mid, hi);
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
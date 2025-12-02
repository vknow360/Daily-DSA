class Solution {
public:
    long long mergeAndCount(vector<int>& arr, int l, int m, int r) {
        vector<int> left(arr.begin() + l, arr.begin() + m + 1);
        vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

        int i = 0, j = 0, k = l;
        long long inversions = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
                inversions += (left.size() - i);  
            }
        }
        
        while (i < left.size()) arr[k++] = left[i++];
        
        while (j < right.size()) arr[k++] = right[j++];

        return inversions;
    }

    long long mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return 0;

        int m = l + (r - l) / 2;
        long long count = 0;

        count += mergeSort(arr, l, m);
        count += mergeSort(arr, m + 1, r);
        count += mergeAndCount(arr, l, m, r);

        return count;
    }

    long long inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};
